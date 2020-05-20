/*blank trim version2*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c,inspace;
    inspace = 0;
    while((c=getchar())!=EOF)
    {
        if (c == ' ')
        {
            if (inspace == 0)
            {
                inspace = 1;
                putchar(c);
            }
        }
        else
        {
            putchar(c);
            inspace = 0;
        }
        
        
    }
    return 0;
}
