#include<stdio.h>
int main()
{
  int n = 256;
  power4(n);
  return 0;
}
 
  void power4( int n)
{
 int count = 0;
while( n %4== 0)
  {
    n=n/4;
  }
 if(n==1)
 printf("it is a power of 4");
 else
 printf("it is not a power of 4");
}