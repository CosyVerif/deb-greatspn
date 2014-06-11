#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20100216

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)


#ifndef yyparse
#define yyparse    mmparse
#endif /* yyparse */

#ifndef yylex
#define yylex      mmlex
#endif /* yylex */

#ifndef yyerror
#define yyerror    mmerror
#endif /* yyerror */

#ifndef yychar
#define yychar     mmchar
#endif /* yychar */

#ifndef yyval
#define yyval      mmval
#endif /* yyval */

#ifndef yylval
#define yylval     mmlval
#endif /* yylval */

#ifndef yydebug
#define yydebug    mmdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    mmnerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  mmerrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      mmlhs
#endif /* yylhs */

#ifndef yylen
#define yylen      mmlen
#endif /* yylen */

#ifndef yydefred
#define yydefred   mmdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    mmdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   mmsindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   mmrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   mmgindex
#endif /* yygindex */

#ifndef yytable
#define yytable    mmtable
#endif /* yytable */

#ifndef yycheck
#define yycheck    mmcheck
#endif /* yycheck */

#ifndef yyname
#define yyname     mmname
#endif /* yyname */

#ifndef yyrule
#define yyrule     mmrule
#endif /* yyrule */
#define YYPREFIX "mm"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
#ifdef YYPARSE_PARAM_TYPE
#define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
#else
#define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
#endif
#else
#define YYPARSE_DECL() yyparse(void)
#endif /* YYPARSE_PARAM */

extern int YYPARSE_DECL();

#line 2 "SOURCE/CTL/CTLParser.y"
/*#include "../../INCLUDE/var_ext.h"*/
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include "CTLLexer.h"
#include "CTL.h"
#include "../SHARED/medd.h"
#define PERFORMANCECTL 1
using namespace std;
CTLMDD *ctl = CTLMDD::getInstance();
CTLFormula *ris = NULL;
dddRS::RSRG *rsrg;
istringstream *buffer;
FlexLexer* lexer;
clock_t startMDD, endMDD, endMDD2; /* tempi di clock quando inizia la generazione dell'MDD della formula, quando finisce e dopo aver controllato la presenza dello stato iniziale nella formula*/


void yyerror(const char *str)
{
  cout<<"Errore in parsificazione: "<<str<<endl;
}
 
int yywrap()
{
	return 0; /*con 1 cicla all'infinito*/
} 
int yylex(void){
	int i = lexer->yylex(); 
	return i;
}
extern int yyparse(void);
extern void getPreTR(const int tID, int *preset);
extern void getInhTR(const int tID, int *set);
extern int output_flag;
extern int Max_Token_Bound;


#line 44 "SOURCE/CTL/CTLParser.y"
typedef union{
double num;
char var[255];
class Term *term;
class Expression *expr;
class Inequality *ineq;
class AtomicProposition *AP;
class CTLFormula *formula;
} YYSTYPE;
#line 166 "SOURCE/CTL/CTLParser.cc"
#define NUMBER 257
#define VAR 258
#define PLUS 259
#define MINUS 260
#define TIMES 261
#define DIV 262
#define MINOR 263
#define MAJOR 264
#define MINOREQ 265
#define MAJOREQ 266
#define EQ 267
#define NEQ 268
#define OR 269
#define AND 270
#define NOT 271
#define LPARENT 272
#define RPARENT 273
#define TRUEv 274
#define FALSEv 275
#define LQPARENT 276
#define RQPARENT 277
#define DEADLOCK 278
#define NDEADLOCK 279
#define ENABLED 280
#define E 281
#define A 282
#define G 283
#define X 284
#define F 285
#define U 286
#define IMPL 287
#define YYERRCODE 256
static const short mmlhs[] = {                           -1,
    0,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    4,    4,    4,    4,
    6,    6,    5,    5,    5,    5,    5,    5,    1,    1,
    1,    1,    1,    1,    1,    2,    2,    2,    3,    3,
    3,    3,    3,
};
static const short mmlen[] = {                            2,
    1,    1,    3,    3,    3,    2,    3,    3,    3,    6,
    3,    3,    3,    3,    6,    4,    1,    1,    1,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    3,    3,    3,    3,    3,    3,    1,    1,    3,
    3,    3,    3,
};
static const short mmdefred[] = {                         0,
   39,   38,    0,    0,   21,   22,   20,   19,    0,    0,
    0,    0,    0,   31,    0,    2,   17,   18,    0,    6,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   29,
   30,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,   35,    0,    0,    0,    0,
    0,    0,    0,    0,   36,   42,   37,   43,    0,    0,
    0,   16,    0,    0,    0,    0,    0,    0,    0,   10,
   15,
};
static const short mmdgoto[] = {                         12,
   13,   14,   15,   16,   17,   18,   19,
};
static const short mmsindex[] = {                      -179,
    0,    0, -179, -179,    0,    0,    0,    0, -270, -106,
 -103,    0,  -99,    0, -109,    0,    0,    0, -243,    0,
 -146, -241, -264, -254, -179, -179, -179, -179, -179, -179,
 -179, -179, -160, -160, -160, -160, -245, -245, -245, -245,
 -245, -245, -245, -245, -247, -190, -179, -179, -179,    0,
    0,    0, -257, -256, -243, -243, -243, -210, -243, -243,
 -243, -160, -177, -177,    0,    0, -105, -105, -105, -105,
 -105, -105, -171, -171,    0,    0,    0,    0, -163, -209,
 -243,    0, -179, -179, -114, -245, -245, -262, -207,    0,
    0,
};
static const short mmrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   65,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   86,   87,   88,    0,   89,   94,
  104,    0, -135, -124,    0,    0,   22,   24,   43,   45,
   64,   66,    1,    3,    0,    0,    0,    0,   71,   69,
  105,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short mmgindex[] = {                         0,
   13,    0,   -4,    0,    0,    0,   25,
};
#define YYTABLESIZE 391
static const short mmtable[] = {                         22,
   40,   24,   41,   53,   47,   48,   47,   48,   52,    1,
   75,    1,   47,   48,   90,   82,   21,   43,   44,   45,
   46,   23,   49,   25,   49,   47,   48,   20,   23,   83,
   49,   51,   67,   68,   69,   70,   71,   72,   73,   74,
   76,   78,   24,   49,   26,   63,   64,   65,   66,   54,
   55,   56,   57,   58,   59,   60,   61,   22,   47,   48,
   48,   47,   48,   27,    1,   28,    1,   77,    4,   91,
    5,   79,   80,   81,   85,   84,   49,    1,    2,   49,
    0,   76,   78,   35,   36,    9,    8,   13,   14,   86,
   87,    3,    4,   11,    5,    6,    1,    2,    7,    8,
    9,   10,   11,   12,    7,   47,   48,   88,   89,    0,
    0,   62,   33,   34,   35,   36,   37,   38,   39,   40,
   41,   42,    0,   32,   32,    0,   50,   32,   32,   32,
   32,   32,   32,    0,   33,   33,    0,   32,   33,   33,
   33,   33,   33,   33,   33,   34,   35,   36,   33,   43,
   44,   45,   46,   43,   44,   86,   87,    0,   50,   33,
   34,   35,   36,   37,   38,   39,   40,   41,   42,   25,
    0,    0,   29,    0,    0,    0,   26,   27,   28,   30,
   31,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   40,
   40,   41,   41,    0,    0,    0,    0,    0,    0,   40,
   40,   41,   41,   40,    0,   41,    0,   40,    0,   41,
    0,    0,    0,    0,    0,    0,   40,   40,   41,   41,
   23,   23,   25,   25,   23,    0,   25,    0,   23,    0,
   25,    0,    0,    0,    0,    0,    0,   23,   23,   25,
   25,   24,   24,   26,   26,   24,    0,   26,    0,   24,
    0,   26,    0,    0,    0,    0,    0,    0,   24,   24,
   26,   26,   27,   27,   28,   28,   27,    4,   28,    0,
   27,    4,   28,    5,    0,    4,    0,    5,    0,   27,
   27,   28,   28,    0,    4,    4,    5,    5,    9,    8,
   13,   14,    9,    8,   13,   14,   11,    0,    0,    0,
   11,    9,    8,   13,   14,    0,   12,    7,    0,   11,
   12,    7,    0,    0,    0,    0,    0,    0,    0,   12,
    7,
};
static const short mmcheck[] = {                          4,
    0,  272,    0,  258,  269,  270,  269,  270,  273,  257,
  258,  257,  269,  270,  277,  273,    4,  259,  260,  261,
  262,    0,  287,    0,  287,  269,  270,    3,    4,  286,
  287,  273,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,    0,  287,    0,   33,   34,   35,   36,   25,
   26,   27,   28,   29,   30,   31,   32,   62,  269,  270,
  270,  269,  270,    0,    0,    0,  257,  258,    0,  277,
    0,   47,   48,   49,   62,  286,  287,  257,  258,  287,
   -1,   86,   87,  261,  262,    0,    0,    0,    0,  261,
  262,  271,  272,    0,  274,  275,  257,  258,  278,  279,
  280,  281,  282,    0,    0,  269,  270,   83,   84,   -1,
   -1,  272,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,   -1,  259,  260,   -1,  273,  263,  264,  265,
  266,  267,  268,   -1,  259,  260,   -1,  273,  263,  264,
  265,  266,  267,  268,  259,  260,  261,  262,  273,  259,
  260,  261,  262,  259,  260,  261,  262,   -1,  273,  259,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  276,
   -1,   -1,  276,   -1,   -1,   -1,  283,  284,  285,  283,
  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,
  260,  259,  260,   -1,   -1,   -1,   -1,   -1,   -1,  269,
  270,  269,  270,  273,   -1,  273,   -1,  277,   -1,  277,
   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  286,  287,
  269,  270,  269,  270,  273,   -1,  273,   -1,  277,   -1,
  277,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  286,
  287,  269,  270,  269,  270,  273,   -1,  273,   -1,  277,
   -1,  277,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
  286,  287,  269,  270,  269,  270,  273,  269,  273,   -1,
  277,  273,  277,  273,   -1,  277,   -1,  277,   -1,  286,
  287,  286,  287,   -1,  286,  287,  286,  287,  273,  273,
  273,  273,  277,  277,  277,  277,  273,   -1,   -1,   -1,
  277,  286,  286,  286,  286,   -1,  273,  273,   -1,  286,
  277,  277,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
  286,
};
#define YYFINAL 12
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NUMBER","VAR","PLUS","MINUS",
"TIMES","DIV","MINOR","MAJOR","MINOREQ","MAJOREQ","EQ","NEQ","OR","AND","NOT",
"LPARENT","RPARENT","TRUEv","FALSEv","LQPARENT","RQPARENT","DEADLOCK",
"NDEADLOCK","ENABLED","E","A","G","X","F","U","IMPL",
};
static const char *yyrule[] = {
"$accept : inizio",
"inizio : CTLformula",
"CTLformula : atomicProposition",
"CTLformula : LPARENT CTLformula RPARENT",
"CTLformula : CTLformula AND CTLformula",
"CTLformula : CTLformula OR CTLformula",
"CTLformula : NOT CTLformula",
"CTLformula : CTLformula IMPL CTLformula",
"CTLformula : E X CTLformula",
"CTLformula : E G CTLformula",
"CTLformula : E LQPARENT CTLformula U CTLformula RQPARENT",
"CTLformula : A X CTLformula",
"CTLformula : A F CTLformula",
"CTLformula : E F CTLformula",
"CTLformula : A G CTLformula",
"CTLformula : A LQPARENT CTLformula U CTLformula RQPARENT",
"CTLformula : ENABLED LPARENT VAR RPARENT",
"atomicProposition : inequality",
"atomicProposition : boolvalue",
"atomicProposition : NDEADLOCK",
"atomicProposition : DEADLOCK",
"boolvalue : TRUEv",
"boolvalue : FALSEv",
"inequality : expression MINOR number_expr",
"inequality : expression MINOREQ number_expr",
"inequality : expression MAJOR number_expr",
"inequality : expression MAJOREQ number_expr",
"inequality : expression EQ number_expr",
"inequality : expression NEQ number_expr",
"expression : LPARENT expression RPARENT",
"expression : LPARENT number_expr RPARENT",
"expression : term",
"expression : expression PLUS expression",
"expression : expression MINUS expression",
"expression : expression TIMES expression",
"expression : expression DIV expression",
"term : number_expr TIMES VAR",
"term : number_expr DIV VAR",
"term : VAR",
"number_expr : NUMBER",
"number_expr : number_expr PLUS number_expr",
"number_expr : number_expr MINUS number_expr",
"number_expr : number_expr TIMES number_expr",
"number_expr : number_expr DIV number_expr",

};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;

#define YYPURE 0

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 201 "SOURCE/CTL/CTLParser.y"


std::string getVarName(int v){
	std::string val = rsrg->getPL(v-1);
	return val;//.c_str(); 
}




/**
* Private
*/
dd_edge *parse_formula(std::string formula, bool *val){
	buffer = new istringstream(formula);
	lexer = new yyFlexLexer(buffer);
	yyparse();
	delete lexer;
	delete buffer;
	dd_edge * dd = NULL;
	if(ris!= NULL){
		startMDD=clock();
		dd = ris->getMDD();
		endMDD=clock();
		if(dd!=NULL) dd = ctl->copy(dd);
		delete(ris);
		ris = NULL;
		//Controllo la presenza della marcatura iniziale
		dd_edge r(ctl->getMDDForest());
		try
			{
			apply(INTERSECTION, (*(ctl->getInitMark())), (*dd),(r));
			}
		catch(...)
			{
			cerr << "ERROR in INTERSECTION in Parser";
			}
		endMDD2=clock();
		(*val) = (r.getCardinality()!=0);
	}
	return dd;
}

/**
* It parses formula and returns a dd_edge and a bool value (true is the formula is valid for initia mark)
*
**/
dd_edge *CTLParser(dddRS::RSRG r, std::string formula, bool *val){
	rsrg = &r;
	//inizializzo la classe CTL dove ho i riferimenti a rs foreste e domini per tutte le altre classi
	ctl->CTLinit(rsrg->getRS(),rsrg->getInitMark(), rsrg->getNSFt(), rsrg->getDomain());
	return parse_formula(formula,val);
}

/**
* It parses all formulas into file net_name.ctl and returns a dd_edge
*
**/


dd_edge * CTLParser(dddRS::RSRG *r){
	clock_t startOut, endOut;
	bool val;
	rsrg = r;
	std::string filename = rsrg->getNetName();
	ifstream in;
	filename = filename + ".ctl";
	in.open(filename.c_str());
	//inizializzo la classe CTL dove ho i riferimenti a rs foreste e domini per tutte le altre classi
	ctl->CTLinit(rsrg->getRS(),rsrg->getInitMark(), rsrg->getNSFt(), rsrg->getDomain());
	dd_edge *dd;
	filename = filename + ".output";
	FILE *f = fopen(filename.c_str(), "w"); 
	char tmp[255];
	char *line = &tmp[0];
	while(!in.eof()){
		in.getline(line,255,'\n');
		if(std::string(line)!="") {
			cout<<"--- "<<std::string(line)<<" ---"<<endl;
			dd = parse_formula(std::string(line), &val); 
			fprintf(f,"\n ********** %s *********  \n", line);
			if(dd == NULL){
				fprintf(f,"Error during the computatione\n");
				cout<<"Error"<<endl;
			}
			else{	
				startOut = clock();
				cout<<"\tEvaluation: "<<(val?"true":"false")<<endl;
				val?fprintf(f,"Evaluation: true\n"):fprintf(f,"Evaluation: false\n");
				// STAMPA MARCATURE
				if(output_flag == TRUE){
					dd_edge::iterator i = dd->begin();
					int nvar = ctl->getDomain()->getNumVariables();
					while(i!=NULL){// != dd->end()){ 
						int j;
						for(j=1; j <= nvar; j++){
							int val = *(i.getAssignments() + j );
							std::string s = getVarName(j);
							if(val!=0) fprintf(f,"%s(%d) ",s.c_str(), val);
						}//per ogni posto
						++i;
						fprintf(f,"\n");
						fflush(f);
					}//per ogni marcatura
				}//fine stampa
				dd = NULL;
				endOut = clock();
			
				#if PERFORMANCECTL
				cout<<"\tTime set generation: "<<setprecision(7)<<((double)(endMDD-startMDD))/CLOCKS_PER_SEC<<" sec"<<endl;
				cout<<"\tTime set generation and valutation: "<<setprecision(7)<<((double)(endMDD2-startMDD))/CLOCKS_PER_SEC<<" sec"<<endl;
				cout<<"\tTime print: "<<setprecision(7)<<((double)(endOut-startOut))/CLOCKS_PER_SEC<<" sec"<<endl;
				#endif
			}
			cout<<endl;
		}
	}//per ogni riga file
	in.close();
	fclose(f);
	//cout<<"Risultati scritti su file"<<endl;
	return dd;
}






int getVarID(std::string v){
	int val = rsrg->getPL(v);
	if(val == -1) cout<<"Place "<<v<<" not found"<<endl;
	return val +1; 
}

CTLFormula * enableTR(std::string v){
	int val = rsrg->getTR(v);
	if(val == -1) {
		cout<<"Transizione "<<v<<" non trovata"<<endl;
		return new BoolValue(false);
	}
	else{
		int nvar = ctl->getDomain()->getNumVariables();
		//int b = Max_Token_Bound;
		int * pre = (int *) malloc((nvar) * sizeof(int));
		int * inhib = (int *) malloc((nvar) * sizeof(int));
		getPreTR(val,pre);
		getInhTR(val,inhib);
		bool first = true;
		CTLFormula *formula=NULL;
		for(int i = 0; i<nvar;i++){

			if(pre[i]!=0){
				Term *t = new Term(1,i+1,(Term::op_type)2);/*Term::TIMES);*/;
				Inequality *in = new Inequality((Inequality::op_type)3/*>=*/,t,pre[i]);
				CTLFormula *ce;
				if(first){
					first=false;
					ce = in;
				}
				else
					ce = new ComplexBoolFormula(formula,in, (ComplexBoolFormula::op_type)1/*AND*/);
				formula = ce;
			}
			
			if(inhib[i]!=0){
				Term *t = new Term(1,i+1,(Term::op_type)2);/*Term::TIMES);*/;
				Inequality *in = new Inequality((Inequality::op_type)0/*<*/,t,inhib[i]);
				CTLFormula *ce;
				if(first){
					first=false;
					ce = in;
				}
				else
					ce = new ComplexBoolFormula(formula,in, (ComplexBoolFormula::op_type)1/*AND*/);
				formula = ce;
			}





		}
		free(pre);
		free(inhib);
		return formula;
	}
}

/*int main( int argc, const char* argv[] )
{
	//Settare num variabili in ctlmdd ecc...
        yyparse();
	return 1;
} */
#line 642 "SOURCE/CTL/CTLParser.cc"
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

    i = data->s_mark - data->s_base;
    newss = (data->s_base != 0)
          ? (short *)realloc(data->s_base, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base  = newss;
    data->s_mark = newss + i;

    newvs = (data->l_base != 0)
          ? (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
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
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
#line 74 "SOURCE/CTL/CTLParser.y"
	{ris = yystack.l_mark[0].formula;}
break;
case 2:
#line 78 "SOURCE/CTL/CTLParser.y"
	{yyval.formula=yystack.l_mark[0].AP;}
break;
case 3:
#line 79 "SOURCE/CTL/CTLParser.y"
	{yyval.formula=yystack.l_mark[-1].formula;}
break;
case 4:
#line 80 "SOURCE/CTL/CTLParser.y"
	{ComplexBoolFormula *ce = new ComplexBoolFormula(yystack.l_mark[-2].formula,yystack.l_mark[0].formula, (ComplexBoolFormula::op_type)1);yyval.formula = ce;}
break;
case 5:
#line 81 "SOURCE/CTL/CTLParser.y"
	{ComplexBoolFormula *ce = new ComplexBoolFormula(yystack.l_mark[-2].formula,yystack.l_mark[0].formula, (ComplexBoolFormula::op_type)2);yyval.formula = ce;}
break;
case 6:
#line 82 "SOURCE/CTL/CTLParser.y"
	{ComplexBoolFormula *ce = new ComplexBoolFormula(yystack.l_mark[0].formula);yyval.formula = ce;}
break;
case 7:
#line 83 "SOURCE/CTL/CTLParser.y"
	{ /* (not CTLformula1) or CTLformula*/
				  ComplexBoolFormula *nf1 = new ComplexBoolFormula(yystack.l_mark[-2].formula); /* (not CTLformula1)*/
				  ComplexBoolFormula *ce = new ComplexBoolFormula(nf1,yystack.l_mark[0].formula, (ComplexBoolFormula::op_type)2);
				  yyval.formula = ce;
				}
break;
case 8:
#line 88 "SOURCE/CTL/CTLParser.y"
	{CTLOperation *ce = new CTLOperation(yystack.l_mark[0].formula, (CTLOperation::op_type) 0/*CTLOperation::EX*/);yyval.formula = ce;}
break;
case 9:
#line 89 "SOURCE/CTL/CTLParser.y"
	{CTLOperation *ce = new CTLOperation(yystack.l_mark[0].formula, (CTLOperation::op_type) 2/*CTLOperation::EG*/);yyval.formula = ce;}
break;
case 10:
#line 90 "SOURCE/CTL/CTLParser.y"
	{CTLOperation *ce = new CTLOperation(yystack.l_mark[-3].formula, yystack.l_mark[-1].formula);yyval.formula = ce;}
break;
case 11:
#line 91 "SOURCE/CTL/CTLParser.y"
	{	/* not EX not CTLFormula */
					ComplexBoolFormula *cbf = new ComplexBoolFormula(yystack.l_mark[0].formula); /*not CTLFormula*/
					CTLOperation *co = new CTLOperation(cbf, (CTLOperation::op_type) 0/*CTLOperation::EX*/); /* EX not CTLFormula*/
					ComplexBoolFormula *ce = new ComplexBoolFormula(co); /*not EX not CTLFormula*/
					yyval.formula = ce;
				}
break;
case 12:
#line 98 "SOURCE/CTL/CTLParser.y"
	{	/* not EG not CTLFormula */
					ComplexBoolFormula *cbf = new ComplexBoolFormula(yystack.l_mark[0].formula); /*not CTLFormula*/
					CTLOperation *co = new CTLOperation(cbf, (CTLOperation::op_type) 2/*CTLOperation::EG*/); /* EG not CTLFormula*/
					ComplexBoolFormula *ce = new ComplexBoolFormula(co); /*not EG not CTLFormula*/
					yyval.formula = ce;
				}
break;
case 13:
#line 105 "SOURCE/CTL/CTLParser.y"
	{	/* E true U CTLFormula */
					/**/
					/*BoolValue *bv = new BoolValue(true); //true*/
					/*CTLOperation *ce = new CTLOperation(bv, $3); // E true U CTLFormula*/
					CTLOperation *co = new CTLOperation(yystack.l_mark[0].formula, (CTLOperation::op_type) 3/*CTLOperation::EF*/); 					yyval.formula = co;
				}
break;
case 14:
#line 111 "SOURCE/CTL/CTLParser.y"
	{	/*not (E true U not CTLFormula )*/
					/*BoolValue *bv = new BoolValue(true); //true*/
					ComplexBoolFormula *cbf = new ComplexBoolFormula(yystack.l_mark[0].formula); /*not CTLFormula*/
					/*CTLOperation *eu = new CTLOperation(bv, cbf); // E true U not CTLFormula*/
					/*ComplexBoolFormula *ce = new ComplexBoolFormula(eu); //not E true U not CTLFormula*/
					/*not EF not CTLFormula*/
					CTLOperation *co = new CTLOperation(cbf, (CTLOperation::op_type) 3/*CTLOperation::EF*/);
					ComplexBoolFormula *ce = new ComplexBoolFormula(co);
					yyval.formula = ce;
				}
break;
case 15:
#line 121 "SOURCE/CTL/CTLParser.y"
	{	/*not (E not CTLFormula2 U (not CTLFormula1 and not CTLFormula2) ) and not EG not CTLFormula2*/
					ComplexBoolFormula *f1 = new ComplexBoolFormula(yystack.l_mark[-3].formula); /*not CTLFormula1*/
					ComplexBoolFormula *f2 = new ComplexBoolFormula(yystack.l_mark[-1].formula); /*not CTLFormula2*/
					ComplexBoolFormula *f1f2 = new ComplexBoolFormula(f1,f2, (ComplexBoolFormula::op_type)1/*and*/); /*(not CTLFormula1 and not CTLFormula2)*/
					CTLOperation *eu = new CTLOperation(f2, f1f2); /*E not CTLFormula2 U (not CTLFormula1 and not CTLFormula2) */
					ComplexBoolFormula *neu = new ComplexBoolFormula(eu); /*not (E not CTLFormula2 U (not CTLFormula1 and not CTLFormula2) )*/
					CTLOperation *eg = new CTLOperation(f2, (CTLOperation::op_type) 2/*CTLOperation::EG*/); /* EG not CTLFormula2*/
					ComplexBoolFormula *neg = new ComplexBoolFormula(eg); /*not EG not CTLFormula2*/
					ComplexBoolFormula *ce = new ComplexBoolFormula(neu,neg, (ComplexBoolFormula::op_type)1/*and*/); /*total*/
					yyval.formula = ce;
				}
break;
case 16:
#line 132 "SOURCE/CTL/CTLParser.y"
	{std::string v(yystack.l_mark[-1].var); yyval.formula=enableTR(v);}
break;
case 17:
#line 136 "SOURCE/CTL/CTLParser.y"
	{yyval.AP = yystack.l_mark[0].ineq;}
break;
case 18:
#line 137 "SOURCE/CTL/CTLParser.y"
	{yyval.AP = yystack.l_mark[0].AP;}
break;
case 19:
#line 138 "SOURCE/CTL/CTLParser.y"
	{yyval.AP = new Deadlock(false);}
break;
case 20:
#line 139 "SOURCE/CTL/CTLParser.y"
	{yyval.AP = new Deadlock(true);}
break;
case 21:
#line 143 "SOURCE/CTL/CTLParser.y"
	{BoolValue *be = new BoolValue(true); yyval.AP = be;}
break;
case 22:
#line 144 "SOURCE/CTL/CTLParser.y"
	{BoolValue *be = new BoolValue(false); yyval.AP = be;}
break;
case 23:
#line 147 "SOURCE/CTL/CTLParser.y"
	{ Expression *ex = yystack.l_mark[-2].expr;
				Inequality *in = new Inequality((Inequality::op_type)0,ex,yystack.l_mark[0].num);
				yyval.ineq=in;
				}
break;
case 24:
#line 151 "SOURCE/CTL/CTLParser.y"
	{Expression *ex = yystack.l_mark[-2].expr;
				Inequality *in = new Inequality((Inequality::op_type)2,ex,yystack.l_mark[0].num);
				yyval.ineq=in;
				}
break;
case 25:
#line 155 "SOURCE/CTL/CTLParser.y"
	{Expression *ex = yystack.l_mark[-2].expr;
				Inequality *in = new Inequality((Inequality::op_type)1,ex,yystack.l_mark[0].num);
				yyval.ineq=in;
				}
break;
case 26:
#line 159 "SOURCE/CTL/CTLParser.y"
	{Expression *ex = yystack.l_mark[-2].expr;
				Inequality *in = new Inequality((Inequality::op_type)3,ex,yystack.l_mark[0].num);
				yyval.ineq=in;
				}
break;
case 27:
#line 163 "SOURCE/CTL/CTLParser.y"
	{Expression *ex = yystack.l_mark[-2].expr;
				Inequality *in = new Inequality((Inequality::op_type)4,ex,yystack.l_mark[0].num);
				yyval.ineq=in;

				}
break;
case 28:
#line 168 "SOURCE/CTL/CTLParser.y"
	{Expression *ex = yystack.l_mark[-2].expr;
				Inequality *in = new Inequality((Inequality::op_type)5,ex,yystack.l_mark[0].num);
				yyval.ineq=in;
				}
break;
case 29:
#line 175 "SOURCE/CTL/CTLParser.y"
	{yyval.expr = yystack.l_mark[-1].expr;}
break;
case 30:
#line 176 "SOURCE/CTL/CTLParser.y"
	{ConstantExpr *ce = new ConstantExpr(yystack.l_mark[-1].num); yyval.expr = ce;}
break;
case 31:
#line 177 "SOURCE/CTL/CTLParser.y"
	{ yyval.expr=yystack.l_mark[0].term;}
break;
case 32:
#line 179 "SOURCE/CTL/CTLParser.y"
	{ComplexExpr *ce = new ComplexExpr(yystack.l_mark[-2].expr,yystack.l_mark[0].expr,(Expression::op_type)0);/*Expression::PLUS);*/	yyval.expr=ce;}
break;
case 33:
#line 180 "SOURCE/CTL/CTLParser.y"
	{ComplexExpr *ce = new ComplexExpr(yystack.l_mark[-2].expr,yystack.l_mark[0].expr,(Expression::op_type)1);/*Expression::MINUS);*/ yyval.expr=ce;}
break;
case 34:
#line 181 "SOURCE/CTL/CTLParser.y"
	{ComplexExpr *ce = new ComplexExpr(yystack.l_mark[-2].expr,yystack.l_mark[0].expr,(Expression::op_type)2);/*Expression::TIMES);*/ yyval.expr=ce;}
break;
case 35:
#line 182 "SOURCE/CTL/CTLParser.y"
	{ComplexExpr *ce = new ComplexExpr(yystack.l_mark[-2].expr,yystack.l_mark[0].expr,(Expression::op_type)3);/*Expression::DIV);*/ yyval.expr=ce;}
break;
case 36:
#line 187 "SOURCE/CTL/CTLParser.y"
	{std::string v(yystack.l_mark[0].var); Term *t = new Term(yystack.l_mark[-2].num,getVarID(v),(Term::op_type)2);/*Term::TIMES);*/ yyval.term=t;}
break;
case 37:
#line 188 "SOURCE/CTL/CTLParser.y"
	{std::string v(yystack.l_mark[0].var);Term *t = new Term(yystack.l_mark[-2].num,getVarID(v),(Term::op_type)3);/*Term::DIV);*/ yyval.term=t;}
break;
case 38:
#line 189 "SOURCE/CTL/CTLParser.y"
	{std::string v(yystack.l_mark[0].var); Term *t = new Term(1,getVarID(v),(Term::op_type)2);/*Term::TIMES);*/ yyval.term=t;}
break;
case 39:
#line 194 "SOURCE/CTL/CTLParser.y"
	{yyval.num=yystack.l_mark[0].num;}
break;
case 40:
#line 195 "SOURCE/CTL/CTLParser.y"
	{yyval.num=yystack.l_mark[-2].num +yystack.l_mark[0].num;}
break;
case 41:
#line 196 "SOURCE/CTL/CTLParser.y"
	{yyval.num=yystack.l_mark[-2].num -yystack.l_mark[0].num;}
break;
case 42:
#line 197 "SOURCE/CTL/CTLParser.y"
	{yyval.num=yystack.l_mark[-2].num *yystack.l_mark[0].num;}
break;
case 43:
#line 198 "SOURCE/CTL/CTLParser.y"
	{yyval.num=yystack.l_mark[-2].num /yystack.l_mark[0].num;}
break;
#line 1073 "SOURCE/CTL/CTLParser.cc"
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
