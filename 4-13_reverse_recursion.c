/* the recursion version of reverse function */
#include <stdio.h>
#include <string.h>


void reverse(char s[],int len)
{
    static int i = 0;
    int temp;
    if (i < len)
    {
        temp = s[i];
        s[i++] = s[len];
        s[len--] = temp;
        reverse(s,len);
    }
}

int main(int argc, char const *argv[])
{
    char s[] = "abcdefg";
    reverse(s,strlen(s) - 1);
    printf("%s",s);
    return 0;
}
