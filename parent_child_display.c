#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>


void main(){
    pid_t n1;
     n1=fork();
    if(n1>0){
        printf("\nparent");
    }

    else if(n1==0){
        printf("\nchild");

    }
    else{
        printf("error");
    }
}
