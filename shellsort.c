#include <stdio.h>

void shellsort(int v[],int n)
{
    int i,j,gap,temp;
    for (gap = n/2;gap >= 1;gap/=2)
        for (i = gap ;i <= n-1;i++)
            for (j = i - gap;j >= 0 && v[j] > v[j + gap];j -= gap)
            {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp; 
            }
}

int main(int argc, char const *argv[])
{
    int i;
    int v[] = {1,5,0,2,3,4,6,8,7,9};
    shellsort(v,10);
    for (i=0;i<=9;i++)
    {
        printf("%d,",v[i]);
    }
    return 0;
}
