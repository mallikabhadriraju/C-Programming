#include<stdio.h>
int main()
{
  int n = 1;
  printf("%d", nextnum2(n));
  return 0;
}
 
  int nextnum2( int n)
{
 int count = 0;
while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}
