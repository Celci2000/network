#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
// #include<sys/wait.h>

#include<ctype.h>
int main(){
    char str[100];
    pid_t n;
    printf("enter a string");
    fgets(str, 100, stdin);
    n=fork();
    if(n<0){
        printf("\nfork failed");
    }
    else if(n==0){
        printf("\nchild process\n");
        for(int i=0;str[i]!='\0';i++){
              str[i]=str[i]-'a'+'A';     
              printf("%c" , str[i]);    
        }
      
      

    }
    else{
        printf("parent processs or child proces finished\n");
    }
    return 0;
}
