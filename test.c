#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    char buffer[20] = "10379cend$3";
    char *pmessage = "now is the time";
    char *stop;
    char s[20];
    int x = 1515;
    int y = 3;
    int z = 0b1011;
    int t = 0b101;
    printf("%s\n",buffer);
    printf("%d\n", strtol(buffer, &stop, 2));
    printf("%s\n", stop);
    y = (x >> 2)<<2;
    printf("%d\n",y);
    printf("%d\n",t & z);
    printf("stdout\n");
    fprintf(stdout, "stdout\n");
    fprintf(stderr, "stderr\n");
    return 0;
}