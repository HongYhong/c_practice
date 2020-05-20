#include <stdio.h>

int bitcounts(unsigned x)
{
    int i;
    while (x != 0)
    {
        x &= (x-1);
        i ++;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    unsigned int x = 0b101010101010101;
    printf("%d",bitcounts(x));
    return 0;
}
