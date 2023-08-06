#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void main(){
    int nodes[10][10],node_count,i,j,k,change,distAB,distAC,distBC;

     printf("enter the node_count:");
     scanf("%d", &node_count);
     printf("\nenter the cost matrix:\n");
     for(i=0;i<node_count;i++){
        for(j=0;j<node_count;j++){
        scanf("%d",&nodes[i][j]);

     }
     }

     do{
        change=0;
        for(i=0;i<node_count;i++){
            for(j=0;j<node_count;j++){
                if(nodes[i][j]!=-1 && i!=j){
                    for(k=0;k<node_count;k++){
                       distAB=nodes[i][j];
                       distBC=nodes[j][k]==-1? INT_MAX:nodes[j][k];
                       distAC=nodes[i][k]==-1? INT_MAX:nodes[i][k];
                    }
                    if(distBC==INT_MAX){
                        continue;
                    }
                    if(distAC>distBC+distAC){
                        nodes[i][k]=distBC+distAC;
                        change++;
                    }
                }
            }
        }
     }while(change!=0);
     for(int i=0;i<node_count;i++)
{
    for(int j=0;j<node_count;j++){
        printf("%d ",nodes[i][j]);
    }
    printf("\n");
}    
    }



