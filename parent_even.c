#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

void main()
{
int arr[10],n;
printf("\nEnter the number of elements: ");
scanf("%d",&n);
printf("Enter the elements:");
for(int i=0; i<n; i++)
{
scanf(" %d",&arr[i]);
}
int n1 = fork();
if(n1>0)
{
int sum=0;
for(int i=0; i<n; i++)
{
if(arr[i]%2==0)
{
sum+=arr[i];
}
}
printf("\nParent Process... Sum of even numbers: %d",sum);

}
else if(n1==0)
{
int sum=0;
for(int i=0; i<n; i++)
{
if(arr[i]%2==01)
{
sum+=arr[i];
}
}
printf("\nChild Process... Sum of odd numbers: %d",sum);
}
else{
    printf(" fork error");
}
}