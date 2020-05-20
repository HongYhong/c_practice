#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int limit);
int strrindex(char s[], char t[]);

int main(int argc, char const *argv[])
{
    int len;
    char line[MAXLINE];
    char pattern[] = "ould";
    while ((len = getline2(line, MAXLINE)) > 0)
    {
        printf("%d",strrindex(line, pattern));
    }
    return 0;
}