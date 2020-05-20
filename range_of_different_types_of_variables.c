#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    printf("the size of a char is %d\n", CHAR_BIT);
    printf("the min value of the signed char is %d\n", SCHAR_MIN);
    printf("the max value of the signed char is %d\n", SCHAR_MAX);
    printf("the max value of the unsigned char is %d\n", UCHAR_MAX);
    printf("the min value of the short int is %d\n", SHRT_MIN);
    printf("the max value of the short int is %d\n", SIZE_MAX);
    printf("the max value of the int is %d\n", INT_MAX);
    printf("the min value of the int is %d\n", INT_MIN);
    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);

    printf("The minimum value of LONG = %ld\n", LONG_MIN);
    printf("The maximum value of LONG = %ld\n", LONG_MAX);
    return 0;
}
