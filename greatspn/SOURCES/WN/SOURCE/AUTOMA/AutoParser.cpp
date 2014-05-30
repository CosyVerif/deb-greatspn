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
#define yyparse    kkparse
#endif /* yyparse */

#ifndef yylex
#define yylex      kklex
#endif /* yylex */

#ifndef yyerror
#define yyerror    kkerror
#endif /* yyerror */

#ifndef yychar
#define yychar     kkchar
#endif /* yychar */

#ifndef yyval
#define yyval      kkval
#endif /* yyval */

#ifndef yylval
#define yylval     kklval
#endif /* yylval */

#ifndef yydebug
#define yydebug    kkdebug
#endif /* yydebug */

#ifndef yynerrs
#define yynerrs    kknerrs
#endif /* yynerrs */

#ifndef yyerrflag
#define yyerrflag  kkerrflag
#endif /* yyerrflag */

#ifndef yylhs
#define yylhs      kklhs
#endif /* yylhs */

#ifndef yylen
#define yylen      kklen
#endif /* yylen */

#ifndef yydefred
#define yydefred   kkdefred
#endif /* yydefred */

#ifndef yydgoto
#define yydgoto    kkdgoto
#endif /* yydgoto */

#ifndef yysindex
#define yysindex   kksindex
#endif /* yysindex */

#ifndef yyrindex
#define yyrindex   kkrindex
#endif /* yyrindex */

#ifndef yygindex
#define yygindex   kkgindex
#endif /* yygindex */

#ifndef yytable
#define yytable    kktable
#endif /* yytable */

#ifndef yycheck
#define yycheck    kkcheck
#endif /* yycheck */

#ifndef yyname
#define yyname     kkname
#endif /* yyname */

#ifndef yyrule
#define yyrule     kkrule
#endif /* yyrule */
#define YYPREFIX "kk"

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

#line 22 "SOURCE/AUTOMA/AutoParser.y"
#ifndef __PRS_H__
	#define __PRS_H__
	#include "../AUTOMA/parser.h"
#endif

extern "C"
{
#include "AutoLexer.h"
#include <stdio.h>
#include <string.h>

	int kkparse(void);
	int kklex(void);
        int kkwrap()
        	{
                return 1;
        	}
	void kkerror(const char *str)
		{
        	fprintf(stderr,"errore: %s\n",str);
		}
}
extern FILE * kkin; /*standard yacc from file*/

using namespace dddRS;

dddRS::RSRGAuto *rs;
map <int, map <int ,class ATRANSITION> > automa;
int source,transition,dest;
map < int, class BOUNDMARKING > tmpPre, tmpPost;
bool pre=false;
set <int> InitSet;
int Bot=-1, Top=-1;


int initAutoma(class RSRGAuto* r)
{
rs = r;
std::string net=rs->getNetName()+std::string(".automaton");
kkin = fopen(net.c_str(),"r");
if (kkin==NULL)
    {
    printf("\n\nError: opening input file: %s\n\n",net.c_str());
    exit(EXIT_FAILURE);
    }
kkparse();
fclose(kkin);
#if DEBUGPARSER
map <int, map < int ,class ATRANSITION> >::iterator iterm = automa.begin();
while (iterm!=automa.end())
	{
	cout<<"****************************************\n";
	cout<<"\t\tSource: "<<iterm->first<<endl;
	map <int, class ATRANSITION>::iterator iterl = iterm->second.begin();
	cout<<"****************************************\n";
	while (iterl!=iterm->second.end())
		{
		cout<<"\tTransition: "<<(iterl->first)<<endl;
		cout<<iterl->second;
		iterl++;
		}	
	iterm++;
	}
	cout<<endl;
#endif
return EXIT_SUCCESS;
}

#line 98 "SOURCE/AUTOMA/AutoParser.y"
typedef union{
int num;
char var[255];
} YYSTYPE;
#line 188 "SOURCE/AUTOMA/AutoParser.cpp"
#define NUMBER 257
#define STRING 258
#define YYERRCODE 256
static const short kklhs[] = {                           -1,
    0,    0,    3,    3,    2,    2,    1,    1,    5,    4,
    6,    9,    8,    7,    7,    7,    7,   10,   10,   10,
};
static const short kklen[] = {                            2,
    0,    5,    0,    2,    2,    2,    0,    2,    1,    5,
    1,    1,    1,    1,    1,    3,    5,    3,    3,    3,
};
static const short kkdefred[] = {                         0,
    0,    0,    9,    0,    8,    0,    0,    5,    6,    3,
    0,   11,    4,    0,    0,   14,    0,    0,   15,    0,
    0,    0,    0,    0,   13,    0,   18,   19,   20,    0,
   16,    0,    0,   12,   10,   17,
};
static const short kkdgoto[] = {                          1,
    2,    7,   11,   13,    5,   14,   18,   26,   35,   19,
};
static const short kksindex[] = {                         0,
    0, -121,    0, -247,    0,  -43, -113,    0,    0,    0,
 -245,    0,    0,  -40,  -53,    0,  -40, -244,    0, -241,
 -239, -238,  -25,  -21,    0,  -40,    0,    0,    0, -237,
    0, -235,  -18,    0,    0,    0,
};
static const short kkrindex[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   24,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -12,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short kkgindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  -11,    0,    0,  -13,
};
#define YYTABLESIZE 258
static const short kktable[] = {                         17,
    1,    9,    4,   24,   16,   23,   20,   22,   21,    6,
   10,   12,   30,   25,   32,   27,   33,   28,   29,   31,
   15,   34,   36,    2,    0,   15,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    8,    0,    0,    0,   15,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    7,
};
static const short kkcheck[] = {                         40,
    0,   45,  124,   17,   45,   17,   60,   61,   62,  257,
  124,  257,   38,  258,   26,  257,   30,  257,  257,   41,
  258,  257,   41,    0,   -1,   38,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,   -1,   -1,   -1,  258,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 258
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'&'",0,"'('","')'",0,0,0,"'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'<'","'='",
"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"NUMBER","STRING",
};
static const char *yyrule[] = {
"$accept : automa",
"automa :",
"automa : entry '|' exit '|' edges",
"edges :",
"edges : edges rule",
"exit : NUMBER NUMBER",
"exit : NUMBER '-'",
"entry :",
"entry : entry state",
"state : NUMBER",
"rule : source exp trans exp destination",
"source : NUMBER",
"destination : NUMBER",
"trans : STRING",
"exp : '-'",
"exp : formula",
"exp : '(' formula ')'",
"exp : '(' exp '&' formula ')'",
"formula : STRING '<' NUMBER",
"formula : STRING '>' NUMBER",
"formula : STRING '=' NUMBER",

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
#line 230 "SOURCE/AUTOMA/AutoParser.y"
  
#line 365 "SOURCE/AUTOMA/AutoParser.cpp"
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
case 5:
#line 118 "SOURCE/AUTOMA/AutoParser.y"
	{
		Top = yystack.l_mark[-1].num;
		Bot = yystack.l_mark[0].num;
		}
break;
case 6:
#line 124 "SOURCE/AUTOMA/AutoParser.y"
	{
		Top = yystack.l_mark[-1].num;
		}
break;
case 9:
#line 136 "SOURCE/AUTOMA/AutoParser.y"
	{
		InitSet.insert(yystack.l_mark[0].num);
		}
break;
case 10:
#line 143 "SOURCE/AUTOMA/AutoParser.y"
	{
		ATRANSITION temp(dest);
		temp.setLBoundPre(tmpPre);
		temp.setLBoundPost(tmpPost);
		tmpPre.clear();
		tmpPost.clear();
		automa[source][transition]=temp;
  		}
break;
case 11:
#line 154 "SOURCE/AUTOMA/AutoParser.y"
	{
	source=yystack.l_mark[0].num;
	pre=true;
	}
break;
case 12:
#line 161 "SOURCE/AUTOMA/AutoParser.y"
	{
	dest=yystack.l_mark[0].num;
	}
break;
case 13:
#line 167 "SOURCE/AUTOMA/AutoParser.y"
	{
	transition=rs->getTR(std::string(yystack.l_mark[0].var));
	if (transition<0)
		{
		std::string tmp= "Error in the automaton: " + std::string(yystack.l_mark[0].var) +std::string(" is not a valid transition\n");
		ExceptionIO obj(tmp);
		throw (obj);
		}
	pre=false;
	}
break;
case 18:
#line 186 "SOURCE/AUTOMA/AutoParser.y"
	{
		 int p=rs->getPL(std::string(yystack.l_mark[-2].var));
		 if (p<0)
			{
			std::string tmp= "Error in the automaton: " + std::string(yystack.l_mark[-2].var) +std::string(" is not a valid place\n");
			ExceptionIO obj(tmp);
			throw (obj);
			}
		 if (pre)
			tmpPre[p].setMax(yystack.l_mark[0].num-1);
		 else
			tmpPost[p].setMax(yystack.l_mark[0].num-1);
    		}
break;
case 19:
#line 201 "SOURCE/AUTOMA/AutoParser.y"
	{
		int p=rs->getPL(std::string(yystack.l_mark[-2].var));
		if (p<0)
			{
			std::string tmp= "Error in the automaton: " + std::string(yystack.l_mark[-2].var) +std::string(" is not a valid place\n");
			ExceptionIO obj(tmp);
			throw(obj);
			} 
		if(pre)
			tmpPre[p].setMin(yystack.l_mark[0].num+1);
		else
			tmpPost[p].setMin(yystack.l_mark[0].num+1);
		}
break;
case 20:
#line 216 "SOURCE/AUTOMA/AutoParser.y"
	{
		int p=rs->getPL(std::string(yystack.l_mark[-2].var));
		if (p<0)
			{
			std::string tmp= "Error in the automaton: " + std::string(yystack.l_mark[-2].var) +std::string(" is not a valid place\n");
			ExceptionIO obj(tmp);
			throw(obj);
			}
		if (pre)
			tmpPre[p].set(yystack.l_mark[0].num,yystack.l_mark[0].num);
		else
			tmpPost[p].set(yystack.l_mark[0].num,yystack.l_mark[0].num);
		}
break;
#line 671 "SOURCE/AUTOMA/AutoParser.cpp"
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
