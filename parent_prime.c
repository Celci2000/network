#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <math.h>

int main(){
   
     
    int n ,flag=0;
    printf("enter n:");
    scanf("%d", &n);
    int x=n/2;
     pid_t pid = fork(); 
    if(pid>0){
        printf("\nparent process");
        for(int i=2;i<=x;i++){
            if(n%i==0){
                flag=1;
                break;
            }
        }
        if(flag==1|| n==0 || n==1){
            printf("\n  not  a prime number");
        }
        else if (flag==0){
                   printf("\nprime number");
        }
    }
    else if(pid==0){
        printf("\n child process\n");
    }
    return 0;
}
 