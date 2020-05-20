#include <stdio.h>

void escape(char s[],char t[])
{
    int i=0,j=0;
    while(t[i] != '\0')
    {
        switch (t[i])
        {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            i++;
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            i++;
            break;
        default:
            s[j++] = t[i++];
            break;
        }
    }
}

void unescape(char s[],char t[])
{
    int i = 0,j = 0;
    while (t[i] != '\0')
    {
        switch (t[i])
        {
        case '\\':
            switch (t[++i])
            {
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
            default:
                break;
            }
            ++i;
            break;
        
        default:
            s[j++] = t[i++]; 
            break;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int i;
    char s[1000];
    for (i=0;i<=999;i++)
    {
        s[i] = '\0';
    }
    char t1[] = {"sdasd213\tsada\nsd"} ;
    char t2[] = "123\\tqwe123\\nrty";
    unescape(s,t2);
    printf("%s\n",t2);
    printf("%s\n",s);
    return 0;
}
