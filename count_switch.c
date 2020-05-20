#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c,i,nwhite = 0,nothers = 0;
    int digits[10];
    for (i = 0;i<= 9;i++)
    {
        digits[i] = 0;
    }

    while ((c = getchar())!= EOF)
    {
        switch (c)
        {
        case '1': case '2':case '3': case '4':case '5': case '6':case '7': case '8':case '9': case '0':
            digits[c - '0']++;
            break;
        case ' ':case '\n' :case '\t':
            nwhite ++;
            break;
        default:
            nothers++;
            break;
        }
    }
    printf("the numbers of digits are:");
    for (i = 0;i<=9;i++)
    {
        printf("%d,",digits[i]);
    }
    printf("\nthe number of whites are %d\nthe number of others are %d",nwhite,nothers);
    return 0;
}
