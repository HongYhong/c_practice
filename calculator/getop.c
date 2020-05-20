#include <stdio.h>
#include <ctype.h>

#include "calc.h"

int getop(char s[])
{
    int c, i = 0;
    char next;
    /* skip white spaces */
    while ((s[0] = c = getch2()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch2()))
            ;
        s[i] = '\0';
        if (c != EOF)
            ungetch2(c);
        return INDENTIFIER;
    }

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* return an operator or invalid character*/
    if (c == '-')
    {
        next = getch2();
        if (!isdigit(next) && next != '.')
        {
            ungetch2(next);
            return c; /* it is an operator */
        }
        else
        {
            c = next;
            s[++i] = c;
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch2()))
            ; /* get the int part */
    if (c == '.')
        while (isdigit(s[++i] = c = getch2()))
            ; /* decimal part */
    s[i] = '\0';
    if (c != EOF)
        ungetch2(c);
    return NUMBER;
}
