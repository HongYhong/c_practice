#include <stdio.h>
#define MAXELEMENTS 1000

void itoa(int n,char s[])
{
    static int i = 0;
    if (n < 0)
    {
        s[i++] = '-';
        n = -n;
    }
    if (n/10)
        itoa(n/10,s);
    s[i++] = n % 10 +'0';
    s[i] = '\0';
}

int main(int argc, char const *argv[])
{
    int i=0;
    char s[MAXELEMENTS];
    itoa(-1233322,s);
    printf("%s",s);
    return 0;
}
