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
#define yyparse Indexparse
#define yylex Indexlex
#define yyerror Indexerror
#define yychar Indexchar
#define yyval Indexval
#define yylval Indexlval
#define yydebug Indexdebug
#define yynerrs Indexnerrs
#define yyerrflag Indexerrflag
#define yyss Indexss
#define yyssp Indexssp
#define yyvs Indexvs
#define yyvsp Indexvsp
#define yylhs Indexlhs
#define yylen Indexlen
#define yydefred Indexdefred
#define yydgoto Indexdgoto
#define yysindex Indexsindex
#define yyrindex Indexrindex
#define yygindex Indexgindex
#define yytable Indextable
#define yycheck Indexcheck
#define yyname Indexname
#define yyrule Indexrule
#define yysslim Indexsslim
#define yystacksize Indexstacksize
#define YYPREFIX "Index"
#line 2 "./src/srcdsrg/IndexDsrg.y"

/* .......... Declarations C ........*/
#pragma warning (disable:4786)
#include "const.h"
#include "SCONSSPOT.h"
#include "struct.h"
#include "SSTRUCTSPOT.h"
#include "var_ext.h"
#include "SVAR_EXTSPOT.h"
#include "macros.h"

/***************** Variables *******************/

struct Token_Domains TD; 
char*   Ptr_Cur_index=NULL;
int     Lim_Pos_index=0;
int     ind=0;
/**********************************************/

/**************** flex functions ************************/
extern int yylex();
extern FILE *yyin;
void yyerror(char *s){  printf("parsing error: %s\n", s); } 
int Indexwrap(){ return (1); }
extern void   flush_buffer_index();
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
extern PART_MAT_P GetMatRepOfTransDom(); 
extern char*** GetMatRepOfClObj();
extern int initialize () ;
extern void Afficher();
extern int EXISTE_PLACE();
extern int EXISTE_TRANS();
extern int EXISTE_FUNC(int t, char* f);
/************************************************************************/

int
error_color(char* s){
  printf("\n The object %s is not a valid color of the treated WN  \n",s);
  return(1); 
}
int 
error_dec(char* s){
  printf("\n The decolorisation function is not ");
  printf(" allowed for the place '%s'  \n ",s);
  return(1);
} 
int
error_proj(char* s){
  printf("\n The projection function is not ");
  printf(" compatible with the place's '%s' color domain \n ",s);
  return (1);
} 
int 
error_place(char* s){
  printf("\n Place %s does'nt exist in the treated WN \n", s);
  return(1);
}  
int 
error_trans(char* s){
  printf("\n Transition %s does'nt exist in the treated WN \n", s);
  return(1);
} 
int
error_exp(){
  printf("\n Some Sub-expressions's Color domains are incompatible\n");
  return(1);     
} 

int 
error_trans_fun(char* tr, char* fc){
  printf("\n Transition %s has no function named %s \n",tr,fc);
  return(1);	  
} 
                
#line 91 "./src/srcdsrg/IndexDsrg.y"
typedef union { 	
  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
  struct Perf_Index* Pd;
} YYSTYPE;
#line 137 "IndexDsrg.tab.c"
#define YYERRCODE 256
#define IDENT 257
#define ID 258
#define EQ 259
#define LT 260
#define GT 261
#define MINUS 262
#define NBORDTOK 263
#define NBEVENT 264
#define IDEN 265
#define OR 266
#define AND 267
const short Indexlhs[] = {                                        -1,
    6,    6,    6,    7,    8,   11,   10,   10,   12,    4,
   13,   13,   14,   14,   15,    1,    5,   16,    0,    0,
   17,    9,   18,    9,    9,    9,    2,   19,    3,
};
const short Indexlen[] = {                                         2,
    1,    1,    1,    1,    1,    0,    4,    1,    0,    4,
    1,    1,    3,    1,    0,    4,    1,    0,    4,    0,
    0,    7,    0,    7,    4,    4,    3,    0,    6,
};
const short Indexdefred[] = {                                      0,
    4,    5,    0,    0,    0,   18,    0,    0,    0,    0,
    0,    0,    0,    0,   19,   21,   23,   15,    0,   17,
   22,    0,    0,    0,   24,    1,    2,    3,    9,    0,
    0,   27,    0,   12,   11,    0,    0,   28,    0,    0,
   16,    0,    0,    0,   13,    0,    0,   10,   29,    0,
    7,
};
const short Indexdgoto[] = {                                       3,
   20,   21,   25,   32,   22,   29,    4,    5,    6,   44,
   47,   33,   36,   37,   23,    9,   18,   19,   42,
};
const short Indexsindex[] = {                                   -252,
    0,    0,    0,  -37,  -36,    0, -248, -245,  -45,  -26,
  -25, -252,  -40,  -39,    0,    0,    0,    0, -241,    0,
    0, -253,  -71, -253,    0,    0,    0,    0,    0, -260,
 -102,    0, -238,    0,    0,  -21,  -69,    0, -233, -260,
    0, -233,    0, -235,    0,  -98,  -16,    0,    0, -233,
    0,
};
const short Indexrindex[] = {                                     29,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   29,  -29,  -28,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -61,    0,    0,    0,    0,
    0,    0,  -44,    0,    0,    0,    0,    0,    0,    0,
    0,
};
const short Indexgindex[] = {                                     21,
    0,    0,    0,    0,    0,   10,    0,    0,    0,  -41,
    0,    0,    0,   -5,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 217
const short Indextable[] = {                                       6,
   46,   34,    7,    8,   35,   26,   27,   28,   51,   10,
    1,    2,   11,   12,   13,   14,   24,   16,   17,   30,
   38,   39,   40,   41,   43,   48,   49,   50,   20,   25,
   26,   14,   15,   31,   45,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    8,
};
const short Indexcheck[] = {                                      44,
   42,  262,   40,   40,  265,  259,  260,  261,   50,  258,
  263,  264,  258,   59,   41,   41,  258,   58,   58,   91,
  123,  260,   44,   93,  258,  261,  125,   44,    0,   59,
   59,   93,   12,   24,   40,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  261,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#if YYDEBUG
const char * const Indexname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,"':'","';'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"IDENT","ID","EQ","LT","GT","MINUS","NBORDTOK","NBEVENT","IDEN","OR","AND",
};
const char * const Indexrule[] = {
"$accept : FORMULES",
"OP : EQ",
"OP : LT",
"OP : GT",
"OPERP : NBORDTOK",
"OPERT : NBEVENT",
"$$1 :",
"VARS : ID $$1 ',' VARS",
"VARS : ID",
"$$2 :",
"CONST : $$2 LT VARS GT",
"PROJECTING : IDEN",
"PROJECTING : MINUS",
"PERS : PROJECTING ',' PERS",
"PERS : PROJECTING",
"$$3 :",
"PROJ : $$3 '[' PERS ']'",
"PROJ1 : PROJ",
"$$4 :",
"FORMULES : ATOMIC $$4 ';' FORMULES",
"FORMULES :",
"$$5 :",
"ATOMIC : OPERP '(' ID ')' ':' $$5 CONDP",
"$$6 :",
"ATOMIC : OPERT '(' ID ')' ':' $$6 CONDT",
"ATOMIC : OPERP '(' ID ')'",
"ATOMIC : OPERT '(' ID ')'",
"CONDP : PROJ1 OP CONST",
"$$7 :",
"CONDT : ID OP '{' $$7 VARS '}'",
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
#line 319 "./src/srcdsrg/IndexDsrg.y"

int perf_index_parser(FILE* f){

char c;
int i=0;
 char* ptr; 
   ptr=Ptr_Cur_index=(char*)malloc(STR_SIZE*sizeof(char));
     
   while((c=fgetc(f))!=EOF)  
     {
       Ptr_Cur_index[i]=c; 
       i++;
     }

   Ptr_Cur_index[i]='\0';
   Lim_Pos_index=(int)Ptr_Cur_index+strlen(Ptr_Cur_index);   

   if(i==0)
     {
       free(ptr);
       printf("\n File of perf. indices is empty \n");
       return 1;
     }
   
   i=yyparse();
   free(ptr);

  return i;
}















#line 362 "IndexDsrg.tab.c"
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
#line 119 "./src/srcdsrg/IndexDsrg.y"
{yyval.j=EQOP;}
break;
case 2:
#line 119 "./src/srcdsrg/IndexDsrg.y"
{yyval.j=LOP;}
break;
case 3:
#line 119 "./src/srcdsrg/IndexDsrg.y"
{yyval.j=GOP;}
break;
case 4:
#line 121 "./src/srcdsrg/IndexDsrg.y"
{yyval.j=NBTOKEN; }
break;
case 5:
#line 122 "./src/srcdsrg/IndexDsrg.y"
{yyval.j=NBEVENT; }
break;
case 6:
#line 123 "./src/srcdsrg/IndexDsrg.y"
{
            int Cl;
	    int v=GetIndObj(yyvsp[0].s,MTCL,&Cl);
	    if(v==UNKNOWN) error_color(yyvsp[0].s); 
	    TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
	    TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
	    TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;
	    free(yyvsp[0].s);
         }
break;
case 8:
#line 132 "./src/srcdsrg/IndexDsrg.y"
{
	   int Cl;
	   int v=GetIndObj(yyvsp[0].s,MTCL,&Cl);

	   if(v==UNKNOWN) 
	     error_color(yyvsp[0].s);  

	   TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
	   TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
	   TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ; 
	   free(yyvsp[0].s);
	 }
break;
case 9:
#line 145 "./src/srcdsrg/IndexDsrg.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 10:
#line 146 "./src/srcdsrg/IndexDsrg.y"
{      
	CToken_p pt =(CToken_p)emalloc(sizeof(CToken));
	pt->mult=1;
	(pt->tok_dom).Token=TD.Token;     
	(pt->tok_dom).Domain=TD.Domain;
	(pt->tok_dom).NbCl=TD.NbCl;
	pt->next=NULL;
	yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
	yyval.nd->op=NOP;
	yyval.nd->type=TOK;
	yyval.nd->FONCT=pt;
	yyval.nd->filsg=yyval.nd->filsd=NULL; 
	}
break;
case 11:
#line 160 "./src/srcdsrg/IndexDsrg.y"
{
               TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
 	       TD.Token[TD.NbCl]=PROJECT ; TD.NbCl++ ;   
             }
break;
case 12:
#line 164 "./src/srcdsrg/IndexDsrg.y"
{ 
	       TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
	       TD.Token[TD.NbCl]=ELIMINATE ; TD.NbCl++ ;  
	     }
break;
case 15:
#line 171 "./src/srcdsrg/IndexDsrg.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL; }
break;
case 16:
#line 172 "./src/srcdsrg/IndexDsrg.y"
{  
        if(TD.NbCl==1 && TD.Token[0]==ELIMINATE) 
	  error_dec(tabp[ind].place_name);
	if(TD.NbCl!=tabp[ind].comp_num)
	  error_proj(tabp[ind].place_name);
	 
	yyval.tk=(CToken_p)emalloc(sizeof(CToken));
	yyval.tk->mult=ind;
	(yyval.tk->tok_dom).Token=TD.Token;  
	(yyval.tk->tok_dom).Domain=NULL;
	int i;   
	for(i=0,(yyval.tk->tok_dom).NbCl=0;i<TD.NbCl;i++)
	  if((yyval.tk->tok_dom).Token[i]==PROJECT) {
	    (yyval.tk->tok_dom).Domain=realloc((yyval.tk->tok_dom).Domain,
					 (((yyval.tk->tok_dom).NbCl)+1)*sizeof(int));
	    (yyval.tk->tok_dom).Domain[ (yyval.tk->tok_dom).NbCl]=tabp[yyval.tk->mult].dominio[i]; 
	    (yyval.tk->tok_dom).NbCl++;
	  }  
	yyval.tk->next=NULL; 	     
       }
break;
case 17:
#line 193 "./src/srcdsrg/IndexDsrg.y"
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
case 18:
#line 203 "./src/srcdsrg/IndexDsrg.y"
{ 
              PERFINDICES= (struct Perf_Index**)realloc
		           (PERFINDICES,(NbPind+1)*sizeof(struct Perf_Index*));
	      PERFINDICES[NbPind]=yyvsp[0].Pd;
	      NbPind ++;
           }
break;
case 21:
#line 211 "./src/srcdsrg/IndexDsrg.y"
{
            if ((ind=EXISTE_PLACE(yyvsp[-2].s))==NOT_PRESENT)
	      error_proj(yyvsp[-2].s);	    
	    else {
	      free(yyvsp[-2].s);
	      TD.Token=NULL;
	      TD.Domain=NULL;
	      TD.NbCl=0;
	    }	
           }
break;
case 22:
#line 221 "./src/srcdsrg/IndexDsrg.y"
{
	     yyval.Pd= (struct Perf_Index*)emalloc(sizeof(struct Perf_Index));
	     yyval.Pd->pt_index=ind;
	     yyval.Pd->op_type=yyvsp[-6].j;
	     yyval.Pd->mean=0;
	     yyval.Pd->sum=0;
	     yyval.Pd->type=PL;
	     yyval.Pd->cond=yyvsp[0].nd;
	   }
break;
case 23:
#line 230 "./src/srcdsrg/IndexDsrg.y"
{
	     if ((ind=EXISTE_TRANS(yyvsp[-2].s))==NOT_PRESENT)
	       error_trans(yyvsp[-2].s);
	     else {
	       free(yyvsp[-2].s);
	       TD.Token=NULL;
	       TD.Domain=NULL;
	       TD.NbCl=0;
	     }    
	   }
break;
case 24:
#line 240 "./src/srcdsrg/IndexDsrg.y"
{
	     yyval.Pd= (struct Perf_Index*)emalloc(sizeof(struct Perf_Index));
	     yyval.Pd->pt_index=ind;
	     yyval.Pd->op_type=yyvsp[-6].j;
	     yyval.Pd->type=TR;
	     yyval.Pd->mean=0;
	     yyval.Pd->sum=0;
	     yyval.Pd->cond=yyvsp[0].nd;
	   }
break;
case 25:
#line 249 "./src/srcdsrg/IndexDsrg.y"
{
	     int i;
	     yyval.Pd= (struct Perf_Index*)emalloc(sizeof(struct Perf_Index));
	     if ((i=EXISTE_PLACE(yyvsp[-1].s))==NOT_PRESENT)
	       error_place(yyvsp[-1].s);  
	     free(yyvsp[-1].s);
	     yyval.Pd->mean=0;
	     yyval.Pd->sum=0;
	     yyval.Pd->type=PL  ; 
	     yyval.Pd->pt_index=i;
	     yyval.Pd->op_type=yyvsp[-3].j;
	     yyval.Pd->cond=NULL;
	   }
break;
case 26:
#line 262 "./src/srcdsrg/IndexDsrg.y"
{
	     int i;  
	     yyval.Pd= (struct Perf_Index*)emalloc(sizeof(struct Perf_Index));
	     if ((i=EXISTE_TRANS(yyvsp[-1].s))==NOT_PRESENT)
	       error_trans(yyvsp[-1].s);
	     free(yyvsp[-1].s);
	     yyval.Pd->mean=0; 
	     yyval.Pd->sum=0;
	     yyval.Pd->type=TR  ; 
	     yyval.Pd->pt_index=i;
	     yyval.Pd->op_type=yyvsp[-3].j;
	     yyval.Pd->cond=NULL;
	   }
break;
case 27:
#line 275 "./src/srcdsrg/IndexDsrg.y"
{
         int i;
	 yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
	 yyval.nd->op=yyvsp[-1].j;
	 yyval.nd->type=NOTYPE;
	 
	 if(((yyvsp[-2].nd->FONCT)->tok_dom).NbCl!=((yyvsp[0].nd->FONCT)->tok_dom).NbCl)
	   error_exp();  
	
	 for( i=0; i<((yyvsp[0].nd->FONCT)->tok_dom).NbCl;i++)
	   if( ((yyvsp[-2].nd->FONCT)->tok_dom).Domain[i]!= 
	       ((yyvsp[0].nd->FONCT)->tok_dom).Domain[i] )
	     error_exp();

	 yyval.nd->FONCT=yyvsp[0].nd->FONCT;
	 yyval.nd->filsg=yyvsp[-2].nd;
	 yyval.nd->filsd=yyvsp[0].nd;	 
        }
break;
case 28:
#line 294 "./src/srcdsrg/IndexDsrg.y"
{  TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 29:
#line 294 "./src/srcdsrg/IndexDsrg.y"
{
         int pos;
	 if((pos=EXISTE_FUNC(ind, yyvsp[-5].s))==NOT_PRESENT )
	   error_trans_fun(tabt[ind].trans_name, yyvsp[-5].s);
	 else
	   { 
	     yyval.nd = (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
	     yyval.nd->op=yyvsp[-4].j;
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
	     free(yyvsp[-5].s);
	   }
       }
break;
#line 819 "IndexDsrg.tab.c"
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
