#include <stdio.h>

void swap(int *px,int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int main(int argc, char const *argv[])
{
    int x1=5;
    int x2=6;
    swap(&x1,&x2);
    printf("%d,%d",x1,x2);
    return 0;
}
