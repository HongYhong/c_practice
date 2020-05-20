/* 1-21 practice */
#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int limit)
{
    int i, c;
    for (i = 0; i <= limit; ++i)
    {
        s[i] = '\0';
    }
    i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        s[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        s[i] = '\n';
        i++;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    int len, i = 0;
    char line[MAXLINE];
    while ((len = getline(line, MAXLINE)) > 0)
    {
        i = 0;
        while (line[i] != '\0')
        {
            if (line[i] == ' ' && line[i + 1] == ' ' && line[i + 2] == ' ' && line[i + 3] == ' ')
            {
                putchar('\t');
                i += 4;
            }
            else
            {
                putchar(line[i]);
                i += 1;
            }
        }
    }
    return 0;
}
