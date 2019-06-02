#include<stdio.h>
int setKthBit(int n, int k)
{
    return ((1 << k) | n);
}
int main()
{
    int n = 10, k = 3;
    printf("Kth bit set number = %d",setKthBit(n, k));
    return 0;
} 
