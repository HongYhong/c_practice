#include <stdio.h>
#include <ctype.h>
#define MAXELEMENTS 1000
#define MAX 1000

int getint(int *);
int getch(void);
void ungetch(int);

int main(int argc, char const *argv[])
{
    int n, array[MAXELEMENTS], i;
    for (n = 0; (getint(&array[n])) != EOF && n < MAXELEMENTS; n++)
        ;
    for (i = 0; i < n; i++)
    {
        printf("%d,", array[i]);
    }
    return 0;
}

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ;
    if (c != EOF && !isdigit(c) && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn = *pn * sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int buffer[MAX];
int bp = 0;

int getch(void)
{
    return (bp > 0) ? buffer[--bp] : getchar();
}

void ungetch(int c)
{
    if (bp < MAX)
        buffer[bp++] = c;
}
