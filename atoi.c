#include <stdio.h>
#include <ctype.h>
#define MAX 1000
int atoi(char s[])
{
    int i, n = 0;
    for (i = 0; s[i] <= '9' && s[i] >= '0'; i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

int atoi2(char s[])
{
    int i, sign,n;
    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }          /* jump through the spaces */

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '-' || s[i] == '+')
    {
        i++;
    }

    for (n = 0;isdigit(s[i]);i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}

int main(int argc, char const *argv[])
{
    char num[] = "  -213213";
    printf("%d", atoi2(num));
    return 0;
}
