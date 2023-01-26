#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    int client_sock;
    struct sockaddr_in server;
    int rnum;


    client_sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_addr.s_addr = inet_addr("192.168.88.128");
    server.sin_family = AF_INET;
    server.sin_port = htons(4202);


    connect(client_sock, (struct sockaddr*)&server, sizeof(server));


    recv(client_sock, &rnum, sizeof(rnum), 0);

    printf("Random number: %d\n", rnum);


    close(client_sock);
    return 0;
}
