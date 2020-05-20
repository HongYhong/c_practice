#include <stdio.h>

int lower(char c)
{
    return (c < 'Z' && c > 'A') ? c - 'A' + 'a' : 0;
}

int main(int argc, char const *argv[])
{
    char c = 'H';
    printf("%c",lower(c));
    return 0;
}
