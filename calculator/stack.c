#include <stdio.h>
#include "calc.h"
#include <string.h>
#include <math.h>

#define MAXVAL 1000

int sp = 0;         /* the next position of empty */
double val[MAXVAL]; /* the value stack */

double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error:empty stack.");
        return 0.0;
    }
}

void push(double f)
{
    if (sp >= MAXVAL)
    {
        printf("error:stack full,can't push.");
    }
    else
    {
        val[sp++] = f;
    }
}

void showtop(void)
{
    if (sp > 0)
    {
        printf("The top of the stack:%d\n", val[sp - 1]);
    }
    else
    {
        printf("empty stack.");
    }
}

void copytop(void)
{
    double temp = pop();
    push(temp);
    push(temp);
}

void swaptop(void)
{
    double temp1 = pop();
    double temp2 = pop();
    push(temp1);
    push(temp2);
}

void clearstack(struct varType var[])
{
    int i;
    sp = 0;
    for (i = 0;i<=MAXVAR-1;i++)
    {
        var[i].name[0] = '\0';
        var[i].val = 0.0;
    }
}

void dealwithname(char s[], struct varType var[])
{
    if (0 == strcmp(s, "sin"))
    {
        push(sin(pop()));
    }
    else if (0 == strcmp(s, "cos"))
    {
        push(cos(pop()));
    }
    else if (0 == strcmp(s, "exp"))
    {
        push(exp(pop()));
    }
    else if (0 == strcmp(s, "pow"))
        push(pow(pop(), pop()));
    else
    {
        dealwithvar(s, var);
    }
}

void dealwithvar(char s[], struct varType var[])
{
    int i=0;
    /* first of all,search for the variable in the list.*/
    while (var[i].name[0] != '\0' && i < MAXVAR - 1)
    {
        if(!strcmp(s,var[i].name))
        {
            push(var[i].val);
            last.val = var[i].val;
            strcpy(last.name,s);
            pos = i;
            return ;
        }
        i++;
    }
    /* can not find the variable in the list */
    if (i <= MAXVAR -1)
    {
        strcpy(var[i].name,s);
        strcpy(last.name,s);
        pos = i;
        push(var[i].val);
        last.val = var[i].val;
    }
    else
    {
        printf("error:full variable stack.");
    }
}
