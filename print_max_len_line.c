#include <stdio.h>
#define MAXLEN 1000
int getline(char s[],int limit)
{
    int c,j=0;
    while((c=getchar())!=EOF && c != '\n')
    {
        s[j]=c;
        j++;
    }
    return j;
}

void copy(char from[],char to[])
{
    int i=0;
    while(from[i]!='0')
    {
        to[i] = from[i];
        ++i;
    }
}

int main(int argc, char const *argv[])
{
    int i,max=0,len;
    char longestline[MAXLEN];
    char line[MAXLEN];
    for (i=0;i<=MAXLEN;i++)
    {
        line[i]='0';
        longestline[i]='0';
    }

    while((len =getline(line,MAXLEN))>0)
    {
        if(len>max)
        {
            max = len;
            copy(line,longestline);
        }
    }
    
    
    for (i =0 ;i<max;i++)
    {
        printf("%c",longestline[i]);
        
    }
    printf("\n%d",max);
    return 0;
}

