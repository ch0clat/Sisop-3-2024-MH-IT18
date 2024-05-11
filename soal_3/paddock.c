#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include "action.h"

#define PORT 8080

void log_message(const char* source, const char* command, const char* additional_info) {
    time_t rawtime;
    struct tm *info;
    char timestamp[80];

    time(&rawtime);
    info = localtime(&rawtime);

    strftime(timestamp, 80, "%d/%m/%Y %H:%M:%S", info);

    FILE *fp = fopen("/home/kali/sisoptest/modul3/race.log", "a");
    if (fp == NULL) {
        perror("Failed to open log file");
        return;
    }

    fprintf(fp, "[%s] [%s]: [%s] [%s]\n", source, timestamp, command, additional_info);
    fclose(fp);
}

void handle_rpc_call(int new_socket) {
    char buffer[1024] = {0};
    read(new_socket, buffer, 1024);

    char command[50];
    char info[50];

    sscanf(buffer, "%s %s", command, info);
    log_message("Driver", command, info);

    char response[1024] = {0};

    if (strcmp(command, "Gap") == 0) {
        float distance = atof(info);
        strcpy(response, handle_gap(distance));
    } else if (strcmp(command, "Fuel") == 0) {
        int fuel = atoi(info);
       strcpy(response, handle_fuel(fuel));
    } else if (strcmp(command, "Tire") == 0) {
        int tire_wear = atoi(info);
        strcpy(response, handle_tire(tire_wear));
    } else if (strcmp(command, "TireChange") == 0) {
        strcpy(response, handle_tire_change(info));
    } else {
        strcpy(response, "Invalid command");
    }

    send(new_socket, response, strlen(response), 0);
    log_message("Paddock", command, response);

    close(new_socket);
}

static void skeleton_daemon()
{
    pid_t pid, sid;
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return;
    }

    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }

    umask(0);

    sid = setsid();
    if (sid < 0)
    {
        perror("SID failed");
        return;
    }

    if ((chdir("/")) < 0)
    {
        perror("Chdir failed");
        return;
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    openlog("paddock", LOG_PID, LOG_DAEMON);
    syslog(LOG_NOTICE, "paddock started");
}

int main() {
    skeleton_daemon();

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        return 1;
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
    }

    while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept failed");
        continue;
    }

        handle_rpc_call(new_socket);
    }

    syslog (LOG_NOTICE, "Paddock terminated.");
    closelog();
    
    return EXIT_SUCCESS;
}
