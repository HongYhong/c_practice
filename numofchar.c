#include <stdio.h>

int main(int argc, char const *argv[])
{
    long nc;
    nc = 0 ;
    while (getchar()!= EOF)
        nc++;
    printf("the number of characters is %ld\n",nc);
    
    return 0;
}
