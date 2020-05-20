#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i,c,nothers=0,nblank=0;
    int ndigits[10];

    for (i = 0; i < 10;i++)
    {
        ndigits[i]=0;
    }

    while((c=getchar())!=EOF)
    {
        if (c >= '0' && c<= '9' )
        {
            ++ ndigits[c - '0'];
        }
        else if (c == ' '|| c == '\n'||c == '\t')
        {
            ++ nblank;
        }
        else
        {
            ++ nothers; 
        }
    }
    printf("the numbers of digits are:");
    for (i =0;i<=9;i++)
    {
        printf("%d ",ndigits[i]);
    }
    printf("\n");
    printf("the number of blanks is %d\n",nblank);
    printf("the number of others is %d\n",nothers);
    return 0;
}
