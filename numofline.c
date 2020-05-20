#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    long nl;
    nl = 0;
    while ((c = getchar())!= EOF)
    {
        if (c == '\n')
        {
            nl ++;
        }
    }
    printf("the number of lines is %d",nl);
    return 0;
}
