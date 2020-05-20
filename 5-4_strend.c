#include <stdio.h>
#include <string.h>
#include <stddef.h>

int strend(char *s, char *t)
{
    int i, j;
    for (i = strlen(s) - strlen(t) , j = 0; *(t + j) && *(s + i) == *(t + j); i++, j++)
        ;
    if (*(t + j) == '\0')
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    char *test[] = {"abc","bdbd","bc","dbd","c","bd","d"};
    size_t numoftest = sizeof test / sizeof test[0];
    size_t thistest,tailtest;
    for (thistest = 0;thistest < numoftest;thistest++ )
    {
        for (tailtest = 0;tailtest < numoftest;tailtest++)
        {
            printf("test:[%s],tailltest[%s],result:%d\n",test[thistest],test[tailtest],strend(test[thistest],test[tailtest]));
        }
    }
    return 0;
}
