#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080

void log_message(const char* source, const char* command, const char* additional_info) {
    time_t rawtime;
    struct tm *info;
    char timestamp[80];

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(timestamp, 80, "%d/%m/%Y %H:%M:%S", info);

    FILE *fp = fopen("race.log", "a");
    fprintf(fp, "[%s] [%s]: [%s] [%s]\n", source, timestamp, command, additional_info);
    fclose(fp);
}

void handle_rpc_call(int new_socket) {
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);

    char command[50];
    char info[50];

    sscanf(buffer, "%s %s", command, info);

    char response[1024] = {0};

    if (strcmp(command, "Gap") == 0) {
        float distance = atof(info);
        if (distance < 3.5) {
            strcpy(response, "Gogogo");
        } else if (distance >= 3.5 && distance < 10) {
            strcpy(response, "Push");
        } else {
            strcpy(response, "Stay out of trouble");
        }
    } else if (strcmp(command, "Fuel") == 0) {
        int fuel = atoi(info);
        if (fuel > 80) {
            strcpy(response, "Push Push Push");
        } else if (fuel >= 50 && fuel <= 80) {
            strcpy(response, "You can go");
        } else {
            strcpy(response, "Conserve Fuel");
        }
    } else if (strcmp(command, "Tire") == 0) {
        int tire_wear = atoi(info);
        if (tire_wear > 80) {
            strcpy(response, "Go Push Go Push");
        } else if (tire_wear >= 50 && tire_wear <= 80) {
            strcpy(response, "Good Tire Wear");
        } else if (tire_wear >= 30 && tire_wear < 50) {
            strcpy(response, "Conserve Your Tire");
        } else {
            strcpy(response, "Box Box Box");
        }
    } else if (strcmp(command, "Tire Change") == 0) {
        if (strcmp(info, "Soft") == 0) {
            strcpy(response, "Mediums Ready");
        } else if (strcmp(info, "Medium") == 0) {
            strcpy(response, "Box for Softs");
        }
    } else {
        strcpy(response, "Invalid command");
    }

    send(new_socket, response, strlen(response), 0);
    log_message("Paddock", command, info);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        handle_rpc_call(new_socket);
    }

    return 0;
}
