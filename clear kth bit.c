#include<stdio.h>
int clearKthBit(int n, int k)
{
    return (~(1 << k) & n);
}
int main()
{
    int n = 10, k = 1;
    printf("Kth bit set number = %d",clearKthBit(n, k));
    return 0;
}