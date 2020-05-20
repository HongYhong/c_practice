#include <stdio.h>
#include <string.h>
void reverse(char s[])
{
    int i, j;
    char temp;
    for (j = 0; s[j] != '\0'; j++)
    {
        ;
    }
    --j;
    i = 0;
    while (j > i)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
}
/* convert number to string */
void itoa(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i] = '-';
    }
    s[i] = '\0';
    reverse(s);

}

int main(int argc, char const *argv[])
{
    int n = 93939356;
    char s[1000];
    itoa(n, s);
    printf("%s", s);
    return 0;
}
