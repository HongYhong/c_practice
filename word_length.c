/* histogram of word length */

#include <stdio.h>
#define MAXNUMWORD 1000

int main(int argc, char const *argv[])
{
    int c, i, maxlen = 0, len = 0, inword = 0;
    int lenword[MAXNUMWORD];
    for (i = 0; i < MAXNUMWORD; ++i)
    {
        lenword[i] = 0;
    }

    int j = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            if (inword == 1)
            {
                lenword[j] = len;
                ++j;
                if (maxlen < len)
                {
                    maxlen = len;
                }
                len = 0;
                inword =0 ;
            }
        }
        else
        {
            inword = 1;
            ++len;
        }
    }

    int t;
    printf("   ^\n");
    for (i = maxlen; i >= 1; --i)
    {
        printf("%3d| ", i);
        for (t = 0; t <= j; ++t)
        {
            if (lenword[t] >= i)
            {
                printf(" * ");
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    printf("   +--------------------------------->\n     ");
    for (t =0 ; t < j;++t)
    {
        
        printf(" %d ",t);
    }
    return 0;
}
