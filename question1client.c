#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char*argv[])
{
 int client_sock, rnum;
 struct sockaddr_in server;


 client_sock = socket(AF_INET, SOCK_STREAM, 0);
 server.sin_addr.s_addr = inet_addr("192.168.88.128");
 server.sin_family = AF_INET;
 server.sin_port = htons(8080);

 connect(client_sock,(struct sockaddr*)&server,sizeof(server));



 recv(client_sock, &rnum, sizeof(rnum),0);
 printf("Random number from server is %d\n",rnum);

 close(client_sock);
 return 0;
}
