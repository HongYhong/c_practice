/* blank trim */
/* version 1 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a=getchar(),c;
    while((c = getchar())!=EOF)
    {
        if (c == ' ' & a == ' ' )
        {
            ;
        }
        else
        {
            putchar(a);
        }
        
        a = c;
    }
    return 0;
}
