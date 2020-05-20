#include <stdio.h>
#define MAXLINE 1000

int getline2(char line[], int limit);
int stringmatch(char line[], char pattern[]);

int main(int argc, char const *argv[])
{
    int len;
    char line[MAXLINE];
    char pattern[] = "ould";
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (stringmatch(line, pattern))
        {
            printf("%s", line);
        }
    }
    return 0;
}