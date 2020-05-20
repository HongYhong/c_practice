#include <stdio.h>

void strcat2(char *s,char *t)
{
    while(*s++)
        ;
    s--;
    while(*s++ = *t++)
        ;   
}

int main(int argc, char const *argv[])
{
    char s[1000] = "abcdef";
    char *t = "ggg";
    strcat2(s,t);
    printf("%s",s);
    return 0;
}
