#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int rightrot(unsigned x,int n)
{
    while(n > 0)
    {
        if (x & 1 == 1)
        {
            x = (x >> 1) | ~(~0U >> 1);
        }
        else
        {
            x = x >> 1;
        }
        n -- ;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    unsigned int x = 0b11110101011111101010101010101010;
    unsigned int y = 0b10111101010111111010101010101010;
    printf("%d\n",rightrot(x,2));
    char s[1000];
    itoa(rightrot(x,2),s,2);
    printf("%s",s);
    return 0;
}
