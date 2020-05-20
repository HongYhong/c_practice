#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int a;
    srand((unsigned)time(NULL));
    a = rand();
    printf("%d",a);
    return 0;
}
