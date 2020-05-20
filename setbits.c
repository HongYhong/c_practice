#include <stdio.h>

int setbits(unsigned x,int p,int n,unsigned y)
{
    return ((~((~(~0 << n))<<(p-n+1))) & x )| (((~(~0 << n)) & y) << (p-n+1))  ;
}

int main(int argc, char const *argv[])
{
    int x = 0b101011101;
    int y = 0b1110101111;
    printf("%d",setbits(x,4,3,y));
    return 0;
}
