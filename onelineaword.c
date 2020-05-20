#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c,inword=0;
    while((c = getchar())!= EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (inword == 1)
            {
                printf("\n");
                inword =0;
            }
        }
        else
        {
            putchar(c);
            inword = 1;
        }
    }
    return 0;
}
