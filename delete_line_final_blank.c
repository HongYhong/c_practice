/* delete blanks and tabs at the final of lines and total blank line */
#include <stdio.h>
#define MAXLINE 1000

int delete_blanks_tabs_at_final(char s[],int len)
{
    while (s[len] == ' '|| s[len] == '\t'||s[len]=='\n')
    {
        s[len] = '0';
        --len;
    }
    s[++len] = '\n';
    return len;
}

int getline(char s[], int limit)
{
    int c,i,j=0;
    for (i = 0 ;i <=MAXLINE ;i++ )
    {
        s[i] = '0';
    }
    while((c=getchar())!=EOF && c != '\n')
    {
        s[j] = c;
        j++;
    }
    if (c == '\n')
    {
        s[j] = '\n';
        if(j==0)
        {
            j++;
        }
    }
    if (j > 0)
    {
        j = delete_blanks_tabs_at_final(s,j)+1;
    }
    return j;
}



int add(char from[],char store[],int current)
{
    int i=0;
    ++current;
    while(from[i] != '0')
    {
        if (from[i]=='\n' && i==0)
        {
            break;
        }
        store[current] = from [i];
        ++ i;
        ++ current;
    }
    return current;
}


int main(int argc, char const *argv[])
{
    int current = -1,i,len;
    char line[MAXLINE];
    char store[MAXLINE];
    for (i =0;i<=MAXLINE;i++)
    {
        store[i]='0';
    }
    while((len = getline(line,MAXLINE))>0)
    {
        if (len ==1 && line[0]=='\n')
        {
            continue;
        }
        current = add(line,store,current);
    }
    for (i=0;i<=MAXLINE;i++)
    {
        printf("%c,",store[i]);
    }
    return 0;
}
