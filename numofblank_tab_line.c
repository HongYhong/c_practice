#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nb = 0,nt = 0,nl = 0,c;
    while ((c=getchar())!=EOF)
    {
        if (c == ' ')
        {
            nb++;
        }
        if (c == '\t')
        {
            nt++;
        }
        if (c == '\n')
        {
            nl++;
        }
    }
    printf("the number of blanks is %d",nb);
    printf("the number of tabs is %d",nt);
    printf("the number of lines is %d",nl);
    return 0;
}
