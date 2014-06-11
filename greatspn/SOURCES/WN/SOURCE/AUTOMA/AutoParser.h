#define NUMBER 257
#define STRING 258
typedef union{
int num;
char var[255];
} YYSTYPE;
extern YYSTYPE kklval;
