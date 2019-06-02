#include<stdio.h>

int main()

{
    
int n;
    
printf("enter a number");
    
scanf("%d",&n);
    
if(lucky(n,2))
    
printf("it is a lucky number");
    
else
    
printf("it is not a lucky number");

}

int lucky(int n,int count)

{
    
int next_position=n;
    
if(count>n)
    
return 1;
    
if(n%count==0)
    
return 0;
    
next_position-=next_position/count;
    
count++;
    
return lucky(next_position,count);

}