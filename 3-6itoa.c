#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void reverse(char s[], int minlen)
{
    int i = 0, len;
    int temp;
    for (len = 0; s[len] != '\0'; len++)
    {
        ;
    }
    len--;
    if (len >= minlen)
    {
        while (i < len)
        {
            temp = s[i];
            s[i++] = s[len];
            s[len--] = temp;
        }
    }
    else
    {
        while (len <= minlen)
        {
            s[++len] = ' ';
        }
        i = 0;
        while (i < minlen)
        {
            temp = s[i];
            s[i++] = s[minlen];
            s[minlen--] = temp;
        }
    }
}

void itoa2(int n, char s[], int minlen)
{
    int i, sign;
    i = 0;
    sign = n;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s, minlen);
}

int main(int argc, char const *argv[])
{
    char s[1000];
    printf("%d\n", 25);
    itoa2(4425, s, 10);
    printf("%s", s);
    return 0;
}
