#include <stdio.h>
#define MAXLINE 1000

void discard_newline(char s[])
{
    int i=0;
    while(s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
        }
        ++i;
    }
}

void reverse(char s[])
{
    int i,j;
    char temp;
    for (j=0;s[j]!='\0';j++)
    {
        ;
    }
    --j;
    i = 0;
    while(j>i)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
}

int getline(char s[],int limit)
{
    int c,i=0;
    for (i = 0;i<=limit;i++)
    {
        s[i] = '\0';
    }
    i = 0;
    while((c=getchar())!=EOF && c != '\n')
    {
        s [i] = c;
        ++i;
    }
    if (c == '\n')
    {
        s[i] = '\n';
        ++i;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int len;
    char line[MAXLINE];
    char store[MAXLINE];
    while ((len = getline(line,MAXLINE)) > 0)
    {
        discard_newline(line);
        reverse(line);
        printf("%s",line);
    }
}
