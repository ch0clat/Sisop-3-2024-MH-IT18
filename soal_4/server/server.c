#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_LINE_LENGTH 255
#define PORT 8080

void send_message(int sockfd, const char *message) {
    send(sockfd, message, strlen(message), 0);
}

void show(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    char line[MAX_LINE_LENGTH];

    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    while (fgets(line, sizeof(line), list) != NULL) {
        send_message(sockfd, line);
    }

    fclose(list);
}

void add_row(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "a");
    char type [5] = "ADD";
    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    fprintf(list, "%s\n", options);
    change_log(type, options);
    fclose(list);
    send_message(sockfd, "Row added successfully.\n");
}

void search_row(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    char line[MAX_LINE_LENGTH];
    int found = 0;
    int row_number = 0;
    char *token;

    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    char title[MAX_LINE_LENGTH];
    sscanf(options, "%[^\n]", title);

    while (fgets(line, sizeof(line), list) != NULL) {
        row_number++;
        int column_number = 0;
        char *field[MAX_LINE_LENGTH];

        token = strtok(line, ",");
        while (token != NULL && column_number <= 4){
            field[column_number++] = token;
            token = strtok(NULL, ",");
        }

        if (column_number == 2 && strcmp(field[2], title) == 0){
            found = 1;
            send_message(sockfd, line);
        }
        
    }

    fclose(list);

    if (!found) {
        send_message(sockfd, "Row not found.\n");
    }
}

void status_search(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    char line[MAX_LINE_LENGTH];
    int found = 0;

    if (list == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    char title[MAX_LINE_LENGTH];
    sscanf(options, "%[^\n]", title);

    while (fgets(line, sizeof(line), list) != NULL) {
        if (strstr(line, title) != NULL) {
            found = 1;
            send_message(sockfd, line);
        }
    }

    fclose(list);

    if (!found) {
        send_message(sockfd, "Row not found.\n");
    }
}

void delete_row(char *options, int sockfd) {
    FILE *list = fopen("myanimelist.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    char line[MAX_LINE_LENGTH];
    char type[5] = "DEL";

    if (list == NULL || temp == NULL) {
        perror("Error opening file");
        send_message(sockfd, "Error opening file\n");
        return;
    }

    int found = 0;
    while (fgets(line, sizeof(line), list) != NULL) {
        if (strstr(line, options) != NULL) {
            found = 1;
            continue;
        }
        fprintf(temp, "%s", line);
    }

    fclose(list);
    fclose(temp);

    if (found) {
        remove("myanimelist.csv");
        rename("temp.csv", "myanimelist.csv");
        change_log(type, options);
        send_message(sockfd, "Row deleted successfully.\n");
    } else {
        remove("temp.csv");
        send_message(sockfd, "Row not found.\n");
    }
}

void change_log(char *type, char *changes){
    FILE *log = fopen("change.log", "a");
    time_t currentDate;
    struct tm *localTime;

    time(&currentDate);
    localTime = localtime(&currentDate);

    char dateFormat[9];
    strftime(dateFormat, sizeof(dateFormat), "%d,%m,%y", localtime);
    

    fprinf(log, "[%s] [%s] [%s]", dateFormat, type, changes);

    fclose(log);
}

void handle_command(char *command, int sockfd) {
    char input[MAX_LINE_LENGTH];
    strcpy(input, command);
    int i;

    char options[MAX_LINE_LENGTH];
    char cmd[MAX_LINE_LENGTH];
    sscanf(input, "%s %[^\n]", cmd, options);

    // char *cmd = strtok(input, " ");
    // int len = strlen(input);

    // for (i = 0; i < len; i++){
    //     if (input[i] == ' '){
    //         break;
    //     }
    // }

    // for (int j = 0; j < len - i; j++){
    //     input[j] = input[j + i + 1];
    // }
    
    // input[len - i] = '\0';
    // strcpy(options, input);

    if (strcmp(cmd, "show") == 0) {
        show(options, sockfd);
    } else if (strcmp(cmd, "exit") == 0) {
        send_message(sockfd, "Exiting\n");
        exit(EXIT_SUCCESS);
    } else if (strcmp(cmd, "add") == 0) {
        add_row(options, sockfd);
    } else if (strcmp(cmd, "search") == 0) {
        search_row(options, sockfd);
    } else if (strcmp(cmd, "delete") == 0) {
        delete_row(options, sockfd);
    } else if (strcmp(cmd, "status") == 0) {
        status_search(options, sockfd);
    }
    else {
        send_message(sockfd, "Invalid command\n");
    }
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    char buffer[1024] = {0};
    char *hello = "Connection established\n";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    send(new_socket, hello, strlen(hello), 0);

    while (1) {
        valread = read(new_socket, buffer, 1024);
        printf("Client: %s\n", buffer);
        handle_command(buffer, new_socket);
    }

    return 0;
}
