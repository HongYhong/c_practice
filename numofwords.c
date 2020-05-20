#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c,nw=0,inword=0;
    while((c = getchar())!=EOF)
    {
        if (c == '\n' || c == '\t' || c == ' ')
        {
            inword = 0;
        }
        else
        {
            if (inword == 0)
            {
                nw++;
                inword =1;
            }
        }
        
    }
    printf("the number of words is %d",nw);
    return 0;
}
