#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
void main(){
    char*ip ="127.0.0.1";
    int  port =8890;
    struct sockaddr_in server_addr,client_addr;
    socklen_t addr_size;
    int sockfd;
    int n;
    char buffer[1024];
    sockfd= socket(AF_INET , SOCK_DGRAM, 0);
    if(sockfd<0){
        printf("\nsocket error");
        exit(1);
    }
    printf("\nserver socket created" );
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY;
    server_addr.sin_port=htons(port);
    n =bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(n<0){
        printf("\nbind error");
        exit(1);

    }
    printf("\nbinded successfully");
    bzero(buffer,1024);
    addr_size=sizeof(client_addr);
    recvfrom(sockfd,buffer ,1024 ,0 , (struct sockaddr*)&client_addr,&addr_size );
    printf("received from  client:%s ",buffer);
    for(int i=0;i<strlen(buffer);i++){
        buffer[i]=buffer[i]-'a'+'A';
    }

    sendto(sockfd, buffer ,1024 ,0 ,(struct sockaddr*)&client_addr,sizeof(client_addr));
    printf("\nsend to client :%s",buffer);
    close(sockfd);printf("\ndisconnected");
}