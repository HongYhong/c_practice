/* histogram of different characters */

#include <stdio.h>
#define MAXNUM 256

int main(int argc, char const *argv[])
{
    int c, i, j, maxcount = 0, count = 0;
    int nchar[MAXNUM];
    for (i = 0; i < MAXNUM; i++)
    {
        nchar[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        ++nchar[c];
    }

    for (i = 0; i < MAXNUM; i++)
    {
        count = nchar[i];
        if (maxcount < count)
        {
            maxcount = count;
        }
    }

    for (i = maxcount; i > 0; i--)
    {
        printf("%3d| ", i);
        for (j = 0; j < MAXNUM; j++)
        {
            if (nchar[j] > 0)
            {
                if (nchar[j] >= i)
                {
                    printf(" * ");
                }
                else
                {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }
    printf("    +--------------------------------------------------------->\n    ");

    for (j = 0; j < MAXNUM; j++)
    {
        if (nchar[j] > 0)
        {
            printf("%3d", j / 100);
        }
    }
    printf("\n    ");

    for (j = 0; j < MAXNUM; j++)
    {
        if (nchar[j] > 0)
        {
            printf("%3d", j / 10 %10 );
        }
    }
    printf("\n    ");

    for (j = 0; j < MAXNUM; j++)
    {
        if (nchar[j] > 0)
        {
            printf("%3d",j %10);
        }
    }
    printf("\n");
    return 0;
}
