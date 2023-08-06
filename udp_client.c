#include<stdio.h>

#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
void main(){
    char *ip="127.0.0.1";
    int port =8890;
    struct sockaddr_in addr;
    socklen_t addr_size;
    int sockfd;
    char buffer[1024];
    sockfd=socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd<0){
        printf("\nsocket error");
        exit(1);


    }
    addr_size=sizeof(addr);
    printf("\nserver socket created");
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr=INADDR_ANY;
    addr.sin_port = htons(port);
    bzero(buffer, 1024);

    printf("\nstring from client:");
    scanf(" %s",buffer);
    sendto(sockfd,buffer,1024,0,(struct sockaddr*)&addr,addr_size);
    bzero(buffer,1024);
    recvfrom(sockfd, buffer ,1024 , 0,(struct sockaddr*)&addr, &addr_size);
    printf("\nreceived from server: %s",buffer);
    close(sockfd);
    printf("\ndisconnected from server");



}
