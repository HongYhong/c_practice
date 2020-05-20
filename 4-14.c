#include<stdio.h>
#define swap(t,x,y) t z=x;x=y;y=z

int main(int argc, char const *argv[])
{
    int x1=1;
    int x2=2;
    swap(int,x1,x2);
    printf("%d,%d",x1,x2);
    return 0;
}
