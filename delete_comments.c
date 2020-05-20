#include <stdio.h>
#define MAXLINE 10000
int main(int argc, char const *argv[])
{
    int c, incomment = 0, i = 0, j, quote = 0;
    char s[MAXLINE];
    while ((c = getchar()) != EOF)
    {
        s[i] = c;
        i++;
    }

    for (j = 0; j <= i; j++)
    {
        if (quote == 0 && (s[j] == '"' || s[j] == '\''))
        {
            quote = 1;
        }
        else
        {
            if (quote == 1 && (s[j] == '"' || s[j] == '\''))
            {
                quote = 0;
                ++j;
            }
        }

        if (!quote)
        {
            if (s[j] == '/' && s[j + 1] == '*')
            {
                s[j] = '\0';
                s[j + 1] = '\0';
                incomment = 1;
                j++;
                continue;
            }
            if (s[j] == '/' && s[j + 1] == '/')
            {
                s[j] = '\0';
                s[j + 1] = '\0';
                incomment = 2;
                continue;
                j++;
            }
            if (incomment == 1 && s[j] == '*' && s[j + 1] == '/')
            {
                s[j] = '\0';
                s[j + 1] = '\0';
                incomment = 0;
                j++;
                continue;
            }
            if (incomment == 2 && s[j] == '\n')
            {
                incomment = 0;
                continue;
            }
            if (incomment == 1 || incomment == 2)
            {
                s[j] = '\0';
                continue;
            }
        }
        else
        {
            continue;
        }
    }
    for (j = 0; j <= i; j++)
    {
        if (s[j] != '\0')
        {
            printf("%c", s[j]); /* sadasd */
        }
    }
    return 0;
}

