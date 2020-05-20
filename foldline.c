#include <stdio.h>
#define foldgap 10
#define MAXLINE 10000

int getline(char s[],int limit)
{
    int c,i=0;
    for (i=0;i<=limit;++i)
    {
        s [i] = '\0';
    }
    i = 0;
    while((c = getchar())!=EOF && c != '\n')
    {
        s[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        s[i] = '\n';
        ++ i;
    }
    s[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    int len,foldpos=foldgap,i,j,temp;
    char line[MAXLINE];
    while((len = getline(line,MAXLINE))>0)
    {
        for (foldpos=foldgap;foldpos<=len;foldpos+=(foldgap+1))
        {
            if (line[foldpos] != '\0')
            {
                for (i = foldpos;i > foldpos - foldgap ;--i)
                {
                    if (line[i] != ' ')
                    {
                        for (j=len;j>=i;j--)
                        {
                            line[j+1] = line[j];
                        }
                        line[i] = '\n';
                        len++;
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        printf("%s",line);
    }
    return 0;
}
