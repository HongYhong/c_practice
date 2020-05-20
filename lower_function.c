#include <stdio.h>
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }
    else
    {
        printf ("the input is wrong.");
    }
    
}
int main(int argc, char const *argv[])
{
    int c= 'G';
    printf("%c",lower(c));
    return 0;
}
