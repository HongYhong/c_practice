#include <stdio.h>

int htoi(char s[])
{
    int i = 2, n = 0, power = 1, a;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        while (s[i] != '\0')
        {
            i++;
        }
        i--;
        while (i >= 2)
        {
            if (s[i] < '9' && s[i] > '0')
            {
                a = s[i] - '0';
                n = n + a * power;
                power *= 16;
                i --;
            }
            else if (s[i] <= 'f' && s[i] >= 'a')
            {
                a = s[i] - 'a' + 10;
                n = n + a * power;
                power *= 16;
                i--;
            }
            else if (s[i] <= 'F' && s[i] >= 'A')
            {
                a = s[i] - 'A' + 10;
                n = n + a * power;
                power *= 16;
                i--;
            }
            else
            {
                printf("wrong input");
            }
        }
    }
    else
    {
        printf("wrong input");
    }
    return n;
}

int main(int argc, char const *argv[])
{
    int a;
    char s[] = "0x1ff";
    a = htoi(s);
    printf("%d", a);
    return 0;
}
