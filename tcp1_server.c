#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char*ip="127.0.0.1";
  int   port= 8880;
     struct sockaddr_in server_addr, client_addr;
     int sockfd,confd;
     socklen_t addr_size;
     int n;
     sockfd= socket(AF_INET, SOCK_STREAM, 0);
     if(sockfd<0){
        printf("socket error\n");
        exit(1);
     }
     printf(" \nserver sockect created");
     bzero(&server_addr, sizeof(server_addr));
     server_addr.sin_family = AF_INET;
     server_addr.sin_addr.s_addr= INADDR_ANY;
     server_addr.sin_port= htons(port);

     n= bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
     if(n<0){
        printf("\n bind error");
        exit(1);
     }
     printf("\nbind to port number:%d",port);

     listen(sockfd, 10);
     printf("\n server sockect listening");
  char buffer[1024];
  char filename[1024];
  FILE*fptr;
  addr_size= sizeof(client_addr);
        confd= accept(sockfd, (struct sockaddr*)&client_addr, &addr_size);
        bzero(buffer ,1024);
        if(confd<0){
            printf("connnection error");
            exit(1);

        }
        printf("\nconnection established");
     while(1){
        
        recv(confd, buffer ,1024 ,0);
        printf("\nclient's msg - filename:%s",buffer);
        strcpy(filename, buffer);
        bzero(buffer, 1024);
        fptr= fopen(filename, "r");
        if(fptr==NULL){
            send(confd, "no such file",sizeof("no such file"),0);
            printf("\n error reading file");
            exit(1);
        }
        int lines=1, words= 0, chars=0;
        char ch= getc(fptr);
        while(ch!=EOF){
            chars++;
            if(ch==' ' || ch=='.'){
                words++;
            }
            else if(ch=='\n'){
                lines++;
            }
            ch=getc(fptr);
        }
        char charstr[10], wordstr[10], linestr[10];
        strcpy(buffer, "number of charcters:");
        sprintf(charstr,"%d", chars);
        strcat(buffer,charstr );
        strcat(buffer,"\nNumber of words: ");
        sprintf(wordstr, "%d", words);
        strcat(buffer, wordstr);
        strcat(buffer, "\n NUmber of lines");
           sprintf(linestr,"%d", lines);
        strcat(buffer,linestr);
        strcat(buffer, "\n");

        send(confd, buffer, 1024, 0);
        close(confd);
        printf("\n client disconneted");


     }

}