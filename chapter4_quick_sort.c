#include <stdio.h>

void swap(char v[],int i,int j);

void qsort(char v[],int left,int right)
{
    int last,i;   /*last: the last position of the first group*/
    if (left >= right)
        return;
    last = left;
    for (i = left+1 ;i<=right;i++)
    {
        if (v[left] > v[i])
            swap(v,++last,i);
    }
    swap(v,left,last);
    qsort(v,last+1,right);
    qsort(v,left,last-1);
}

void swap(char v[],int i,int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp; 
}

int main(int argc, char const *argv[])
{
    int i;
    char test[]= {4,1,3,5,9,2,5};
    qsort(test,0,6);
    for (i = 0;i<=6;i++)
    {
        printf("%d,",test[i]);
    }
    return 0;
}
