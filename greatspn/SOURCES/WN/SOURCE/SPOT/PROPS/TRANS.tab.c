#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)


#ifndef yyparse
#define yyparse    Transparse
#endif /* yyparse */

#ifndef yylex
#define yylex      Translex
#endif /* yylex */

#ifndef yyerror
#define yyerror    Transerror
#endif /* yyerror */

#ifndef yychar
#define yychar     Transchar
#endif /* yychar */

#ifndef yyval
#define yyval      Transval
#endif /* yyval */

#ifndef yylval
#define yylval     Translval
#endif /* yylval */

#ifndef yydebug
#define yydebug    Transdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    Transnerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  Transerrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      Translhs
#endif /* yylhs */

#ifndef yylen
#define yylen      Translen
#endif /* yylen */

#ifndef yydefred
#define yydefred   Transdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    Transdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   Transsindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   Transrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   Transgindex
#endif /* yygindex */

#ifndef yytable
#define yytable    Transtable
#endif /* yytable */

#ifndef yycheck
#define yycheck    Transcheck
#endif /* yycheck */

#ifndef yyname
#define yyname     Transname
#endif /* yyname */

#ifndef yyrule
#define yyrule     Transrule
#endif /* yyrule */
#define YYPREFIX "Trans"

#define YYPURE 0

#line 6 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"

/* .......... Declarations C ........*/
#pragma warning (disable:4786)
#include "../../../INCLUDE/const.h"
#include "../../../INCLUDE/SCONSSPOT.h"
#include "../../../INCLUDE/struct.h"
#include "../../../INCLUDE/SSTRUCTSPOT.h"
#include "../../../INCLUDE/var_ext.h"
#include "../../../INCLUDE/SVAR_EXTSPOT.h"
#include "../../../INCLUDE/macros.h"

/***************** Variables *******************/

static struct Token_Domains TD; 
extern char*   Ptr_Cur;
extern int     Lim_Pos;
int trans;
/**********************************************/

/**************** flex functions ************************/
extern int yylex();
extern FILE *yyin;
void yyerror(char *s){  printf("parsing error: %s\n", s); } 
int Transwrap(){ return (1); }
extern void   flush_buffer();
/*******************************************************/


/************** extern functions needed to compute local partitions *******/

extern void* ecalloc();
extern void* emalloc();
extern int GetIndObj();
extern PART_MAT_P GetMatRepOfTransDom();
extern PART_MAT_P GetMatRepOfPartTransDom();
extern TYPE_P** FindDisjParts2();


/************************************************************************/

int EXISTE_TRANS(char* id){
int i=0;
 
    while (i<ntr){
      if (strcmp(tabt[i].trans_name,id)==0) return i;
       i++;  
     }
    return NOT_PRESENT; 
} 

int EXISTE_FUNC(int t, char* f)
 {
   int i;

   for(i=0; i < tabt[t].comp_num;i++)
     if(strcmp(tabt[t].names[i],f)==0)
       return i;

   return  NOT_PRESENT; 

 }
          
#line 72 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { 	

  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 177 "TRANS.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IDENT 257
#define ID 258
#define NOT 259
#define EQ 260
#define MAX 261
#define D 262
#define MCOMP 263
#define OR 264
#define AND 265
#define YYERRCODE 256
static const short Translhs[] = {                        -1,
    1,    1,    5,    4,    4,    7,    6,    6,    8,    9,
   10,    0,    0,    3,    3,    3,    3,    3,    2,   11,
    2,   12,    2,   13,    2,
};
static const short Translen[] = {                         2,
    1,    2,    0,    4,    1,    0,    4,    1,    4,    0,
    0,    8,    0,    3,    3,    7,    7,    1,    4,    0,
    7,    0,    6,    0,    4,
};
static const short Transdefred[] = {                      0,
   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    2,    0,   22,    0,    0,   15,   14,   11,    0,    0,
   20,    0,   19,    0,    0,    0,    0,   25,    0,    0,
    0,    0,    0,   12,    9,    0,    0,    0,   23,    0,
    0,    0,   21,    0,   17,   16,    0,    4,    7,
};
static const short Transdgoto[] = {                       2,
   13,    8,    9,   41,   48,   47,   52,   20,    3,   36,
   39,   32,   10,
};
static const short Transsindex[] = {                   -247,
    0,    0,  -79,  -40, -253,  -23,  -40, -255,  -75, -243,
 -240,    0, -122, -237,  -19,  -40,  -40,  -35,  -17, -253,
    0,  -15,    0,  -14, -249,    0,    0,    0, -232, -243,
    0, -230,    0,  -11,  -10, -247,   -9,    0, -227,    0,
  -92,  -40,  -40,    0,    0,    0,   -7,   -8,    0,   -6,
   -4,   -2,    0, -230,    0,    0, -227,    0,    0,
};
static const short Transrindex[] = {                     38,
    0,    0,    0, -221,    0,    0, -221,  -38,    0,    0,
    0,    0,    0,    0,    0, -221, -221,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   38,    0,    0,    0,  -42,
    0, -221, -221,    0,    0,  -36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short Transgindex[] = {                      7,
   24,    0,   -3,   -5,    0,  -12,    0,   16,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 221
static const short Transtable[] = {                       7,
   23,    3,   18,   15,    8,   11,   12,    6,   16,   17,
    1,    4,   26,   27,   34,   35,   14,   18,   19,   21,
   24,   25,   29,   28,   31,   37,   33,   40,   42,   43,
   46,   45,   49,   53,   55,   54,   56,   13,   50,   51,
   24,   57,   44,   30,   59,   38,    0,    0,   58,    0,
    0,    0,    0,    0,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    5,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    6,
};
static const short Transcheck[] = {                      40,
  123,   44,   41,    7,   41,  259,  260,   44,  264,  265,
  258,   91,   16,   17,  264,  265,   40,   93,  262,  260,
  258,   41,   40,   59,   40,  258,   41,  258,   40,   40,
  258,   41,  125,   41,   41,   44,   41,    0,   42,   43,
  262,   44,   36,   20,   57,   30,   -1,   -1,   54,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,   -1,   -1,
  261,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"IDENT","ID","NOT","EQ","MAX","D","MCOMP","OR","AND","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : FORMULES",
"OP : EQ",
"OP : NOT EQ",
"$$1 :",
"VARS : ID $$1 ',' VARS",
"VARS : ID",
"$$2 :",
"COMP : ID $$2 ',' COMP",
"COMP : ID",
"STATIC : D '(' ID ')'",
"$$3 :",
"$$4 :",
"FORMULES : ID $$3 '[' ATOMIC ']' ';' $$4 FORMULES",
"FORMULES :",
"ATOMIC : EXPR AND ATOMIC",
"ATOMIC : EXPR OR ATOMIC",
"ATOMIC : '(' ATOMIC ')' AND '(' ATOMIC ')'",
"ATOMIC : '(' ATOMIC ')' OR '(' ATOMIC ')'",
"ATOMIC : EXPR",
"EXPR : MAX '(' ID ')'",
"$$5 :",
"EXPR : ID OP MCOMP '(' $$5 COMP ')'",
"$$6 :",
"EXPR : ID OP '{' $$6 VARS '}'",
"$$7 :",
"EXPR : $$7 STATIC OP STATIC",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 445 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
  
int guard_parser(FILE* f){

 char c; 
 int i=0; 
 char* ptr; 
 ptr=Ptr_Cur=(char*)malloc(STR_SIZE*sizeof(char));
     
 while((c=fgetc(f))!=EOF)  
   {
     Ptr_Cur[i]=c; 
     i++;
   }
 
   Ptr_Cur[i]='\0';
   Lim_Pos=(int)Ptr_Cur+strlen(Ptr_Cur);   

   
   i=yyparse();
   free(ptr);
  

  return i;
}















#line 434 "TRANS.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 102 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{yyval.j=EQOP;}
break;
case 2:
#line 102 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{yyval.j=NEQOP;}
break;
case 3:
#line 104 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
                       int Cl;
                       int v=GetIndObj(yystack.l_mark[0].s,MTCL,&Cl);
                       if(v==UNKNOWN) {
			 printf("\n The object :%s is not a valid color of the WN to be verfied \n",yystack.l_mark[0].s);
                         return(1);
                       }
                       TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
                       TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
		       TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;
                       free(yystack.l_mark[0].s);
                      }
break;
case 5:
#line 117 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
			int Cl;
			int v=GetIndObj(yystack.l_mark[0].s,MTCL,&Cl);
			if(v==UNKNOWN) {
			  printf("\n The object :%s is not a valid color of WN to be verfied \n",yystack.l_mark[0].s); 
			  return(1);
			}
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ; 
			                 
			free(yystack.l_mark[0].s);
			
                     }
break;
case 6:
#line 134 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		         int pos;
			 if((pos=EXISTE_FUNC(trans, yystack.l_mark[0].s))==NOT_PRESENT )
			   {
			     printf("\n Transition '%d' has no function named %s \n",trans,yystack.l_mark[0].s);
			     return(1);					  
			   }

			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=pos+1 ; TD.NbCl++ ;
			
                        }
break;
case 8:
#line 147 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
			 int pos;
			 if((pos=EXISTE_FUNC(trans, yystack.l_mark[0].s))==NOT_PRESENT )
			   {
			     printf("\n Transition '%d' has no function named %s \n",trans,yystack.l_mark[0].s);
			     return(1);					  
			   }
	             
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=pos+1 ; TD.NbCl++ ;
			
		   }
break;
case 9:
#line 162 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
                                 int pos;
				 if((pos=EXISTE_FUNC(trans, yystack.l_mark[-1].s))==NOT_PRESENT )
				   {
				     printf("\n Transition '%d' has nov function named %s \n",trans,yystack.l_mark[-1].s);
				     return(1);					  
				   }
				 else
				   {
			   
				     TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
				     TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
				     TD.Token[TD.NbCl]=pos+1 ;  TD.Domain[TD.NbCl]= tabt[trans].dominio[pos] ;
				     TD.NbCl++ ;
	                 	   }
                               }
break;
case 10:
#line 181 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{ 
                         if( (trans=EXISTE_TRANS(yystack.l_mark[0].s))==NOT_PRESENT ) 
                           {  
			     printf("\n Transition  '%s' does'nt exist \n",yystack.l_mark[0].s);
			     return(1);			     
			   }
			 free(yystack.l_mark[0].s);
                     }
break;
case 11:
#line 190 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
                      tabt[trans].dyn_guard=yystack.l_mark[-2].nd;
		      set_ref(tabt[trans].dyn_guard->PART_MAT,tabt[trans].dyn_guard->NbElPM);
                    }
break;
case 14:
#line 197 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		      yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
		      yyval.nd->op=ANDOP;
		      yyval.nd->type=NOTYPE;
		      yyval.nd->FONCT=NULL;
		      yyval.nd->filsg=yystack.l_mark[-2].nd;
		      yyval.nd->filsd=yystack.l_mark[0].nd;
		      
		      if(yystack.l_mark[-2].nd->PART_MAT==NULL && yystack.l_mark[0].nd->PART_MAT==NULL )
			{ yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
		      else
			if(yystack.l_mark[-2].nd->PART_MAT==NULL && yystack.l_mark[0].nd->PART_MAT!=NULL)
			  { yyval.nd->PART_MAT=yystack.l_mark[0].nd->PART_MAT; yyval.nd->NbElPM=yystack.l_mark[0].nd->NbElPM; }
			else 
			  if(yystack.l_mark[-2].nd->PART_MAT!=NULL && yystack.l_mark[0].nd->PART_MAT==NULL)
			     { yyval.nd->PART_MAT=yystack.l_mark[-2].nd->PART_MAT; yyval.nd->NbElPM=yystack.l_mark[-2].nd->NbElPM; }
			  else 
			    {
                               
			      PART_MAT_P var,Part=calloc(2,sizeof(PART_MAT));
                               				
			      Part[0].PART_MAT= yystack.l_mark[-2].nd->PART_MAT;
			      Part[0].NbElPM= yystack.l_mark[-2].nd->NbElPM ;  
			      Part[1].PART_MAT= yystack.l_mark[0].nd->PART_MAT;
			      Part[1].NbElPM= yystack.l_mark[0].nd->NbElPM ; 
			      var=FindDisjParts3(Part ,2);  
			      yyval.nd->PART_MAT=var->PART_MAT;
			      yyval.nd->NbElPM=var->NbElPM;
			    
                              /*free(var);*/
			      free(Part);
			      /* FreePartMAt($1->PART_MAT, $1->NbElPM);*/
			      /* FreePartMAt($3->PART_MAT, $3->NbElPM); */
			    }
                    }
break;
case 15:
#line 233 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		       yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
		       yyval.nd->op=OROP;
		       yyval.nd->type=NOTYPE;
		       yyval.nd->FONCT=NULL;
		       yyval.nd->filsg=yystack.l_mark[-2].nd;
		       yyval.nd->filsd=yystack.l_mark[0].nd;
		       
		       if(yystack.l_mark[-2].nd->PART_MAT==NULL && yystack.l_mark[0].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
		       else
			 if(yystack.l_mark[-2].nd->PART_MAT==NULL && yystack.l_mark[0].nd->PART_MAT!=NULL)
			   { yyval.nd->PART_MAT=yystack.l_mark[0].nd->PART_MAT; yyval.nd->NbElPM=yystack.l_mark[0].nd->NbElPM; }
			 else 
			   if(yystack.l_mark[-2].nd->PART_MAT!=NULL && yystack.l_mark[0].nd->PART_MAT==NULL)
			     { yyval.nd->PART_MAT=yystack.l_mark[-2].nd->PART_MAT;yyval.nd->NbElPM=yystack.l_mark[-2].nd->NbElPM;}
			   else 
			     { 
			       PART_MAT_P var,Part=calloc(2,sizeof(PART_MAT));
                               				
			       Part[0].PART_MAT= yystack.l_mark[-2].nd->PART_MAT;
			       Part[0].NbElPM= yystack.l_mark[-2].nd->NbElPM ;  
			       Part[1].PART_MAT= yystack.l_mark[0].nd->PART_MAT;
			       Part[1].NbElPM= yystack.l_mark[0].nd->NbElPM ; 
			       var=FindDisjParts3(Part ,2);  
			       yyval.nd->PART_MAT=var->PART_MAT;
			       yyval.nd->NbElPM=var->NbElPM;
			       /* free(var);*/
			       /* FreePartMAt($1->PART_MAT, $1->NbElPM);*/
			       /*FreePartMAt($3->PART_MAT, $3->NbElPM);*/
			       free(Part);
			     }
		       
		     }
break;
case 16:
#line 267 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		      yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
		      yyval.nd->op=ANDOP;
		      yyval.nd->type=NOTYPE;
		      yyval.nd->FONCT=NULL;
		      yyval.nd->filsg=yystack.l_mark[-5].nd;
		      yyval.nd->filsd=yystack.l_mark[-1].nd;
		      
		      if(yystack.l_mark[-5].nd->PART_MAT==NULL && yystack.l_mark[-1].nd->PART_MAT==NULL )
			{ yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
		      else
			if(yystack.l_mark[-5].nd->PART_MAT==NULL && yystack.l_mark[-1].nd->PART_MAT!=NULL)
			  { yyval.nd->PART_MAT=yystack.l_mark[-1].nd->PART_MAT; yyval.nd->NbElPM=yystack.l_mark[-1].nd->NbElPM; }
			else
			  if(yystack.l_mark[-5].nd->PART_MAT!=NULL && yystack.l_mark[-1].nd->PART_MAT==NULL)
			     { yyval.nd->PART_MAT=yystack.l_mark[-5].nd->PART_MAT; yyval.nd->NbElPM=yystack.l_mark[-5].nd->NbElPM; }
			  else
			    {
                               
			      PART_MAT_P var,Part=calloc(2,sizeof(PART_MAT));
                               				
			      Part[0].PART_MAT= yystack.l_mark[-5].nd->PART_MAT;
			      Part[0].NbElPM= yystack.l_mark[-5].nd->NbElPM ;
			      Part[1].PART_MAT= yystack.l_mark[-1].nd->PART_MAT;
			      Part[1].NbElPM= yystack.l_mark[-1].nd->NbElPM ;
			      var=FindDisjParts3(Part ,2);
			      yyval.nd->PART_MAT=var->PART_MAT;
			      yyval.nd->NbElPM=var->NbElPM;
			    
                              /*free(var);*/
			      free(Part);
			      /* FreePartMAt($1->PART_MAT, $1->NbElPM);*/
			      /* FreePartMAt($3->PART_MAT, $3->NbElPM);*/
			    }
                    }
break;
case 17:
#line 303 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		       yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
		       yyval.nd->op=OROP;
		       yyval.nd->type=NOTYPE;
		       yyval.nd->FONCT=NULL;
		       yyval.nd->filsg=yystack.l_mark[-5].nd;
		       yyval.nd->filsd=yystack.l_mark[-1].nd;
		       
		       if(yystack.l_mark[-5].nd->PART_MAT==NULL && yystack.l_mark[-1].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
		       else
			 if(yystack.l_mark[-5].nd->PART_MAT==NULL && yystack.l_mark[-1].nd->PART_MAT!=NULL)
			   { yyval.nd->PART_MAT=yystack.l_mark[-1].nd->PART_MAT; yyval.nd->NbElPM=yystack.l_mark[-1].nd->NbElPM; }
			 else
			   if(yystack.l_mark[-5].nd->PART_MAT!=NULL && yystack.l_mark[-1].nd->PART_MAT==NULL)
			     { yyval.nd->PART_MAT=yystack.l_mark[-5].nd->PART_MAT;yyval.nd->NbElPM=yystack.l_mark[-5].nd->NbElPM;}
			   else
			     {
			       PART_MAT_P var,Part=calloc(2,sizeof(PART_MAT));
                               				
			       Part[0].PART_MAT= yystack.l_mark[-5].nd->PART_MAT;
			       Part[0].NbElPM= yystack.l_mark[-5].nd->NbElPM ;
			       Part[1].PART_MAT= yystack.l_mark[-1].nd->PART_MAT;
			       Part[1].NbElPM= yystack.l_mark[-1].nd->NbElPM ;
			       var=FindDisjParts3(Part ,2);
			       yyval.nd->PART_MAT=var->PART_MAT;
			       yyval.nd->NbElPM=var->NbElPM;
			       /* free(var);*/
			       /* FreePartMAt($1->PART_MAT, $1->NbElPM);*/
			       /*FreePartMAt($3->PART_MAT, $3->NbElPM);*/
			       free(Part);
			     }
		       
		     }
break;
case 18:
#line 335 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{yyval.nd=yystack.l_mark[0].nd; }
break;
case 19:
#line 338 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		       
		       int pos;
		       if((pos=EXISTE_FUNC(trans, yystack.l_mark[-1].s))==NOT_PRESENT )
			 {
			   printf("\n Transition '%d' has no function named %s \n",trans,yystack.l_mark[-1].s);
			   return(1);					  
			 }
		       else
			 { 
			   yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			   yyval.nd->op=pos+1;
			   yyval.nd->type=MAXIMUM ;
			   yyval.nd->FONCT=NULL;
			   PART_MAT_P pm=GetMatRepOfPartTransDom(MTCL,tabt[trans].dominio[pos]); 
			   yyval.nd->PART_MAT=pm->PART_MAT;
			   yyval.nd->NbElPM=pm->NbElPM;
			   yyval.nd->filsg=yyval.nd->filsd=NULL;
			   free(pm);
			   free(yystack.l_mark[-1].s);
			 }
                     }
break;
case 20:
#line 361 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 21:
#line 362 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
			  int pos;
			  if((pos=EXISTE_FUNC(trans, yystack.l_mark[-6].s))==NOT_PRESENT )
			    {
			      printf("\n Transition '%d' has no function named %s \n",trans,yystack.l_mark[-6].s);
			      return(1);					  
			    }
			  free(yystack.l_mark[-6].s);
			  int i,cl =tabt[trans].dominio[pos];
			  for(i=0;i<TD.NbCl;i++)
                            if(tabt[trans].dominio[TD.Token[i]-1]!=cl) 
			      {
				printf("\n incompatible color domain in guard function of transition '%d' \n",trans);
				return(1);
			      }
			  
			  yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			    yyval.nd->op=yystack.l_mark[-5].j;
			    yyval.nd->type=MAX_COMP ;
			    yyval.nd->FONCT=NULL;
			    PART_MAT_P pm=GetMatRepOfPartTransDom(MTCL,tabt[trans].dominio[pos]); 
			    yyval.nd->PART_MAT=pm->PART_MAT;
			    yyval.nd->NbElPM=pm->NbElPM;
			    yyval.nd->filsg=yyval.nd->filsd=NULL;
                            yyval.nd->FONCT=(CToken_p)emalloc(sizeof(CToken));
                            yyval.nd->FONCT->mult=pos+1;
			   (yyval.nd->FONCT->tok_dom).Token=TD.Token;     
			   (yyval.nd->FONCT->tok_dom).Domain=NULL;
			   (yyval.nd->FONCT->tok_dom).NbCl=TD.NbCl;
			    yyval.nd->FONCT->next=NULL;
			    free(pm);
			    
                        }
break;
case 22:
#line 396 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{  TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 23:
#line 397 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
			int pos;
			if((pos=EXISTE_FUNC(trans, yystack.l_mark[-5].s))==NOT_PRESENT )
			  {
			    printf("\n Transition '%d' has no function named %s \n",trans,yystack.l_mark[-5].s);
			    return(1);					  
			  }
                        else
  		   	   { 
			    yyval.nd = (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			    yyval.nd->op=yystack.l_mark[-4].j;
			    yyval.nd->type=INCLUDED ;
			    yyval.nd->FONCT=(CToken_p)emalloc(sizeof(CToken));
			     yyval.nd->FONCT->mult=pos+1;
                            (yyval.nd->FONCT->tok_dom).Token=TD.Token;     
			    (yyval.nd->FONCT->tok_dom).Domain=TD.Domain;
			    (yyval.nd->FONCT->tok_dom).NbCl=TD.NbCl;
			    PART_MAT_P pm=GetMatRepOfTransDom(MTCL,TD); 
			    yyval.nd->PART_MAT=pm->PART_MAT;
			    yyval.nd->NbElPM=pm->NbElPM;
			    yyval.nd->filsg=yyval.nd->filsd=NULL;
			    free(pm);
			    free(yystack.l_mark[-5].s);
			   }
                       
                      }
break;
case 24:
#line 425 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 25:
#line 427 "/home/alinard/local/src/greatspn.back/SOURCES/WN/SOURCE/SPOT/PROPS/TRANS.y"
	{
		         yyval.nd = (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			 yyval.nd->op=yystack.l_mark[-1].j;
			 yyval.nd->type=DF;
			 yyval.nd->PART_MAT=NULL;
			 yyval.nd->NbElPM=NULL;
			 yyval.nd->FONCT=(CToken_p)emalloc(sizeof(CToken));
			 yyval.nd->filsg= yyval.nd->filsd=NULL;
			 yyval.nd->FONCT->mult=0;
			 (yyval.nd->FONCT->tok_dom).Token=TD.Token;     
			 (yyval.nd->FONCT->tok_dom).Domain=TD.Domain;
			 (yyval.nd->FONCT->tok_dom).NbCl=TD.NbCl;
			 yyval.nd->FONCT->next=NULL;
		        }
break;
#line 1014 "TRANS.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
