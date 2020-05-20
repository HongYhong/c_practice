/* practice 1-20 */

#include <stdio.h>
#define TABSIZE 5
#define MAXLINE 1000

int calculatespaces(int tabsize,int linelen)
{
    return tabsize - (linelen % tabsize);
}

int getline(char s[],int limit)
{
    int c,i=0;
    while ((c = getchar()) != EOF && c != '\n' && i<=MAXLINE)
    {
        s[i] = c;
        i ++;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    int len,i,l,j;     /* i for the position in line array */ /* l for position in output result */ /* number of spaces */
    char line[MAXLINE];
    while ((len = getline(line,MAXLINE)) >0)
    {
        for (i = 0,l = 0;i<len;i++)
        {
            if (line[i] == '\t')
            {
                j = calculatespaces(TABSIZE,l);
                while (j > 0)
                {
                    putchar(' ');
                    j --;
                    l ++;
                }
            }
            else
            {
                putchar(line[i]);
                ++l;
            }
        }
    }
    return 0;
}
