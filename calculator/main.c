#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXOP 100   /* the max length of operand or operator */

#define MAXVAL 1000

#include "calc.h"

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
    while ((type = getop2(s)) != EOF)
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
