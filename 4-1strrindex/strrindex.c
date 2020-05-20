#include <stdio.h>

int strrindex(char s[], char t[])
{
    int slen, j, k, i, tlen; /* i:s index */ /* j:t index */
    while (s[slen] != '\0')
        slen++;
    while (t[tlen] != '\0')
        tlen++;
    for (i = slen - 1; i >= 0; i--)
    {
        for (j = i, k = tlen - 1; s[j] == t[k] && k >= 0 && j >= 0; k--, j--)
            ;

        if (s[++j] == t[++k] && k == 0)
        {
            return j;
        }
    }
    return 0;
}