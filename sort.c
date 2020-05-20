#include <stdio.h>
#include <string.h>

#define MAXLINENUM 5000
#define MAXLEN 100
#define MAXNUM 1000

int readlines(char *linepointer[], int limit);
void writelines(char *linepointer[], int nlines);
void qsort(char *linepointer[], int left, int right);
char *linepointer[MAXLINENUM];
char lines[MAXNUM][MAXLEN];

int main(int argc, char const *argv[])
{

    int nlines;
    if ((nlines = readlines(linepointer, MAXLINENUM)) >= 0)
    {
        qsort(linepointer, 0, nlines - 1);
        writelines(linepointer, nlines);
        return 0;
    }
    else
    {
        printf("error:input to big to sort.");
        return 1;
    }
}

int getline(char *line, int lenlimit);
void strcpy2(char *s, char *t);
char *alloc(int len);

int readlines(char *linepointer[], int limit)
{
    int nlines = 0;
    char line[MAXLEN];
    char *temp;
    int len;
    while ((len = getline(line, MAXLEN)) > 0 && --limit > 0)
    {
        line[len - 1] = '\0';
        temp = alloc(len);
        strcpy2(temp, line);
        linepointer[nlines++] = temp;
    }
    if (limit != 0)
        return nlines;
    else
        return -1;
}

int readlines2(char lines[MAXNUM][MAXLEN], int limit)
{
    int len, nlines;
    nlines = 0;
    while ((len = getline(lines[nlines], MAXLEN)) > 0)
    {
        if (limit < nlines)
            return -1;
        else
            lines[nlines++][len - 1] = '\0';
        return nlines;
    }
}

#define ALLOCSIZE 100
static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char *alloc(int len)
{
    if (allocbuff + ALLOCSIZE - allocp >= len)
    {
        allocp += len;
        return allocp - len;
    }
    else
    {
        return 0;
    }
}

int getline(char *line, int lenlimit)
{
    int c, i = 0;
    while (--lenlimit && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

void writelines(char *linepointer[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", linepointer[i]);
}

int strcmp2(char *s, char *t);
void swap(char *linepointer[], int i, int j);

void qsort(char *linepointer[], int left, int right)
{
    int i;
    if (left >= right)
        return;
    swap(linepointer, left, (left + right) / 2);
    int last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp2(linepointer[left], linepointer[i]) > 0)
            swap(linepointer, ++last, i);
    swap(linepointer, left, last);
    qsort(linepointer, left, last - 1);
    qsort(linepointer, last + 1, right);
}

void swap(char *linepointer[], int i, int j)
{
    char *temp;
    temp = linepointer[i];
    linepointer[i] = linepointer[j];
    linepointer[j] = temp;
}

int strcmp2(char *s, char *t)
{
    while (*s == *t && *s != '\0')
    {
        s++;
        t++;
    }
    if (*s)
        return *s - *t;
    return 0;
}

void strcpy2(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}