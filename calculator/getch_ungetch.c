#include <stdio.h>
#include <string.h>
#define buffer_size 100
char buffer[buffer_size];
int bufp = 0; /* the next position of the   */

int getch2(void)
{
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch2(int c)
{
    if (bufp >= buffer_size)
    {
        printf("error:too many characters.");
    }
    else
    {
        buffer[bufp++] = c;
    }
}

void ungets(char s[])
{
    int len = strlen(s);
    while (len > 0)
        ungetch2(s[--len]);
}