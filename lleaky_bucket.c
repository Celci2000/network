#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
#include<unistd.h>

#define  packetCount 10
void main(){
 srand(time(0));
 int packets[packetCount], remaining_size=0,op,rate,bucket_size=0;
 int timetotransmit, clk;
 printf("\nenter the bucket_size:");
 scanf("%d", &bucket_size);
 printf("\nenter the rate:");
 scanf("%d", &rate);
 for(int i=0;i<packetCount;i++){
    packets[i]= (rand()%6+1)*10;
}

int i=0;
while(i<packetCount || remaining_size>0){
    if(i<packetCount){
          if(packets[i]+remaining_size>bucket_size){
            printf("\noverflow");

          }
          else{
             remaining_size+=packets[i];
             printf("\n\n incoming packet : %d",packets[i]);
             printf("\n bytes remaining to transmit: %d", remaining_size);

          }
          i++;

    }
    timetotransmit= (rand()%4+1)*10;
    printf("\ntime  left to transmit:%d", timetotransmit);
    
    for(clk=10;clk<=timetotransmit;clk+=10){
        sleep(1);
        if(remaining_size){
            if(remaining_size<=rate){
                op=remaining_size;
                remaining_size=0;
            }
            else{
                op=rate;
                remaining_size-=rate;
                printf("\n packet %d transmitted ",op);
                printf("\n bytes remaining to transmit: %d", remaining_size);


            }
        }
        else{
            printf("\ntime left for transmission %d units", timetotransmit-clk);
            printf("\n no packets to transmit\n");
        }

    }

}

}