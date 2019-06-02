#include<stdio.h>
int main()
{
    int n = 7, k = 4;
    KthBitSetorNot(n,k);
    return 0;
}
void KthBitSetorNot(int n, int k)
{
    if (n & (1 << k-1))
        printf("SET");
    else
        printf("NOT SET");
}
 