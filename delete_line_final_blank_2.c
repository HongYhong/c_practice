#include <stdio.h>
#define MAXLINE 1000

int delete(char s[],int pos)
{
    --pos;
    while (s[pos] == '\n'||s[pos] == '\t' ||s[pos] ==' ')
    {
         s[pos] = '0';
         if (pos == 0)
         {
             --pos;
             break;
         }
         --pos;
    }
    s[++pos] = '\n';
    ++pos;
}

int getline(char s[],int limit)
{
    int i,c,pos=0;
    for (i=0;i<=MAXLINE;++i)
    {
        s[i] = '0';
    }
    while((c = getchar())!=EOF)
    {
        s[pos] = c;
        ++ pos;
        if (c == '\n')
        {
            break;
        }
    }
    if (pos > 0)
    {
         pos = delete(s,pos);
    }
    return pos;     /* pos is the next position of \n */
}

int add(char from[],char store[],int current)
{
    int i=0;
    ++ current;
    while(from[i] != '0' )
    {
        store[current] = from[i];
        ++current;
        ++i;
    }
    return current;
}

int main(int argc, char const *argv[])
{
    int i,len,current=-1;
    char line[MAXLINE];    /* current line */
    char store[MAXLINE];  /* store all lines for printing */
    for (i = 0;i<=MAXLINE;++i)
    {
        store[i] = '0';
    }
    while((len = getline(line,MAXLINE))>0)
    {
        if (line[0]=='\n')
        {
            continue;
        }
        
        current = add(line,store,current);
    }
    
    for(i=0;i<=MAXLINE;i++)
    {
        printf("%c,",store[i]);
       
    }   
        return 0;
}
