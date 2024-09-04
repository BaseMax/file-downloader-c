/**
 *
 * @Author: Max Base
 * @Repository: https://github.com/BaseMax/file-downloader-c
 * @Date: 09/04/2024
 * @Build: gcc -o file-downloader file-downloader.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    const char *hostname = "example.com";
    const char *path = "/file.txt";
    const char *port = "80";
    char request[256];
    char buffer[BUFFER_SIZE];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    size_t bytes_received;
    FILE *fp;

    snprintf(request, sizeof(request), "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return 2;
    }

    freeaddrinfo(servinfo);

    send(sockfd, request, strlen(request), 0);

    fp = fopen("downloaded_file.txt", "wb");

    if (!fp) {
        perror("fopen");
        close(sockfd);
        return 3;
    }

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}
