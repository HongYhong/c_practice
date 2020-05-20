#include <stdio.h>
void squeenze(char s1[],char s2[])
{
    int i,j,t=0;
    for (i = 0; s1[i] != '\0' ; i++)
    {
        for (j = 0;s2[j] != '\0' ; j++)
        {
            if (s1[i] == s2[j])
            {
                break;
            }
        }
        if (s2[j] == '\0')
        {
            s1[t++] = s1[i];  
        }
    }
    s1[t] = '\0';
}

int main(int argc, char const *argv[])
{
    char eg1[] = "abcdefgggg";
    char eg2[] = "abg";
    squeenze(eg1,eg2);
    printf("%s",eg1);
    return 0;
}
