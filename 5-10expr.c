#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXELEMENTS 1000

#define MAXLEN 100

double stack[MAXELEMENTS]; /* value stack */
int sp = 0;                /* the next position of empty in value stack */

void push(double n)
{
    if (sp < MAXELEMENTS)
        stack[sp++] = n;
    else
    {
        printf("error:full stack.");
    }
}

double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        printf("error:empty stack.");
    }
}

int main(int argc, char const *argv[])
{
    double temp;
    int i;
    for (i = 1; i < argc; i++)
    {
        switch (argv[i][0])
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.':
            push(atof(argv[i]));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            temp = pop();
            push(pop() - temp);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            temp = pop();
            push(pop() / temp);
            break;
        default:
            printf("error:unknown op.");
            break;
        }
    }

printf("%g\n", pop());
return 0;
}
