#include <stdio.h>
#include <stdlib.h>

int letter_to_num(char s)
{
    char list[] = "aAbBcCdDeEfF";
    int i;
    for (i = 0; list[i] != '\0'; ++i)
    {
        if (s == list[i])
        {
            return 10 + i / 2;
            break;
        }
    }
    if (list[i] == '\0')
    {
        return 0;
    }
}

int htoi(char s[])
{
    int i = 0, answer = 0, valid = 1;
    if (s[i] == '0')
    {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
        {
            ++i;
        }
    }

    while (valid == 1 && s[i] != '\0')
    {
        answer = answer * 16;
        if (s[i] <= '9' && s[i] >= '0')
        {
            answer = answer + (s[i] - '0');
        }
        else
        {
            if (letter_to_num(s[i]) != 0)
            {
                answer = answer + letter_to_num(s[i]);
            }
            else
            {
                valid = 0;
            }
        }
        ++i;
    }
    if (valid == 0)
    {
        answer = 0;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    char *endp = NULL;
    char *test[] = {"F00", "bar", "0100", "0x1", "0XA", "0X0C0BE", "abcdef", "123456", "0x123456", "deadbeef", "zog_c"};
    unsigned int result;
    unsigned int check;
    size_t numtests = sizeof test / sizeof test[0];
    size_t thistest;
    for (thistest = 0; thistest < numtests; thistest++)
    {
        result = htoi(test[thistest]);
        check = (unsigned int)strtoul(test[thistest], &endp, 16);
        if ((*endp != '\0' && result == 0) || result == check)
        {
            printf("Testing %s. Correct. %u\n", test[thistest], result);
        }
        else
        {
            printf("Testing %s. Incorrect. %u\n", test[thistest], result);
        }
    }
    return 0;
}
