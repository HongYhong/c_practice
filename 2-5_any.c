#include <stdio.h>

int any(char s1[],char s2[])
{
    int i,j;
    for (i = 0;s1[i] != '\0' ;++i)
    {
        for (j = 0; s2[j] != '\0' ;++j)
        {
            if (s1[i] == s2[j])
            {
                break;
            }
        }
        if (s2[j] != '\0')
        {
            break;
        }
    }
    if (s1[i] == '\0')
    {
        return -1;
    }
    else
    {
        return i;
    }
    
}

int main(int argc, char const *argv[])
{
    char eg1[] = "abcdef";
    char eg2[] = "ghi";
    printf ("%d",any(eg1,eg2));
    return 0;
}
