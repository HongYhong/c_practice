#include <stdio.h>
int getline2(char line[], int limit)
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