#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[])
{
    int i, j = 0;
    char *start;
    char *end;
    char *p;
    char upper_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower_alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char num[] = "0123456789";
    for (i = 0; s1[i] != '\0'; i++)
    {
        switch (s1[i])
        {
        case '-':
            if (i == 0 || s1[i + 1] == '\0')
            {
                s2[j++] = s1[i];
                break;
            }
            else if ((start = strchr(upper_alpha, s1[i - 1])) && (end = strchr(upper_alpha, s1[i + 1])))
                ;
            else if ((start = strchr(lower_alpha, s1[i - 1])) && (end = strchr(lower_alpha, s1[i + 1])))
                ;
            else if ((start = strchr(num, s1[i - 1])) && (end = strchr(num, s1[i + 1])))
                ;
            else
            {
                fprintf(stderr, "mismatch operends '%c-%c'  ", s1[i - 1], s1[i + 1]);
                s2[j++] = s1[i];
                break;
            }

            /* expand in s2 */
            p = start;
            while (p != end)
            {
                if (p < end)
                {
                    p++;
                    s2[j++] = *p;
                }
                else
                {
                    p--;
                    s2[j++] = *p;
                }
            }
            j--;
            break;

        default:
            s2[j++] = s1[i];
            break;
        }
    }
    s2[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char *test[] = {"g-a", "aa-hf", "g-a", "-c-g", "   sd123-9sd", "9-3avs-a-g", "G-A", "G-a", "g-0"};
    char result[1000];

    size_t numtest = sizeof test / sizeof test[0];
    size_t thistest;

    for (thistest = 0; thistest < numtest; thistest++)
    {
        expand(test[thistest], result);
        printf("index of test:%d    test:%s  result:", thistest, test[thistest]);
        printf("%s \n", result);
    }

    return 0;
}
