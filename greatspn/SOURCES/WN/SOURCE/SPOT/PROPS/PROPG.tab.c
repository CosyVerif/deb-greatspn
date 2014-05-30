#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define yyparse Propparse
#define yylex Proplex
#define yyerror Properror
#define yychar Propchar
#define yyval Propval
#define yylval Proplval
#define yydebug Propdebug
#define yynerrs Propnerrs
#define yyerrflag Properrflag
#define yyss Propss
#define yyssp Propssp
#define yyvs Propvs
#define yyvsp Propvsp
#define yylhs Proplhs
#define yylen Proplen
#define yydefred Propdefred
#define yydgoto Propdgoto
#define yysindex Propsindex
#define yyrindex Proprindex
#define yygindex Propgindex
#define yytable Proptable
#define yycheck Propcheck
#define yyname Propname
#define yyrule Proprule
#define yysslim Propsslim
#define yystacksize Propstacksize
#define YYPREFIX "Prop"
#line 6 "PROPG.y"

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

struct Token_Domains TD; 
char*   Ptr_Cur=NULL;
int     Lim_Pos=0;

/**********************************************/

/**************** flex functions ************************/
extern int yylex();
extern FILE *yyin;
void yyerror(char *s){  printf("parsing error: %s\n", s); } 
int Propwrap(){ return (1); }
extern void   flush_buffer();
/*******************************************************/


/************** extern functions needed to compute local partitions *******/
extern int get_obj_id();
extern void* ecalloc();
extern void* emalloc();
extern int initialize ();
extern int GetIndObj();
extern  TYPE_P** ComputeLocalPartitions();
extern  TYPE_P** FindDisjParts2();
extern PART_MAT_P FindDisjParts3();
extern char*** GetMatRepOfClObj();
extern int initialize () ;
extern void Afficher();
/************************************************************************/

int EXISTE_PLACE(char* id){
int i=0;
 
    while (i<npl){
      if (strcmp(tabp[i].place_name,id)==0) return i;
       i++;  
     }
    return NOT_PRESENT; 
} 
 
          
#line 63 "PROPG.y"
typedef union { 	

  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
} YYSTYPE;
#line 105 "PROPG.tab.c"
#define YYERRCODE 256
#define IDENT 257
#define ID 258
#define DL 259
#define PRS 260
#define INT 261
#define EDL 262
#define EPRS 263
#define EIN 264
#define NOT 265
#define EQ 266
#define LT 267
#define GT 268
#define OR 269
#define AND 270
#define DECOL 271
#define MINUS 272
#define IDEN 273
const short Proplhs[] = {                                        -1,
    4,    4,    4,    4,    4,    4,    4,    4,    4,    4,
   10,    9,   11,    9,    9,    9,   12,   12,   13,   13,
   14,    3,    1,   15,    1,   16,    1,    2,   17,    0,
    0,    8,    8,    7,    7,    7,    7,    7,    7,    5,
    5,    6,    6,
};
const short Proplen[] = {                                         2,
    1,    2,    1,    2,    2,    3,    1,    2,    2,    3,
    0,    4,    0,    4,    1,    1,    1,    1,    3,    1,
    0,    7,    3,    0,    5,    0,    4,    1,    0,    6,
    0,    3,    3,    1,    1,    1,    3,    3,    3,    1,
    3,    4,    1,
};
const short Propdefred[] = {                                      0,
    0,    0,    0,   43,   28,    0,    0,    0,   34,   36,
    0,    0,    0,   29,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   37,   23,    2,    0,    0,    4,
    8,   33,   41,    0,   38,    0,    0,   18,   17,    0,
    0,    0,    0,    0,    0,   42,    6,   10,   30,    0,
    0,    0,    0,    0,   27,   19,    0,   25,    0,    0,
    0,   14,   12,   22,
};
const short Propdgoto[] = {                                       2,
    8,    9,   10,   25,   11,   12,   13,   14,   55,   64,
   63,   50,   51,   15,   16,   17,   30,
};
const short Propsindex[] = {                                   -249,
  -47,    0,  -18,    0,    0,   -9,  -37, -240,    0,    0,
 -223, -217, -229,    0,  -71, -200, -207,  -37,  -22,    0,
 -252,    0, -205, -204, -247, -247,  -37,  -37,  -37,    4,
 -226, -203, -208,  -20,    0,    0,    0, -201, -199,    0,
    0,    0,    0, -211,    0, -215, -249,    0,    0,   22,
  -25, -208,    0,    0, -198,    0,    0,    0,    0, -226,
   29, -197,   28,   30,    0,    0, -185,    0, -208, -208,
   34,    0,    0,    0,
};
const short Proprindex[] = {                                     76,
    0,    0,  -85,    0,    0,    0,  -87,  -24,    0,    0,
    0,  -58,    0,    0,    0,    0,    0,  -87,    0, -239,
    0,    0,  -40,  -38,    0,    0,  -87,  -87,  -87,    0,
    0,    0,    0,    0,    0,    0,    0,  -35,  -33,    0,
    0,    0,    0,  -11,    0,   18,   76,    0,    0,  -15,
    0,    0,  -31,  -17,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
const short Propgindex[] = {                                     32,
   60,    0,    0,   68,   57,   58,    5,    0,  -44,    0,
    0,    0,   23,    0,    0,    0,    0,
};
#define YYTABLESIZE 258
const short Proptable[] = {                                       3,
   40,    7,    7,   21,    5,   21,    9,   62,    1,    4,
    3,   19,   13,   37,   38,   39,   35,   24,   35,   31,
   56,    7,   34,    6,   72,   73,   11,   26,   20,   39,
   18,   44,   45,   46,   35,   21,   22,   23,   24,   27,
   28,   21,   22,   23,   24,   48,   49,   39,   53,   54,
    3,   26,    7,   27,   28,    5,   32,    9,   28,   33,
   40,   41,   47,   52,   57,   60,   58,   61,   67,   65,
   68,   69,   71,   70,   74,   31,   32,   20,   59,   36,
   29,   42,   66,   43,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   26,
    0,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   40,   40,   40,   40,
    0,    0,    0,    0,    0,    0,    3,    3,    7,    7,
    5,    5,    5,    9,    9,    0,    3,    0,    7,    0,
    3,    5,    7,    9,    0,    5,   16,    9,    4,    5,
   35,   35,   35,   35,    0,   35,   27,   28,   27,   28,
   15,    0,    6,   39,   39,   39,   39,   39,
};
const short Propcheck[] = {                                      40,
   59,   40,   40,   91,   40,   91,   40,   52,  258,  257,
   58,    7,   44,  266,  267,  268,   41,  257,   41,   91,
   41,   40,   18,  271,   69,   70,   44,  267,  269,   41,
   40,   27,   28,   29,   59,  265,  266,  267,  268,  269,
  270,  265,  266,  267,  268,  272,  273,   59,  257,  258,
   91,  269,   91,  269,  270,   91,  257,   91,  270,  267,
  266,  266,   59,  267,  266,   44,  266,   93,   40,  268,
  268,   44,  258,   44,   41,    0,   59,   93,   47,   20,
   13,   25,   60,   26,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
   -1,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  257,  258,
  258,  257,  258,  257,  258,   -1,  267,   -1,  267,   -1,
  271,  267,  271,  267,   -1,  271,  268,  271,  257,  258,
  265,  266,  267,  268,   -1,  270,  269,  270,  269,  270,
  268,   -1,  271,  265,  266,  267,  268,  269,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 273
#if YYDEBUG
const char * const Propname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"IDENT","ID","DL","PRS","INT","EDL","EPRS","EIN","NOT","EQ","LT","GT","OR",
"AND","DECOL","MINUS","IDEN",
};
const char * const Proprule[] = {
"$accept : FORMULES",
"OP : EQ",
"OP : NOT EQ",
"OP : LT",
"OP : LT EQ",
"OP : NOT LT",
"OP : NOT LT EQ",
"OP : GT",
"OP : GT EQ",
"OP : NOT GT",
"OP : NOT GT EQ",
"$$1 :",
"VARS : ID $$1 ',' VARS",
"$$2 :",
"VARS : IDENT $$2 ',' VARS",
"VARS : ID",
"VARS : IDENT",
"PROJECTING : IDEN",
"PROJECTING : MINUS",
"PERS : PROJECTING ',' PERS",
"PERS : PROJECTING",
"$$3 :",
"PROJ : $$3 '[' PERS ']' '(' ID ')'",
"CONST : CONST OR CONST",
"$$4 :",
"CONST : $$4 IDENT LT VARS GT",
"$$5 :",
"CONST : $$5 LT VARS GT",
"FONC : ID",
"$$6 :",
"FORMULES : ID ':' ATOMIC $$6 ';' FORMULES",
"FORMULES :",
"ATOMIC : EXPR3 OP EXPR3",
"ATOMIC : EXPR1 OP EXPR1",
"EXPR3 : FONC",
"EXPR3 : CONST",
"EXPR3 : PROJ",
"EXPR3 : '(' EXPR3 ')'",
"EXPR3 : EXPR3 AND EXPR3",
"EXPR3 : EXPR3 OR EXPR3",
"EXPR1 : EXPR2",
"EXPR1 : EXPR2 OR EXPR2",
"EXPR2 : DECOL '(' EXPR3 ')'",
"EXPR2 : IDENT",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 518 "PROPG.y"

int prop_parser(FILE* f){

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

   if(i==0)
     {
       free(ptr);
       printf("\n File of atomic propositions is empty \n");
       exit(1);
     }
   
   i=yyparse();
   free(ptr);
   _CONS_=calloc(NbProp,sizeof(int)); 

  return i;
}















#line 370 "PROPG.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
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
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 93 "PROPG.y"
{yyval.j=EQOP;}
break;
case 2:
#line 93 "PROPG.y"
{yyval.j=NEQOP;}
break;
case 3:
#line 93 "PROPG.y"
{yyval.j=LOP;}
break;
case 4:
#line 93 "PROPG.y"
{yyval.j=LQOP;}
break;
case 5:
#line 93 "PROPG.y"
{yyval.j=NLOP;}
break;
case 6:
#line 93 "PROPG.y"
{yyval.j=NLQOP;}
break;
case 7:
#line 94 "PROPG.y"
{yyval.j=GOP;}
break;
case 8:
#line 94 "PROPG.y"
{yyval.j=GQOP;}
break;
case 9:
#line 94 "PROPG.y"
{yyval.j=NGOP;}
break;
case 10:
#line 94 "PROPG.y"
{yyval.j=NGQOP;}
break;
case 11:
#line 96 "PROPG.y"
{
                       int Cl;
                       int v=GetIndObj(yyvsp[0].s,MTCL,&Cl);
                       if(v==UNKNOWN) {
			 printf("\n The object :%s is not a valid color of WN to be verfied \n",yyvsp[0].s);
                         return(1);
                       }
                       TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
                       TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
		       TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;
                       free(yyvsp[0].s);
                      }
break;
case 13:
#line 109 "PROPG.y"
{
			int Cl;
			char* st=(char*)calloc(256,sizeof(char)) ;
			sprintf(st,"%d",yyvsp[0].j);
			int v=GetIndObj(st,MTCL,&Cl);
			if(v==UNKNOWN) {
			  printf("\n The object :%d is not a valid color of WN to be verfied \n",yyvsp[0].j); 
			  return(1);
			}
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;
			free(st);
                       }
break;
case 15:
#line 124 "PROPG.y"
{
			int Cl;
			int v=GetIndObj(yyvsp[0].s,MTCL,&Cl);
			if(v==UNKNOWN) {
			  printf("\n The object :%s is not a valid color of WN to be verfied \n",yyvsp[0].s); 
			  return(1);
			}
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;                   
			free(yyvsp[0].s);
                     }
break;
case 16:
#line 137 "PROPG.y"
{
			int Cl;
			char* st=(char*)calloc(256,sizeof(char)) ;
			sprintf(st,"%d",yyvsp[0].j);
			int v=GetIndObj(st,MTCL,&Cl);
			if(v==UNKNOWN) {
			  printf("\n  L'objet :%d n'est pas une couleur valide du réseau vérifié \n",yyvsp[0].j); 
			  return(1);
			}
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;
			free(st);
		  }
break;
case 17:
#line 152 "PROPG.y"
{
                           TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			   TD.Token[TD.NbCl]=PROJECT ; TD.NbCl++ ;   
			}
break;
case 18:
#line 156 "PROPG.y"
{ 
                           TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			   TD.Token[TD.NbCl]=ELIMINATE ; TD.NbCl++ ;  
			 }
break;
case 21:
#line 163 "PROPG.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL; }
break;
case 22:
#line 165 "PROPG.y"
{  
			int i;
		        if ((i=EXISTE_PLACE(yyvsp[-1].s))==NOT_PRESENT) 
			  {
			    printf("\n The place '%s' does'nt exist in the WN to be verified \n", yyvsp[-1].s);
			    return(1);
			  }
                        if(TD.NbCl==1 && TD.Token[0]==ELIMINATE) 
			  {
			    printf("\n The decolorisation function is not allowed for the place '%s'  \n ",yyvsp[-1].s);
			    return(1);
			  }
                        if(TD.NbCl!=tabp[i].comp_num)
			  {
			    printf("\n The projection function is not compatible with the place's '%s' color domain \n ",yyvsp[-1].s);
			    return (1);
			  }
		      
                        yyval.tk=(CToken_p)emalloc(sizeof(CToken));
		        yyval.tk->mult=i;
			(yyval.tk->tok_dom).Token=TD.Token;  
			(yyval.tk->tok_dom).Domain=NULL;   
			for(i=0,(yyval.tk->tok_dom).NbCl=0;i<TD.NbCl;i++)
			  if((yyval.tk->tok_dom).Token[i]==PROJECT)
			  {
			    (yyval.tk->tok_dom).Domain=realloc((yyval.tk->tok_dom).Domain,(((yyval.tk->tok_dom).NbCl)+1)*sizeof(int));
                            (yyval.tk->tok_dom).Domain[ (yyval.tk->tok_dom).NbCl]=tabp[yyval.tk->mult].dominio[i]; 
			    (yyval.tk->tok_dom).NbCl++;
			  }  
			yyval.tk->next=NULL; 
		     
		      }
break;
case 23:
#line 198 "PROPG.y"
{   int i; 
                                     CToken_p ptr=yyvsp[-2].tk;
                                     if((yyvsp[-2].tk->tok_dom).NbCl!=(yyvsp[0].tk->tok_dom).NbCl )
				       {
                                         
					 printf("\n One or more formulas express incompatibility between tokens color domains \n"); 
			                 return(1);  
				       }
				     for(i=0; i<(yyvsp[-2].tk->tok_dom).NbCl;i++)
				       if( (yyvsp[-2].tk->tok_dom).Domain[i]!= (yyvsp[0].tk->tok_dom).Domain[i] )
				       {
					 printf("\n One or more formulas express incompatibility between tokens color domains \n"); 
					 return(1);  
				       }
				     while(ptr->next!=NULL) ptr=ptr->next;
                                      ptr->next=yyvsp[0].tk; yyval.tk=yyvsp[-2].tk;
                                  }
break;
case 24:
#line 215 "PROPG.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 25:
#line 216 "PROPG.y"
{
		                     yyval.tk= (CToken_p)emalloc(sizeof(CToken));
				     if(yyvsp[-3].j==0)
				       {
					 printf(" Value '0', is not valid multiplicity for a token ");
					 return(1);
                                       }
				     yyval.tk->mult=yyvsp[-3].j;
				     (yyval.tk->tok_dom).Token=TD.Token;     
				     (yyval.tk->tok_dom).Domain=TD.Domain;
				     (yyval.tk->tok_dom).NbCl=TD.NbCl;
				     yyval.tk->next=NULL;
		                   }
break;
case 26:
#line 229 "PROPG.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 27:
#line 230 "PROPG.y"
{      
		                     yyval.tk=(CToken_p)emalloc(sizeof(CToken));
				     yyval.tk->mult=1;
				     (yyval.tk->tok_dom).Token=TD.Token;     
				     (yyval.tk->tok_dom).Domain=TD.Domain;
				     (yyval.tk->tok_dom).NbCl=TD.NbCl;
				     yyval.tk->next=NULL;
 
		            }
break;
case 28:
#line 241 "PROPG.y"
{
		      int i;
		      if ((i=EXISTE_PLACE(yyvsp[0].s))==NOT_PRESENT) {
			 
			printf("\n The place '%s' does'nt exist in the WN to be verified \n", yyvsp[0].s);
			return(1);
		       }
                        yyval.tk=(CToken_p)emalloc(sizeof(CToken));
		        yyval.tk->mult=i; 
			(yyval.tk->tok_dom).Token=NULL;   
			(yyval.tk->tok_dom).Domain=tabp[i].dominio;
			(yyval.tk->tok_dom).NbCl=tabp[i].comp_num;
			yyval.tk->next=NULL;
		        free(yyvsp[0].s);
                     }
break;
case 29:
#line 260 "PROPG.y"
{ TreeNode_p pt1=yyvsp[0].nd;
                                     int i;
				     for(i=0;i<NbProp;i++)
                                       if(strcmp(PROPOSITIONS[i].id,yyvsp[-2].s)==0 )
					 {
					   printf("\n There is a double declaration of the atomic proposition '%s' \n",yyvsp[-2].s);
					   return(1);
					 }
				     PROPOSITIONS=realloc(PROPOSITIONS,(NbProp+1)*sizeof(PropAtomic));
				     PROPOSITIONS[NbProp].id=yyvsp[-2].s;
         			     PROPOSITIONS[NbProp].prop=yyvsp[0].nd;
				     NbProp++;
				     
                                }
break;
case 32:
#line 275 "PROPG.y"
{
                                        int i;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=yyvsp[-1].j;
                                        yyval.nd->type=NOTYPE;
						                       
					if(((yyvsp[-2].nd->FONCT)->tok_dom).NbCl!=((yyvsp[0].nd->FONCT)->tok_dom).NbCl)
					  { 
					    printf("\n Some Sub-expressions's Color domains are incompatible  \n");
			                    return(1);     
					  }
				        
					for( i=0; i<((yyvsp[0].nd->FONCT)->tok_dom).NbCl;i++)
					  if( ((yyvsp[-2].nd->FONCT)->tok_dom).Domain[i]!= ((yyvsp[0].nd->FONCT)->tok_dom).Domain[i] )
					    {
					      printf("\n Some Sub-expressions's Color domains are incompatible  \n");
					      return(1);  
					    }
					TreeNode_p pt1,pt3;
                                        yyval.nd->FONCT=yyvsp[0].nd->FONCT;
					yyval.nd->filsg=pt1=yyvsp[-2].nd;
					yyval.nd->filsd=pt3=yyvsp[0].nd;
				
					if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
					else
					  if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL){yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
					  else 
					    if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL){ yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT; 
					                                                  yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM; }
					    else 
					      { 
						yyval.nd->PART_MAT=FindDisjParts2(((yyvsp[-2].nd->FONCT)->tok_dom).Domain,
									    ((yyvsp[-2].nd->FONCT)->tok_dom).NbCl,yyvsp[-2].nd->PART_MAT,
									     yyvsp[-2].nd->NbElPM, yyvsp[0].nd->PART_MAT,yyvsp[0].nd->NbElPM);
                                                yyval.nd->NbElPM=yyvsp[0].nd->NbElPM;
						yyvsp[0].nd->PART_MAT=NULL;
						yyvsp[0].nd->NbElPM=NULL;
					      }
						
		  }
break;
case 33:
#line 316 "PROPG.y"
{   
		                      int i;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=yyvsp[-1].j;
                                        yyval.nd->type=DEC;
					yyval.nd->filsg=yyvsp[-2].nd;
					yyval.nd->filsd=yyvsp[0].nd;
					if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
					else
					  if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL){ yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
					  else 
					    if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL){
					                                                  yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT; 
					                                                  yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM;
					    }
					    else 
					      {
						PART_MAT_P PM,PMS=calloc(2,sizeof(PART_MAT));
						TYPE NBELPMS=2;
						PMS[0].PART_MAT=yyvsp[-2].nd->PART_MAT;PMS[0].NbElPM=yyvsp[-2].nd->NbElPM;
						PMS[1].PART_MAT=yyvsp[0].nd->PART_MAT;PMS[1].NbElPM=yyvsp[0].nd->NbElPM;
						PM=FindDisjParts3(PMS, NBELPMS);
                                                yyval.nd->NbElPM=PM->NbElPM;
						yyval.nd->PART_MAT=PM->PART_MAT;
					       
						FreePartMAt(yyvsp[-2].nd->PART_MAT, yyvsp[-2].nd->NbElPM);
						FreePartMAt(yyvsp[0].nd->PART_MAT, yyvsp[0].nd->NbElPM);
						free(PMS);
					      }
		                    
		}
break;
case 34:
#line 349 "PROPG.y"
{  
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=NOP;
                                        yyval.nd->type=IDE;
					yyval.nd->FONCT=yyvsp[0].tk;
					yyval.nd->PART_MAT=NULL;
					yyval.nd->NbElPM=NULL;
					yyval.nd->filsg=yyval.nd->filsd=NULL;
                                      }
break;
case 35:
#line 358 "PROPG.y"
{ 
                                       yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                       yyval.nd->op=NOP;
                                       yyval.nd->type=TOK;
				       yyval.nd->FONCT=yyvsp[0].tk;
				       yyval.nd->filsg=yyval.nd->filsd=NULL; 
				       yyval.nd->PART_MAT=ComputeLocalPartitions( MTCL,(yyvsp[0].tk->tok_dom).Domain,(yyvsp[0].tk->tok_dom).NbCl,yyvsp[0].tk, &(yyval.nd->NbElPM));
				 
		                     }
break;
case 36:
#line 367 "PROPG.y"
{ 
                                       yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                       yyval.nd->op=NOP;
                                       yyval.nd->type=PRO;
				       yyval.nd->FONCT=yyvsp[0].tk;
        			       yyval.nd->PART_MAT=NULL;
				       yyval.nd->NbElPM=NULL;
				       yyval.nd->filsg=yyval.nd->filsd=NULL; 
                                    }
break;
case 37:
#line 376 "PROPG.y"
{yyval.nd=yyvsp[-1].nd; }
break;
case 38:
#line 377 "PROPG.y"
{
		                       int i;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=ANDOP;
                                        yyval.nd->type=NOTYPE;
					yyval.nd->FONCT=NULL;
					if(((yyvsp[-2].nd->FONCT)->tok_dom).NbCl!=((yyvsp[0].nd->FONCT)->tok_dom).NbCl)
					  {
					    printf("\n Some Sub-expressions's Color domains are incompatible  \n");
			                    return(1);     
					  }
					for( i=0; i<((yyvsp[-2].nd->FONCT)->tok_dom).NbCl;i++)
					  if( ((yyvsp[-2].nd->FONCT)->tok_dom).Domain[i]!= ((yyvsp[0].nd->FONCT)->tok_dom).Domain[i] )
					    {
					      printf("\n Some Sub-expressions's Color domains are incompatible  \n");
					      return(1);  
					    }
					TreeNode_p pt1,pt3;
					yyval.nd->FONCT=yyvsp[-2].nd->FONCT;
					yyval.nd->filsg=pt1=yyvsp[-2].nd;
					yyval.nd->filsd=pt3=yyvsp[0].nd;
					
					if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
					else
					  if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL){ yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
					  else 
					    if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL){ yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT;
					                                                  yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM; }
					    else 
					      { 
						yyval.nd->PART_MAT=FindDisjParts2(((yyvsp[-2].nd->FONCT)->tok_dom).Domain,
									    ((yyvsp[-2].nd->FONCT)->tok_dom).NbCl,yyvsp[-2].nd->PART_MAT,
									     yyvsp[-2].nd->NbElPM, yyvsp[0].nd->PART_MAT,yyvsp[0].nd->NbElPM);
                                                yyval.nd->NbElPM=yyvsp[0].nd->NbElPM;
						yyvsp[0].nd->PART_MAT=NULL;
						yyvsp[0].nd->NbElPM=NULL;
					      }
				   
		                    }
break;
case 39:
#line 416 "PROPG.y"
{  
		                        int i;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=OROP;
                                        yyval.nd->type=NOTYPE;
					if(((yyvsp[-2].nd->FONCT)->tok_dom).NbCl!=((yyvsp[0].nd->FONCT)->tok_dom).NbCl)
					  {
					    printf("\n Some Sub-expressions's Color domains are incompatible  \n");
			                    return(1);     
					  }
					for( i=0; i<((yyvsp[-2].nd->FONCT)->tok_dom).NbCl;i++)
					  if( ((yyvsp[-2].nd->FONCT)->tok_dom).Domain[i]!= ((yyvsp[0].nd->FONCT)->tok_dom).Domain[i] )
					    {
					      printf("\n Some Sub-expressions's Color domains are incompatible  \n");
					      return(1);  
					    }
					yyval.nd->FONCT=yyvsp[-2].nd->FONCT;
					yyval.nd->filsg=yyvsp[-2].nd;
					yyval.nd->filsd=yyvsp[0].nd;
					if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
					else
					  if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL){ yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
					  else 
					    if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL){ yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT; 
					                                                  yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM; }
					    else 
					      {
					        yyval.nd->PART_MAT=FindDisjParts2(((yyvsp[-2].nd->FONCT)->tok_dom).Domain,
									    ((yyvsp[-2].nd->FONCT)->tok_dom).NbCl,yyvsp[-2].nd->PART_MAT,
									     yyvsp[-2].nd->NbElPM, yyvsp[0].nd->PART_MAT,yyvsp[0].nd->NbElPM);
                                                yyval.nd->NbElPM=yyvsp[0].nd->NbElPM;
						yyvsp[0].nd->PART_MAT=NULL;
						yyvsp[0].nd->NbElPM=NULL;
					      }
		                    }
break;
case 40:
#line 452 "PROPG.y"
{ yyval.nd=yyvsp[0].nd;}
break;
case 41:
#line 453 "PROPG.y"
{
		                     int i;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=OROP;
                                        yyval.nd->type=NOTYPE;
					yyval.nd->FONCT=NULL;
					yyval.nd->filsg=yyvsp[-2].nd;
					yyval.nd->filsd=yyvsp[0].nd;
					if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL ) 
					  { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
					else
					  if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL)
					    { yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
					  else 
					    if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL)
					      {
						yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT; 
						yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM;
					      }
					    else 
					      {
						PART_MAT_P PM,PMS=calloc(2,sizeof(PART_MAT));
						TYPE NBELPMS=2;
						PMS[0].PART_MAT=yyvsp[-2].nd->PART_MAT;PMS[0].NbElPM=yyvsp[-2].nd->NbElPM;
						PMS[1].PART_MAT=yyvsp[0].nd->PART_MAT;PMS[1].NbElPM=yyvsp[0].nd->NbElPM;
						PM=FindDisjParts3(PMS, NBELPMS);
                                                yyval.nd->NbElPM=PM->NbElPM;
						yyval.nd->PART_MAT=PM->PART_MAT;
					       
						FreePartMAt(yyvsp[-2].nd->PART_MAT, yyvsp[-2].nd->NbElPM);
						FreePartMAt(yyvsp[0].nd->PART_MAT, yyvsp[0].nd->NbElPM);
						free(PMS);
					      }
		                    

                     		  }
break;
case 42:
#line 490 "PROPG.y"
{
                                        int i;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=DEC;
                                        yyval.nd->type=NOTYPE;
					yyval.nd->FONCT=NULL;
					yyval.nd->filsg=NULL;
					yyval.nd->filsd=yyvsp[-1].nd;
					yyval.nd->NbElPM=yyvsp[-1].nd->NbElPM; 
					yyval.nd->PART_MAT=yyvsp[-1].nd->PART_MAT;
                                    }
break;
case 43:
#line 501 "PROPG.y"
{  int i;
		                        CToken_p tk;
		                        yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
                                        yyval.nd->op=NOP;
                                        yyval.nd->type=IDF;
					tk=(CToken_p)emalloc(sizeof(CToken));
					tk->mult=yyvsp[0].j;
					tk->next=NULL;
					yyval.nd->FONCT=tk;
					yyval.nd->filsg=NULL;
					yyval.nd->filsd=NULL;
					yyval.nd->NbElPM=NULL ;
					yyval.nd->PART_MAT=NULL;
                                    }
break;
#line 1084 "PROPG.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
