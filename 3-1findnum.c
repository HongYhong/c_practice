#include <stdio.h>
#include <time.h>
#define MAXELEMENTS 1000

int binsearch(int x,int v[],int n)
{
    int higher,lower,mid;
    lower = 0;
    higher = n - 1;
    while (higher >= lower)
    {
        mid = (higher + lower) / 2;
        if (x > v[mid])
        {
            lower = mid + 1;
        }
        else if (x < v[mid])
        {
            higher = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binsearch2(int x,int v[],int n)
{
    int higher,lower,mid;
    lower = 0;
    higher = n - 1;
    while (higher >= lower && v[mid] != x)
    {
        mid = (higher + lower ) /2;
        if (x > v[mid])
        {
            lower = mid + 1;
        }
        else
        {
            higher = mid - 1;
        }
    }
    if (v[mid] == x)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    int v[MAXELEMENTS],i,result1,result2;
    clock_t time;
    for (i = 0; i < MAXELEMENTS ; ++i)
    {
        v[i] = i;
    }

    for (i = 0,time = clock();i <= 100000000 ; ++i)
    {
        result1 = binsearch(20,v,MAXELEMENTS);
    }
    time = clock() - time;
    if (result1 == -1)
    {
        printf("there is no elements.\ntime taken:%lu",time);
    }
    else
    {
        printf("the index of the element is %d\ntime taken:%ul (%ul seconds)\n",result1,(unsigned long)time,(unsigned long)time / CLOCKS_PER_SEC);
    }
    


        for (i = 0,time = clock();i <= 100000000 ; ++i)
    {
        result2 = binsearch2(20,v,MAXELEMENTS);
    }
    time = clock() - time;
    if (result2 == -1)
    {
        printf("there is no elements.\ntime taken:%lu\n",time);
    }
    else
    {
        printf("the index of the element is %d \ntime taken:%ul (%ul seconds)",result2,(unsigned long)time,(unsigned long)time / CLOCKS_PER_SEC);
    }
    return 0;
}
