#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
void main(){
    char*ip= "127.0.0.1";
    int port =8880;
    struct sockaddr_in addr;
   socklen_t addr_size ;

   int sockfd;
   sockfd=socket(AF_INET, SOCK_STREAM,0);

if(sockfd<0){
    printf("\nsocket error");
    exit(1);

}
printf("\nclient socket created");
bzero(&addr ,sizeof(addr));
addr.sin_family=AF_INET;
addr.sin_addr.s_addr= INADDR_ANY;
addr.sin_port= htons(port);

connect(sockfd ,(struct sockaddr*)&addr, sizeof(addr));

printf("\nclient socket connected to server");
char buffer[1024];
bzero(buffer, 1024);
strcpy(buffer, "test.txt");
send(sockfd, buffer,1024 ,0 );
printf("\nclient : sent the filename");
bzero(buffer,1024);
recv(sockfd,buffer,1024 ,0);
printf("\n received frrom server:\n%s",buffer);
close(sockfd);
printf("disconnected from server");

}

