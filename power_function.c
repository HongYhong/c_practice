#include <stdio.h>

int power(int a,int i)
{
    int p=1;
    while(i>0)
    {
        p = p * a;
        -- i;
    }
    return p;
}

int main(int argc, char const *argv[])
{
    printf ("%d",power(2,3));
    return 0;
}

