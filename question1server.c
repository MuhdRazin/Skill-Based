#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char*argv[])
{
 int server_sock,client_s, cl, rnum;
 struct sockaddr_in server, client;

 server_sock = socket(AF_INET, SOCK_STREAM, 0);
 server.sin_family = AF_INET;
 server.sin_addr.s_addr = INADDR_ANY;
 server.sin_port = htons(8080);

 bind(server_sock,(struct sockaddr*)&server, sizeof(server));
 listen(server_sock,3);

 cl = sizeof(struct sockaddr_in);
 client_s = accept(server_sock,(struct sockaddr*)&client,(socklen_t*)&cl);

 rnum = rand() % 999 + 100;
 write(client_s,&rnum,sizeof(rnum));

	
 return 0;
}

