/* print line length bigger than 80 */
#include <stdio.h>
#define MAXLINE 1000
#define threshold 5

int getline(char s[], int limit)
{
    int c, j = 0,i;
    for (i =0;i<=MAXLINE;i++)
    {
        s[i] = '0';
    }
    while ((c = getchar()) != EOF && c != '\n')
    {
        s[j] = c;
        j++;
    }
    if (c == '\n')
    {
        s[j] = c;
        j++;
    }
    return j;
}

int add(char from[], char store[], int current)
{
    int i = 0;
    ++current;
    while (from[i] != '0')
    {
        store[current] = from[i];
        ++i;
        ++current;
    }
    return current;
}

int main(int argc, char const *argv[])
{
    int i, len = 0, current = -1;
    char line[MAXLINE];
    char store[MAXLINE];
    for (i = 0; i <= MAXLINE; ++i)
    {
        line[i] = '0';
        store[i] = '0';
    }
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (len > threshold)
        {
            current = add(line, store, current);
        }
    }

    i = 0;
    while (i <= MAXLINE)
    {
        if (store[i] != '0')
        {
            printf("%c", store[i]);
        }
        ++i;
    }
    return 0;
}
