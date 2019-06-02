#include <stdio.h>       
int main()
{
    int n = 7;
    printf("%d", countSetBits(n));
    return 0;
}
int countSetBits(int i)
{
   int count = 0;
  while (i)
  {
    count += i & 1;
    i >>= 1;
  }
  return count;
}
