#include <stdio.h>
#include <stdlib.h>
unsigned  getbits(unsigned x,int p,int n)
{
    return ((x >> p - n +1) & ~(~0 << n));
}

int main(int argc, char const *argv[])
{
    int x = 0b101010101010;
    char s[10];
    x = getbits(x,5,3);
    printf("%d",x);
    return 0;
}
