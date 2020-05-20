#include <stdio.h>

static char daytab[2][13] = {
    {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
    int leap, i;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int day, char *m, char *d)
{
    int leap, i;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1;day >= daytab[leap][i];i++)
        day -= daytab[leap][i];
    *m = i;
    *d = day;
}

int main(int argc, char const *argv[])
{
    printf("%d\n",day_of_year(2020,7,18));
    char m,d;
    month_day(2020,200,&m,&d);
    printf("%d,%d",m,d);
    return 0;
}
