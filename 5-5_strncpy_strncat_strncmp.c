#include <stdio.h>

char *strncpy2(char *s, char *t, int n)
{
    while ((n-- > 0) && (*s++ = *t++))
        ;
    *s = '\0';
    return s;
}

char *strncat2(char *s,char *t,int n)
{
    while (*s++)
        ;
    s--;
    while((n-- > 0) && (*s++ = *t++) )
        ;
    return s;
}

int strncmp2(char *s,char *t,int n)
{
    while ((n-- > 0)&&(*s == *t))
    {
        s++;
        t++;
    }
    n++;
    if (*s == '\0' || n == 0)
        return 0;
    return *t - *s;
}



int main(int argc, char const *argv[])
{
    char s[1000] = "abcg";
    char t[1000] = "abe";
    printf("%d\n",strncmp2(s,t,3));
    strncat2(s,t,6);
    printf("%s", s);
    return 0;
}
