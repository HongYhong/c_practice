/* this is the version2 of getop which can be used without ungetch */
#include <stdio.h>
#include "calc.h"
#include <ctype.h>

int getop2(char s[])
{
    int c, i = 0, next;
    static int buf = EOF;
    if (buf == EOF || buf == ' ' || buf == '\t')
    {
        while ((s[0] = c = getch2()) == ' ' || c == '\t')
            ;
        s[1] = '\0';
    }
    else
    {
        c = buf;
        buf = EOF;
    }
    if (isalpha(c))
    {
        while (isalpha(s[++i] = c = getch2()))
            ;
        s[i] = '\0';
        if (c != EOF)
            buf = c;
        return INDENTIFIER;
    }
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* return an operator or invalid character*/
    if (c == '-')
    {
        next = getch2();
        if (!isdigit(next) && next != '.')
        {
            buf = next;
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
        buf = c;
    return NUMBER;
}