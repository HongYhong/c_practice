#define NUMBER '0'
#define INDENTIFIER '1'
#define MAXVAR 1000
#define ENDSTRING '2'
#define MAX_ID_LEN 1000
struct varType
{
    char name[MAX_ID_LEN];
    double val;
};
void push(double);
double pop(void);
int getop2(char []);
int getch2(void);
void ungetch2(int);
void clearstack(struct varType var[]);
void showtop(void);
void copytop(void);
void swaptop(void);
struct varType last; /* store the last variable's name and value.*/
void dealwithname(char s[],struct varType var[]);
void dealwithvar(char s[],struct varType var[]);


int pos;


