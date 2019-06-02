#include<stdio.h>
int main()
{
    int n;
  printf("enter number");
  scanf("%d",&n);
  PowerOfTwo(n)? printf("it is power of two\n"): printf("it is not a power of 2\n");
  return 0;
}
int PowerOfTwo (int x)
{
  return x && (!(x&(x-1)));
}

