#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


#define MAX 1000

int getfloat(double *);

int main(int argc, char const *argv[])
{
    int n, i;
    double array[MAX];
    for (n = 0; (getfloat(&array[n])) != EOF && n < MAX; n++)
        ;
    for (i = 0; i < n; i++)
    {
        printf("%g,", array[i]);
    }
    return 0;
}

int getch(void);
void ungetch(int);

int getfloat(double *pn)
{
    int c, sawsign = 0;
    double fraction = 0.0,sign = 1.0;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != '+' && c != '-' && c != EOF)
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (sawsign = (c == '+' || c == '-'))
    {
        c = getch();
    }
    if (!isdigit(c) && c != '.' && c != EOF)
    {
        ungetch(c);
        if (sawsign == 1)
        {
            ungetch((sign == -1) ? '-' : '+');
        }
    }
    for (*pn = 0; isdigit(c) || c == '.'; c = getch())
    {
        if (c == '.')
            fraction = 1;
        else
        {
            if (fraction == 0)
            {
                *pn = *pn * 10 + (c - '0'); /* the int part */
            }
            else
            {
                *pn = *pn + ((c - '0') / pow(10, fraction++)); /* the demical part */
            }
        }
    }
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
