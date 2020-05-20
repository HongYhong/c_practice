#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


#define NUMBER '0'
#define INDENTIFIER '1'
#define ENDSTRING '2'
#define MAXVAR 1000
#define MAX_ID_LEN 1000
#define MAXOP 100   /* the max length of operand or operator */
#define MAXVAL 1000
#define buffer_size 100

struct varType
{
    char name[MAX_ID_LEN];
    double val;
};

struct varType last;

char buffer[buffer_size];
int bufp = 0; /* the next position of the   */

int pos;

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






/* how to assigning a variable
   4 a =    OR
   4 4 + a = OR
 */



int main(int argc, char const *argv[])
{
    struct varType var[MAXVAL];
    clearstack(var);
    int type;
    char s[MAXOP];
    double op2;
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:           /* we get an operand from the input */
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 == 0.0)
            {
                printf("error:0 divisor.\n");
            }
            else
            {
                push(pop() / op2);
            }
            break;
        case '%':
            op2 = pop();
            if(op2 == 0.0)
            {
                printf("error:0 divisor.\n");
            }
            else
            {
                push(fmod(pop(),op2));
            }
            break;
        case INDENTIFIER:
            dealwithname(s,var);
            break;
        case ENDSTRING:
            break;
        case '\n':
            printf("\t%f\n",pop());
            break;
        case '~':
            swaptop();
            break;
        case '#':
            copytop();
            break;
        case '?':
            showtop();
            break;
        case '!':
            clearstack(var);
            break;
        case '=':
            pop();
            var[pos].val = pop();
            last.val = var[pos].val;
            push(last.val);
            break;
        default:
            printf("error:unknown command.\n");
            break;
        }
    }
    return 0;
}
