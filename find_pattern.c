#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline2(char *line,int limit)
{
    int c,i=0;
    while (--limit && (c = getchar())!= EOF && c != '\n')    
        line[i++] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

int main(int argc, char const *argv[])
{
    char line[MAXLINE],c;
    int len;
    int number = 0, except = 0 ;
    int found = 0,linenumber=0;
    while (--argc && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find:unknown option %c\n",c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("usage:find -x -n pattern\n");
    else
    {
        while(getline2(line,MAXLINE)>0)
            {
                linenumber++;
                if ((strstr(line,*argv) != NULL) != except)
                    {
                        if (number)
                            printf("%d:",linenumber);
                        printf("%s",line);
                        found++;
                    }
            }
    }
    return found;
}
