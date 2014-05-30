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

#define YYPREFIX "yy"

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

#line 2 "lisp-obj_yacc.y"
  	#include <stdio.h>
	#include <string.h>
	
	#define LISP_OBJ_YACC	
	#include "attrib-yacc.h"
	
	#include "var-lex.h"
	#include "var-yacc.h"
	
	list backpacking = NULL;
	list curr = NULL;
	bool parsedGuard;	
	
#line 17 "lisp-obj_yacc.y"
typedef union
{
	int num_int;
	DomainObjPTR domain;
	char *String;
	enum ClassTypes classtype;
	struct {
		list elements;
		int num_el;
	       } tmp;
	ClassObjPTR class;
	guard_exprPTR guard_e;       
	guardPTR guard;
	enum Tipi_Relaz eq;
	TermPTR term;	
	ElTuplePTR el_tuple;
	TuplePTR tuple;
	arcPTR arc;
	char c;
	markPTR mrk;	
	MrkTuplePTR mt;
} YYSTYPE;
#line 71 "lisp-obj_yacc.c"
#define O 257
#define US 258
#define CO 259
#define MA 260
#define FU 261
#define OBRCK 262
#define CBRCK 263
#define MINUS 264
#define PLUS 265
#define COMMA 266
#define LESSER 267
#define GREATER 268
#define OPAR 269
#define CPAR 270
#define COLON 271
#define VBAR 272
#define S 273
#define MOLT 274
#define DIV 275
#define CARET 276
#define OR 277
#define AND 278
#define NOT 279
#define D 280
#define EQUAL 281
#define POINT 282
#define ESCL 283
#define MD 284
#define PD 285
#define TD 286
#define WHEN 287
#define EVER 288
#define SEMICOLON 289
#define REALNUM 290
#define DIESIS 291
#define ID 292
#define OBRCS 293
#define CBRCS 294
#define FLUSH 295
#define NEWLINE 296
#define NUM 297
#define STRING 298
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,   33,    0,    1,    1,   11,    6,
    6,    2,    2,    3,    3,    4,    4,    5,    5,   30,
   34,   30,   35,   31,   36,   31,   37,   32,   38,   32,
   29,   25,   25,   39,   28,   40,   28,   41,   10,   10,
   42,   27,   43,   27,   26,   26,    7,    7,    8,    8,
    9,    9,   12,   23,   23,   23,   23,   22,   22,   22,
   22,   13,   13,   18,   17,   17,   17,   15,   20,   16,
   21,   14,   19,   24,   24,
};
static const short yylen[] = {                            2,
    2,    2,    2,    2,    0,    3,    3,    1,    3,    2,
    1,    1,    1,    3,    1,    3,    6,    3,    1,    1,
    0,    2,    0,    5,    0,    7,    0,    4,    0,    2,
    1,    1,    1,    0,    6,    0,    8,    0,    4,    0,
    0,    2,    0,    4,    1,    3,    3,    1,    3,    1,
    3,    1,    3,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    5,    3,    3,    2,    3,    3,    3,
    3,    2,    2,    1,    0,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    5,    0,   12,   13,    0,    0,
    0,   11,    1,   74,   23,    4,    0,    0,    0,    0,
    2,    8,    0,    0,   19,    0,    0,   15,    0,    0,
   33,   32,    0,   22,    0,    0,    0,    0,    0,    0,
    6,    0,   16,    0,    0,   29,   25,    0,   34,    0,
    0,    7,    0,    0,    0,   50,   52,   58,   61,   59,
   60,    0,    0,   18,    0,   14,    0,    0,    0,   65,
   66,   41,    0,    0,    0,    9,    0,    0,    0,   62,
    0,    0,    0,    0,   73,    0,   27,   24,   30,   29,
    0,    0,   39,   36,   51,    0,   49,   63,   53,   71,
    0,   69,   17,    0,    0,   43,   35,   56,   54,   55,
   57,   45,    0,    0,   41,    0,   28,   26,    0,    0,
    0,   72,    0,    0,   64,    0,   70,   68,   46,   37,
};
static const short yydgoto[] = {                          6,
   23,   11,   29,   12,   26,   13,   54,   55,   56,   36,
   41,   57,   81,  108,  109,  110,  111,   58,   59,   60,
   61,   62,  112,   63,  123,  114,   91,   20,   21,   16,
   17,   67,   24,   18,   30,   69,  104,   68,   72,  115,
   37,   92,  119,
};
static const short yysindex[] = {                      -244,
 -255, -284, -284, -265,    0,    0,    0,    0, -246, -256,
 -231,    0,    0,    0,    0,    0, -185, -284,    0, -185,
    0,    0, -183, -178,    0, -260, -212,    0, -179, -177,
    0,    0, -284,    0, -184, -176, -174, -284, -206, -261,
    0, -205,    0, -169, -201,    0,    0, -216,    0, -261,
    0,    0, -261, -251, -182,    0,    0,    0,    0,    0,
    0, -228, -253,    0, -199,    0, -257, -284, -168,    0,
    0,    0, -249, -167, -221,    0, -261, -261, -166,    0,
 -284, -197, -165, -193,    0, -187,    0,    0,    0,    0,
 -200, -284,    0,    0,    0, -182,    0,    0,    0,    0,
 -189,    0,    0, -284, -195,    0,    0,    0,    0,    0,
    0,    0, -254, -185,    0, -162,    0,    0, -284, -188,
 -186,    0, -284, -194,    0, -185,    0,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0, -210, -203,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  103, -160, -202,  111,
    0,    0,  114,    0,    0,    0,    0,    0,  115,    0,
    0,    0, -151,    0,    0,    0,    0, -203,    0, -229,
    0,    0,    0,    0,    0,    0,    0,    1,    0, -229,
 -202,    0, -229,    0, -245,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -160,    0,    0,
    0,    0,    0,    0,    0,    0, -229, -229,    0,    0,
 -229,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -252,    0,    0,    0, -215,    0,    0,    0,    0,
    0,    0,    0, -160,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -191,    0,    0,    0,    0, -252,    0,
    0,    0, -252,    0,    0, -190,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  -43,   40,   42,   67,
    0,    0,    0,    0,    0,    0,  -18,    0,    0,    0,
    0,   38,   -1,    2,   41,    4,    9,    0,    0,    0,
    0,   36,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 269
static const short yytable[] = {                         34,
   67,    7,    8,   15,   19,   42,   73,   53,   87,   75,
   88,   76,   14,   93,    1,    2,    3,   48,   48,   35,
   75,  120,   82,   75,   48,   77,   83,   77,  121,   84,
   75,   48,   22,   43,   47,   14,   27,    9,   79,   51,
    4,    5,   10,  122,   85,   75,   75,   47,   95,   89,
   75,   25,   80,   75,   47,   77,   75,   33,   75,   38,
   38,   47,   21,   75,   40,  106,   28,  107,   75,   35,
   87,  106,  118,  130,   42,   44,   42,   44,   31,   32,
   70,   71,   39,   40,   44,  117,   45,   50,   48,   46,
   49,   52,   64,  113,   65,   78,   66,   86,   90,   94,
  100,   98,   20,  101,  102,   35,  103,  125,  116,  127,
   31,  128,   75,    3,   10,   75,   96,   74,   99,   97,
  113,  129,  126,  124,  113,  105,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   67,   67,   67,    0,   67,
};
static const short yycheck[] = {                         18,
    0,  257,  258,    2,    3,  266,   50,  269,  266,   53,
  268,  263,  297,  263,  259,  260,  261,  263,  273,   18,
  273,  276,  276,  276,  270,  277,  280,  277,  283,  283,
  283,  277,  298,  294,   33,  297,  293,  293,  267,   38,
  285,  286,  298,  298,  298,  298,  276,  263,  270,   68,
  280,  298,  281,  283,  270,  277,  267,   17,  262,  262,
   20,  277,  273,  267,  267,  266,  298,  268,  298,   68,
  266,  266,  268,  268,  266,  266,  268,  268,  264,  265,
  297,  298,  266,  262,  297,  104,  266,  262,  273,  267,
  267,  298,  298,   92,  264,  278,  298,  297,  267,  267,
  298,  268,    0,  269,  298,  104,  294,  270,  298,  298,
    0,  298,  273,    0,    0,  267,   77,   51,   81,   78,
  119,  123,  119,  115,  123,   90,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  264,  265,  266,   -1,  268,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"O","US","CO","MA","FU","OBRCK",
"CBRCK","MINUS","PLUS","COMMA","LESSER","GREATER","OPAR","CPAR","COLON","VBAR",
"S","MOLT","DIV","CARET","OR","AND","NOT","D","EQUAL","POINT","ESCL","MD","PD",
"TD","WHEN","EVER","SEMICOLON","REALNUM","DIESIS","ID","OBRCS","CBRCS","FLUSH",
"NEWLINE","NUM","STRING",
};
static const char *yyrule[] = {
"$accept : grammar",
"grammar : CO colors",
"grammar : FU function",
"grammar : PD placedom",
"grammar : MA marking",
"$$1 :",
"grammar : TD $$1 transdom",
"placedom : placedom COMMA STRING",
"placedom : STRING",
"transdom : OBRCK guard_expr CBRCK",
"colors : prefix namelist",
"colors : static",
"prefix : O",
"prefix : US",
"namelist : namelist COMMA STRING",
"namelist : STRING",
"static : OBRCS objects CBRCS",
"static : STRING OBRCS NUM MINUS NUM CBRCS",
"objects : objects COMMA STRING",
"objects : STRING",
"marking : objmark",
"$$2 :",
"marking : $$2 sterm",
"$$3 :",
"objmark : opzcoef $$3 LESSER oblist GREATER",
"$$4 :",
"objmark : objmark plusop opzcoef $$4 LESSER oblist GREATER",
"$$5 :",
"oblist : oblist COMMA $$5 sterm",
"$$6 :",
"oblist : $$6 sterm",
"function : funlist",
"plusop : PLUS",
"plusop : MINUS",
"$$7 :",
"funlist : opzcoef opzguardexpr LESSER $$7 funzseq GREATER",
"$$8 :",
"funlist : funlist plusop opzcoef opzguardexpr LESSER $$8 funzseq GREATER",
"$$9 :",
"opzguardexpr : $$9 OBRCK guard_expr CBRCK",
"opzguardexpr :",
"$$10 :",
"funzseq : $$10 kernel",
"$$11 :",
"funzseq : funzseq COMMA $$11 kernel",
"kernel : term",
"kernel : kernel plusop term",
"guard_expr : guard_expr OR guard_expr_a",
"guard_expr : guard_expr_a",
"guard_expr_a : guard_expr_a AND guard_expr_b",
"guard_expr_a : guard_expr_b",
"guard_expr_b : OPAR guard_expr CPAR",
"guard_expr_b : guard",
"guard : gterm eqsign gterm",
"term : nterm",
"term : pterm",
"term : xterm",
"term : sterm",
"gterm : gdterm",
"gterm : gnterm",
"gterm : gpterm",
"gterm : gxterm",
"eqsign : EQUAL",
"eqsign : LESSER GREATER",
"gdterm : opzcoef D OPAR STRING CPAR",
"sterm : opzcoef S NUM",
"sterm : opzcoef S STRING",
"sterm : opzcoef S",
"nterm : opzcoef ESCL STRING",
"gnterm : opzcoef ESCL STRING",
"pterm : opzcoef CARET STRING",
"gpterm : opzcoef CARET STRING",
"xterm : opzcoef STRING",
"gxterm : opzcoef STRING",
"opzcoef : NUM",
"opzcoef :",

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
#line 713 "lisp-obj_yacc.y"
    
void yyerror()
{
 fprintf(stdout,"Syntax error while parsing a color object\n");
 exit(1);
}
#line 400 "lisp-obj_yacc.c"
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
#line 68 "lisp-obj_yacc.y"
	{  
	   YACCparsedClass = yystack.l_mark[0].class;         
	}
break;
case 2:
#line 73 "lisp-obj_yacc.y"
	{
	   YACCparsedArc = yystack.l_mark[0].arc;
	}
break;
case 3:
#line 78 "lisp-obj_yacc.y"
	{  
	   reverse(&(yystack.l_mark[0].domain->class_list));
	   YACCparsedDomain = yystack.l_mark[0].domain;
	   YACCparsedDomain->place_name = YACCobj_name;
	}
break;
case 4:
#line 84 "lisp-obj_yacc.y"
	{
	  YACCparsedMarking = yystack.l_mark[0].mrk;
	}
break;
case 5:
#line 88 "lisp-obj_yacc.y"
	{
	   parsedGuard = TRUE;
	}
break;
case 6:
#line 92 "lisp-obj_yacc.y"
	{
	   YACCparsedGuard = yystack.l_mark[0].guard_e;
	   parsedGuard = FALSE;
	}
break;
case 7:
#line 99 "lisp-obj_yacc.y"
	{
	   list l;
	    
	   init_list(&l);  	   
	   if((find_key(gListClasses, (generic_ptr) yystack.l_mark[0].String , CmpClassName, &l))==OK)
	   {
	     head_insert(&(yyval.domain->class_list), DATA(l));
	     yyval.domain->num_el = yystack.l_mark[-2].domain->num_el+1;
	   }
	   else
	     Error(UNKN_CLASS_ERR, "yyparse", yystack.l_mark[0].String);	   
	
	}
break;
case 8:
#line 113 "lisp-obj_yacc.y"
	{
	   list l;
	   
	   init_list(&l);	   	   
	   yyval.domain = NewDomain(YACCobj_name, NULL, 0);
	   
	   if((find_key(gListClasses, (generic_ptr) yystack.l_mark[0].String , CmpClassName, &l))==OK)
	   {
	     head_insert(&(yyval.domain->class_list), DATA(l));
	     yyval.domain->num_el=1;
	   }
	   else
	     Error(UNKN_CLASS_ERR, "yyparse", yystack.l_mark[0].String);
	}
break;
case 9:
#line 133 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = yystack.l_mark[-1].guard_e;
	}
break;
case 10:
#line 143 "lisp-obj_yacc.y"
	{
	 reverse(&(yystack.l_mark[0].tmp.elements));
	 yyval.class = NewClass(YACCobj_name, yystack.l_mark[-1].classtype, yystack.l_mark[0].tmp.elements, NULL, yystack.l_mark[0].tmp.num_el);
	}
break;
case 11:
#line 148 "lisp-obj_yacc.y"
	{
	 reverse(&(yystack.l_mark[0].tmp.elements));
	 yyval.class = NewClass(YACCobj_name, SUBCLASS_TYPE, NULL, yystack.l_mark[0].tmp.elements, yystack.l_mark[0].tmp.num_el);
	 
	}
break;
case 12:
#line 156 "lisp-obj_yacc.y"
	{
	 yyval.classtype = ORD_CLASS_TYPE;
	}
break;
case 13:
#line 160 "lisp-obj_yacc.y"
	{
	 yyval.classtype = UNORD_CLASS_TYPE;
	}
break;
case 14:
#line 167 "lisp-obj_yacc.y"
	{ 
	  Class_elementPTR e;
	  
	  e= NewClassElement(yystack.l_mark[0].String);
	  head_insert(&(yystack.l_mark[-2].tmp.elements), (generic_ptr) e);
	  yyval.tmp.elements = yystack.l_mark[-2].tmp.elements;
	  yyval.tmp.num_el = yystack.l_mark[-2].tmp.num_el+1;
	}
break;
case 15:
#line 176 "lisp-obj_yacc.y"
	{ 
	  Class_elementPTR e;
	  
	  e= NewClassElement(yystack.l_mark[0].String);
	  init_list(&(yyval.tmp.elements));
	  head_insert(&(yyval.tmp.elements), (generic_ptr) e);
	  yyval.tmp.num_el = 1;
	}
break;
case 16:
#line 188 "lisp-obj_yacc.y"
	{
	 yyval.tmp = yystack.l_mark[-1].tmp;
	}
break;
case 17:
#line 194 "lisp-obj_yacc.y"
	{
	 Class_elementPTR e;
	 char *string;
	 int i;
	 
	 yyval.tmp.num_el = 0;
	 init_list(&(yyval.tmp.elements));
	 for(i = yystack.l_mark[-3].num_int; i <= yystack.l_mark[-1].num_int ; i++)
	 {
	  string = (char *)Emalloc(strlen(yystack.l_mark[-5].String)+ NUM_DIGIT_TKN +1);
	  string = Estrdup(yystack.l_mark[-5].String);
	  sprintf(string, "%s%d", string, i);	  
	  e = NewClassElement(string);
/*	  printf("\nName %s \n", e->name); */
	  head_insert(&(yyval.tmp.elements), (generic_ptr) e);
	  yyval.tmp.num_el++;
	 }
	}
break;
case 18:
#line 216 "lisp-obj_yacc.y"
	{ 
	  Class_elementPTR e;
	  
	  e= NewClassElement(yystack.l_mark[0].String);
	  head_insert(&(yystack.l_mark[-2].tmp.elements), (generic_ptr) e);
	  yyval.tmp.elements = yystack.l_mark[-2].tmp.elements;
	  yyval.tmp.num_el = yystack.l_mark[-2].tmp.num_el+1;
	}
break;
case 19:
#line 225 "lisp-obj_yacc.y"
	{ 
	  Class_elementPTR e;
	  
	  e= NewClassElement(yystack.l_mark[0].String);
	  init_list(&(yyval.tmp.elements));
	  head_insert(&(yyval.tmp.elements), (generic_ptr) e);
	  yyval.tmp.num_el = 1;
	}
break;
case 20:
#line 236 "lisp-obj_yacc.y"
	{
	  reverse(&(yystack.l_mark[0].mrk->mrk_operand));
	  yyval.mrk = yystack.l_mark[0].mrk;
	}
break;
case 21:
#line 241 "lisp-obj_yacc.y"
	{
	   if((curr = list_iterator(YACCparsedDomain->class_list, curr))==NULL)
	     printf("Error\n");
	}
break;
case 22:
#line 246 "lisp-obj_yacc.y"
	{
	  list l=NULL;	  
	  mrk_operandPTR o;

	  head_insert(&l, (generic_ptr) yystack.l_mark[-1].mrk);
	  o = NewMrkOperand(1, NewMrkTuple(l));  
	  l = NULL;
	  head_insert(&l, (generic_ptr) o);
	  yyval.mrk = NewMarking(YACCobj_name, l);
	}
break;
case 23:
#line 259 "lisp-obj_yacc.y"
	{
	  curr = NULL;
	}
break;
case 24:
#line 263 "lisp-obj_yacc.y"
	{ 
	  list l=NULL;	
	  mrk_operandPTR o;
	  
	  reverse(&(yystack.l_mark[-1].mt->term_list));
	  o = NewMrkOperand(yystack.l_mark[-4].num_int, yystack.l_mark[-1].mt );
	  head_insert(&l, (generic_ptr) o);
	  yyval.mrk = NewMarking(YACCobj_name, l);
	}
break;
case 25:
#line 273 "lisp-obj_yacc.y"
	{
	  curr = NULL;
	}
break;
case 26:
#line 277 "lisp-obj_yacc.y"
	{
	  mrk_operandPTR o;
	  
	  reverse(&(yystack.l_mark[-1].mt->term_list));
	  o = NewMrkOperand(yystack.l_mark[-4].num_int, yystack.l_mark[-1].mt );
	  if(yystack.l_mark[-5].c=='-')
	   o->coef = -(o->coef);
	  head_insert(&(yystack.l_mark[-6].mrk->mrk_operand), (generic_ptr) o);
	  yyval.mrk =yystack.l_mark[-6].mrk;
	}
break;
case 27:
#line 290 "lisp-obj_yacc.y"
	{
	  if((curr = list_iterator(YACCparsedDomain->class_list, curr))==NULL)
	    printf("Error\n");	
	}
break;
case 28:
#line 295 "lisp-obj_yacc.y"
	{	  
	  head_insert(&(yystack.l_mark[-3].mt->term_list), (generic_ptr) yystack.l_mark[0].term);
	  yyval.mt = yystack.l_mark[-3].mt;
	}
break;
case 29:
#line 300 "lisp-obj_yacc.y"
	{
	  if((curr = list_iterator(YACCparsedDomain->class_list, curr))==NULL)
	    printf("Error\n");	
	}
break;
case 30:
#line 305 "lisp-obj_yacc.y"
	{
	  list l=NULL;
	
	  head_insert(&l, (generic_ptr) yystack.l_mark[0].term);	  
	  yyval.mt = NewMrkTuple(l);	  
	}
break;
case 31:
#line 315 "lisp-obj_yacc.y"
	{ 
	  list curr = NULL;
	  list l = NULL;
	  TermPTR t;
	  VariablePTR  v;
	  
	  while ( (curr = list_iterator(backpacking, curr)) != NULL ){
	   t = (TermPTR) DATA(curr);	   
	   if((find_key(YACCParsedVarList, (generic_ptr) t->str, CmpVarName, &l)) == OK){
	    v = (VariablePTR) DATA(l);
	    t->class = v->class;	   
	   }
	   else  
	    Error(UNKN_VAR_ERR, "yyparse", t->str);
	  }
	  destroy(&backpacking, NULL);
	  reverse(&(yystack.l_mark[0].arc->operand));	
	  yyval.arc = yystack.l_mark[0].arc;
	}
break;
case 32:
#line 337 "lisp-obj_yacc.y"
	{
	 yyval.c = '+';
	}
break;
case 33:
#line 341 "lisp-obj_yacc.y"
	{
	 yyval.c = '-';
	}
break;
case 34:
#line 347 "lisp-obj_yacc.y"
	{
	 curr = NULL;
	}
break;
case 35:
#line 351 "lisp-obj_yacc.y"
	{
	 operandPTR o_ptr;
	 
	 reverse(&(yystack.l_mark[-1].tuple->el_list));	 	
	 o_ptr = NewOperand(yystack.l_mark[-5].num_int, yystack.l_mark[-4].guard_e, yystack.l_mark[-1].tuple);	 
	 yyval.arc = NewArcExpression(YACCparsedDomain, NULL );
	 head_insert(&(yyval.arc->operand),(generic_ptr) o_ptr);
	}
break;
case 36:
#line 361 "lisp-obj_yacc.y"
	{
	 curr = NULL;
	}
break;
case 37:
#line 365 "lisp-obj_yacc.y"
	{
	 operandPTR o_ptr;
	 
	 if(yystack.l_mark[-6].c=='-')
	     yystack.l_mark[-5].num_int = -yystack.l_mark[-5].num_int;
	 reverse(&(yystack.l_mark[-1].tuple->el_list)); 
	 o_ptr = NewOperand(yystack.l_mark[-5].num_int, yystack.l_mark[-4].guard_e, yystack.l_mark[-1].tuple);
	 head_insert(&(yystack.l_mark[-7].arc->operand),(generic_ptr) o_ptr);
	 yyval.arc = yystack.l_mark[-7].arc;
	}
break;
case 38:
#line 379 "lisp-obj_yacc.y"
	{
         parsedGuard = TRUE;
        }
break;
case 39:
#line 385 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = yystack.l_mark[-1].guard_e;
	 parsedGuard = FALSE;
	}
break;
case 40:
#line 390 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = NULL;
	}
break;
case 41:
#line 397 "lisp-obj_yacc.y"
	{ 
	   if((curr = list_iterator(YACCparsedDomain->class_list, curr))==NULL)
	     printf("Error\n");
	}
break;
case 42:
#line 402 "lisp-obj_yacc.y"
	{
	  
	   yyval.tuple = NewTuple(NULL);
	   reverse(&(yystack.l_mark[0].el_tuple->term_list));   
	   head_insert(&(yyval.tuple->el_list), (generic_ptr) yystack.l_mark[0].el_tuple);	   	   
	}
break;
case 43:
#line 409 "lisp-obj_yacc.y"
	{
	   if((curr = list_iterator(YACCparsedDomain->class_list, curr))==NULL)
	     printf("Error\n");
	}
break;
case 44:
#line 414 "lisp-obj_yacc.y"
	{
	   reverse(&(yystack.l_mark[0].el_tuple->term_list));   
	   head_insert(&(yystack.l_mark[-3].tuple->el_list), (generic_ptr) yystack.l_mark[0].el_tuple);
	   yyval.tuple=yystack.l_mark[-3].tuple;
	}
break;
case 45:
#line 422 "lisp-obj_yacc.y"
	{  
	   yyval.el_tuple = NewElTuple(NULL);
	   
	   /* printf("Term: %s \n", PrintTerm($1));*/
	   init_list(&(yyval.el_tuple->term_list));	   
	   head_insert(&(yyval.el_tuple->term_list), (generic_ptr) yystack.l_mark[0].term);
	   /* printf("El Tupla: %s \n", PrintElTuple($$));*/
	}
break;
case 46:
#line 431 "lisp-obj_yacc.y"
	{
	   if(yystack.l_mark[-1].c=='-')
	     yystack.l_mark[0].term->coef = -yystack.l_mark[0].term->coef; 
	   head_insert(&(yystack.l_mark[-2].el_tuple->term_list), (generic_ptr) yystack.l_mark[0].term);
	   yyval.el_tuple=yystack.l_mark[-2].el_tuple;
	}
break;
case 47:
#line 443 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = NewGuardExpr(L_OR);
	 yyval.guard_e->Val.Bi.L = yystack.l_mark[-2].guard_e;
	 yyval.guard_e->Val.Bi.R = yystack.l_mark[0].guard_e;     
	}
break;
case 48:
#line 449 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = yystack.l_mark[0].guard_e;
	}
break;
case 49:
#line 457 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = NewGuardExpr(L_AND);
	 yyval.guard_e->Val.Bi.L = yystack.l_mark[-2].guard_e;
	 yyval.guard_e->Val.Bi.R = yystack.l_mark[0].guard_e;     
	}
break;
case 50:
#line 463 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = yystack.l_mark[0].guard_e;
	}
break;
case 51:
#line 471 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = yystack.l_mark[-1].guard_e;
	}
break;
case 52:
#line 475 "lisp-obj_yacc.y"
	{
	 yyval.guard_e = NewGuardExpr(NO_OP); 
	 yyval.guard_e->Val.term = yystack.l_mark[0].guard;
         
	}
break;
case 53:
#line 484 "lisp-obj_yacc.y"
	{
	   yyval.guard = NewGuard(yystack.l_mark[-1].eq, yystack.l_mark[-2].term, yystack.l_mark[0].term);
	 #if DEBUG_UNFOLD
	   printf("La guardia %s\n", PrintGuard(yyval.guard));
	 #endif
        }
break;
case 54:
#line 495 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 55:
#line 499 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 56:
#line 503 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 57:
#line 507 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 58:
#line 513 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 59:
#line 517 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 60:
#line 521 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 61:
#line 525 "lisp-obj_yacc.y"
	{
	 yyval.term = yystack.l_mark[0].term;
	}
break;
case 62:
#line 532 "lisp-obj_yacc.y"
	{
	 yyval.eq = R_EQUAL;
	}
break;
case 63:
#line 537 "lisp-obj_yacc.y"
	{
	 yyval.eq = R_NOT_EQUAL;
	}
break;
case 64:
#line 544 "lisp-obj_yacc.y"
	{	  
	  list l=NULL;
	  VariablePTR v;
	  
	  if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[-1].String, CmpVarName, &l))==OK){
	    v = (VariablePTR) DATA(l);
	    yyval.term = NewTerm(yystack.l_mark[-4].num_int, D_TYPE, v->class, yystack.l_mark[-1].String);
	  } 
	  else
	  {	   	    
            yyval.term = NewTerm(yystack.l_mark[-4].num_int, D_TYPE, NULL, yystack.l_mark[-1].String);
	    head_insert(&backpacking, (generic_ptr) yyval.term);
	  }
 	}
break;
case 65:
#line 562 "lisp-obj_yacc.y"
	{
 	 printf("Warning non implemented function\n");
	 yyval.term = NULL;
 	}
break;
case 66:
#line 567 "lisp-obj_yacc.y"
	{
	 ClassObjPTR  cl;
	 list l;
	 
	 init_list(&l);	   
	 if((find_key(gListSubClasses, (generic_ptr) yystack.l_mark[0].String , CmpClassName, &l))==OK)
	   cl = (ClassObjPTR) DATA(l);
	 else
	   Error(UNKN_CLASS_ERR, "yyparse", yystack.l_mark[0].String);
	 cl = (ClassObjPTR) DATA(curr);	   
	 yyval.term = NewTerm(yystack.l_mark[-2].num_int, S_SUBCLASS_TYPE, cl, yystack.l_mark[0].String);	 

	}
break;
case 67:
#line 581 "lisp-obj_yacc.y"
	{	 
	 ClassObjPTR  cl;
	 
	 cl = (ClassObjPTR) DATA(curr);
	 yyval.term = NewTerm(yystack.l_mark[-1].num_int, S_TYPE, cl, ""); 
	 
	}
break;
case 68:
#line 592 "lisp-obj_yacc.y"
	{
	 VariablePTR  v;
	 ClassObjPTR  cl;
	 list l = NULL;
	 	   
	 cl = (ClassObjPTR) DATA(curr); 
	 yyval.term = NewTerm(yystack.l_mark[-2].num_int, SUCC_TYPE, cl, yystack.l_mark[0].String); 
	 if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) { 	   
	   v = NewVar(yystack.l_mark[0].String, cl);
           head_insert(&YACCParsedVarList, (generic_ptr) v); 
	 }
	}
break;
case 69:
#line 607 "lisp-obj_yacc.y"
	{
         VariablePTR  v;
         list l = NULL; 
	 	
	 if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) {
	   yyval.term = NewTerm(yystack.l_mark[-2].num_int, SUCC_TYPE, NULL, yystack.l_mark[0].String);	 	   
           head_insert(&backpacking, (generic_ptr) yyval.term); 
	 }
	 else{	   
	   v = (VariablePTR) DATA(l);
	   yyval.term = NewTerm(yystack.l_mark[-2].num_int, SUCC_TYPE, v->class, yystack.l_mark[0].String);	   
	 }

	}
break;
case 70:
#line 626 "lisp-obj_yacc.y"
	{
	 VariablePTR  v;
	 ClassObjPTR  cl;
	 list l = NULL;
	 	   
	 cl = (ClassObjPTR) DATA(curr); 
	 yyval.term = NewTerm(yystack.l_mark[-2].num_int, PRED_TYPE, cl, yystack.l_mark[0].String); 
	 if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) { 	   
	   v = NewVar(yystack.l_mark[0].String, cl);           
           head_insert(&YACCParsedVarList, (generic_ptr) v); 
	 }
	}
break;
case 71:
#line 641 "lisp-obj_yacc.y"
	{
         VariablePTR  v;
         list l = NULL;	
	 
	 if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) {
	   yyval.term = NewTerm(yystack.l_mark[-2].num_int, PRED_TYPE, NULL, yystack.l_mark[0].String);	 	   
           head_insert(&backpacking, (generic_ptr) yyval.term); 
	 }
	 else{	   
	   v = (VariablePTR) DATA(l);
	   yyval.term = NewTerm(yystack.l_mark[-2].num_int, PRED_TYPE, v->class, yystack.l_mark[0].String);	   
	 }

	}
break;
case 72:
#line 659 "lisp-obj_yacc.y"
	{
	 VariablePTR  v;
	 ClassObjPTR  cl;
	 list l = NULL;
	 	   
	 cl = (ClassObjPTR) DATA(curr); 
	 yyval.term = NewTerm(yystack.l_mark[-1].num_int, ID_TYPE, cl, yystack.l_mark[0].String); 
	 if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) { 	   
	   v = NewVar(yystack.l_mark[0].String, cl);           
           head_insert(&YACCParsedVarList, (generic_ptr) v);  	 
	   
	   
	 }
        }
break;
case 73:
#line 676 "lisp-obj_yacc.y"
	{
         VariablePTR  v;
	 ClassObjPTR  c;
	 list l = NULL;
	 
	 if((find_key(YACCParsedVarList, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) {
	   if((find_key(gListSubClasses, (generic_ptr) yystack.l_mark[0].String, CmpVarName, &l))==ERROR) {
	     yyval.term = NewTerm(yystack.l_mark[-1].num_int, ID_TYPE, NULL, yystack.l_mark[0].String);	 	   
             head_insert(&backpacking, (generic_ptr) yyval.term); 
	   }
	   else
	   {
	     c = (ClassObjPTR) DATA(l);
	     yyval.term = NewTerm(yystack.l_mark[-1].num_int, ID_TYPE, c, yystack.l_mark[0].String);
	   }  
	 }
	 else{	   
	   v = (VariablePTR) DATA(l);
	   yyval.term = NewTerm(yystack.l_mark[-1].num_int, ID_TYPE, v->class, yystack.l_mark[0].String);	   
	 }
	
        }
break;
case 74:
#line 702 "lisp-obj_yacc.y"
	{
	 yyval.num_int = yystack.l_mark[0].num_int;
	}
break;
case 75:
#line 706 "lisp-obj_yacc.y"
	{
	 yyval.num_int = 1;
	}
break;
#line 1291 "lisp-obj_yacc.c"
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
