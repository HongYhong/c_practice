#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    double atof2(char s[]);
    int atoi2(char s[]);
    char *test[] = {"-3.14159","5.55","-46","   11.1314","6e-6"};
    char *test2[] = {"14","18","-19","26"};
    size_t numoftest = sizeof test / sizeof test[0];
    size_t thistest;
    for (thistest = 0;thistest < numoftest ;thistest++)
    {
        printf("test %d \"%s\"  result:%lf\n",thistest,test[thistest],atof2(test[thistest]));
    }
    numoftest = sizeof test2 / sizeof test2[0];
    for (thistest = 0;thistest < numoftest;thistest++)
    {
        printf("test %d \"%s\"   result:%d\n",thistest,test2[thistest],atoi2(test2[thistest]));
    }
    return 0;
}
