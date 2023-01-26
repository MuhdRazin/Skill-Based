#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char* argv[]) {
    int server_sock, client_s, cl, read_size;
    struct sockaddr_in server, client;
    int rnum;
    srand(time(0));


    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(4202);

    bind(server_sock, (struct sockaddr*)&server, sizeof(server));


    listen(server_sock, 3);

    cl = sizeof(struct sockaddr_in);

    client_s = accept(server_sock, (struct sockaddr*)&client, (socklen_t*)&cl);

    rnum = (rand() % (999 - 100 + 1) + 100);

    write(client_s, &rnum, sizeof(rnum));


    close(client_s);
    close(server_sock);
    return 0;
}
