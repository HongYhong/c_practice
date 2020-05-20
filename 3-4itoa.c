#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void reverse(char s[])
{
    int i=0,len;
    int temp;
    for (len =0 ; s[len] != '\0';len++)
    {
        ;
    }
    len--;
    while(i < len)
    {
        temp = s[i];
        s[i++] = s[len];
        s[len--] = temp;
    }
}

void itoa2(int n,char s[])
{
    int i,sign;
    i = 0;
    sign = n;
    do{
        s[i++] = abs(n % 10) + '0';
    }while (n /= 10);
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
    printf("%d\n",INT_MIN);
    itoa2(INT_MIN,s);
    printf("%s",s);
    return 0;
}



