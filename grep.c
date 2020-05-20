#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int limit);
int stringmatch(char line[], char pattern[]);

int main(int argc, char const *argv[])
{
    int len;
    char line[MAXLINE];
    char pattern[] = "ould";
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (stringmatch(line, pattern))
        {
            printf("%s", line);
        }
    }
    return 0;
}

int getline(char line[], int limit)
{
    int c, i = 0;
    while (--limit && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }
    if (c == '\n')
    {
        line[i++] = '\n';
    }
    line[i] = '\0';
}

int stringmatch(char line[], char pattern[])
{
    int i, j, k;
    for (i = 0; line[i] != '\0'; i++)
    {
        for (j = i, k = 0; line[j] == pattern[k] && pattern[k] != '\0'; j++, k++)
            ;
        if (pattern[k] == '\0')
        {
            return i;
        }
    }
    return 0;
}
