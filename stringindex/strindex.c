#include <stdio.h>

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