#include <stdio.h>

int invert(unsigned x,int p,int n)
{
    return (~(~0 << n)) << (p - n + 1) ^ x; 
}

int main(int argc, char const *argv[])
{
    int x = 0b111010100111;
    printf ("%d",invert(x,4,3));
    return 0;
}
