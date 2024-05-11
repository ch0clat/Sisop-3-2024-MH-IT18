#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_LEN 20


int establish_connection() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void send_rpc_call(int sockfd, const char* command, const char* info) {
    char buffer[1024] = {0};
    snprintf(buffer, sizeof(buffer), "%s %s\n", command, info);
    send(sockfd, buffer, strlen(buffer), 0);
}

void receive_response(int sockfd) {
    char buffer[1024] = {0};
    read(sockfd, buffer, 1024);
    printf("Response from paddock: %s\n", buffer);
}

int main(int argc, char const *argv[]) {
    char command[MAX_LEN];
    char info[MAX_LEN];

    while (1){
    int sockfd = establish_connection();

    printf("Command: ");
    fgets(command, sizeof(command), stdin);

    printf("Info : ");
    fgets(info, sizeof(info), stdin);

    send_rpc_call(sockfd, command, info);
    receive_response(sockfd);
    }

    return 0;
}
