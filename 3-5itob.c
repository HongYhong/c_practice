#include <stdio.h>
#include <stdlib.h>

void reverse(char s[])
{
    int i=0,len;
    int temp;
    for (len = 0;s[len] != '\0';len++)
    {
        ;
    }
    len --;
    while(i < len)
    {
        temp = s[i];
        s[i++] = s[len];
        s[len--] = temp;
    }
}

void itob(int n,char s[],int b)
{
    int i,sign,c;
    sign = n;
    do{
        if (n % b <=9 && n % b >= 0)
        {
            s[i++] = n % b +'0';
        }
        else
        {
            s[i++] = n % b - 10 + 'a';
        }
    }while (n /= b);
    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(int argc, char const *argv[])
{
    char s[1000];
    int n = 42;
    itob(n,s,16);
    printf("%s",s);
    return 0;
}
