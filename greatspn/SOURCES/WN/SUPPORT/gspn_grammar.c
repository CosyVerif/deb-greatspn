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

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "TRANSL/wn_2.yac"
# include <stdio.h>
# include <string.h>
# include "../INCLUDE/const.h"
# include "../INCLUDE/struct.h"
# include "../INCLUDE/var_ext.h"
# include "../INCLUDE/macros.h"

extern void check_predicate();
extern void push_expression();
extern void push_predicate();
extern int evaluate_expression();
extern int optimized_set_token_marking();
extern int optimized_nextvec();
extern int set_token_marking();
extern int get_dynamic_from_total();
extern int nextvec();
extern int get_pl_in();
extern int get_index();
extern int get_marking_parameter_offset();
extern int fill_with_elements();
extern int already_exist();
extern int intersection();
extern int check_obj_name();
extern int get_class_card();
extern int get_obj_id();
extern int set_number_of_elements();
extern int get_proj_num();
extern int already_transformed();
extern void *ecalloc();
extern char *emalloc();
extern void emit();
extern void gen();
extern void out_error();
extern void insert_buf();

int ind,i,j,sbc_ind,tag ;
int objid;
int n_sbcl,numobj,count ;
int not_decl,stop,eqfl,relfl,distfl ;
int low_val,enn_sign=1,sign=1,prsign=1;
int proj_num;
int coef_val,card_val;
int pl,cl,disj;
int addm0,totm0;

int parsing_flag = UNKNOWN;
int exp_on = TRUE;

MDrate_p pmd = NULL;
MDrate_p mdptr = NULL;


Pred_p prd_h = NULL;
Pred_p prd_t = NULL;

Expr_p pcode_h = NULL;
Expr_p pcode_t = NULL;

struct MARKBUF * mpt = NULL;

char temp[MAX_BUFFER][MAX_TAG_SIZE];

char class_read[MAX_TAG_SIZE];
char class_name[MAX_TAG_SIZE];
char sbc_name[MAX_TAG_SIZE];
char buffer[MAX_TAG_SIZE];
char error_name[MAX_TAG_SIZE];
#line 87 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() parser(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() parser(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() parser(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() jjlex(void *YYLEX_PARAM)
# define YYLEX jjlex(YYLEX_PARAM)
#else
# define YYLEX_DECL() jjlex(void)
# define YYLEX jjlex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define DSC 257
#define O 258
#define US 259
#define CO 260
#define S 261
#define CARET 262
#define D 263
#define PD 264
#define ESCL 265
#define DISTANCE 266
#define POINT 267
#define ID 268
#define OBRCS 269
#define CBRCS 270
#define VBAR 271
#define MA 272
#define FU 273
#define NUM 274
#define STRING 275
#define OBRCK 276
#define CBRCK 277
#define MINUS 278
#define PLUS 279
#define COMMA 280
#define NE 281
#define EQ 282
#define LT 283
#define GT 284
#define LE 285
#define GE 286
#define OPAR 287
#define CPAR 288
#define COLON 289
#define MOLT 290
#define DIV 291
#define OR 292
#define AND 293
#define NOT 294
#define MD 295
#define TD 296
#define WHEN 297
#define EVER 298
#define MAXT 299
#define MINT 300
#define INV 301
#define SQRT 302
#define POW 303
#define COMB 304
#define FACT 305
#define SEMICOLON 306
#define REALNUM 307
#define NEWLINE 308
#define UNDERSCORE 309
#define DIESIS 310
#define FLUSH 311
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    7,    3,    8,    3,    9,   11,
    5,   12,   13,    5,    6,    6,   15,   15,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   18,   19,   17,
   17,   17,   17,   17,   14,   14,   16,   16,   20,   21,
    4,    4,    4,   22,   22,   24,    1,   26,    1,   23,
   23,   27,   28,   25,   25,   29,    2,   30,    2,   10,
   10,   31,   31,   32,   32,   34,   34,   34,   34,   34,
   34,   33,
};
static const short yylen[] = {                            2,
    2,    2,    2,    2,    0,    6,    0,    5,    0,    0,
   10,    0,    0,    9,    3,    1,    3,    1,    4,    4,
    6,    4,    6,    3,    1,    1,    1,    0,    0,    7,
    3,    6,    6,    2,    1,    1,    1,    1,    0,    0,
    6,    1,    0,    1,    0,    0,    3,    0,    5,    3,
    0,    0,    0,    5,    0,    0,    3,    0,    5,    3,
    1,    3,    1,    3,    3,    1,    1,    1,    1,    1,
    1,    1,
};
static const short yydefred[] = {                         0,
   46,   56,    0,    0,    0,    0,    0,    0,    0,   12,
    0,    3,    0,   39,   42,    4,   36,   35,   48,    0,
    0,   58,    0,    0,    7,    9,    0,    0,    0,    0,
   26,   27,    0,    0,    0,    0,    0,    0,    0,    0,
   25,    0,    0,    0,   18,   52,   47,    0,   57,    0,
    0,    0,    5,    0,    0,    0,    0,   63,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   34,
   50,    0,   37,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   67,   66,   68,   70,
   69,   71,    0,   49,   31,    0,   24,    0,    0,    0,
    0,    0,    0,    0,    0,   17,    0,   59,    0,    8,
    0,    0,   64,    0,    0,   62,   65,    0,    0,    0,
   19,   20,    0,    0,   22,    0,    0,    0,    6,   44,
   41,   29,    0,    0,    0,    0,   54,    0,    0,    0,
   32,   33,   21,   23,    0,    0,   30,   14,    0,   11,
};
static const short yydgoto[] = {                          5,
    6,    8,   12,   16,   13,   55,   81,   51,   52,   56,
  128,   24,  109,   72,   44,   75,   45,   96,  140,   28,
   85,  131,   21,    7,   47,   29,   76,  126,    9,   48,
   57,   58,   59,   93,
};
static const short yysindex[] = {                      -194,
    0,    0, -201, -272,    0,  -77, -257,  -77, -257,    0,
 -247,    0,  -94,    0,    0,    0,    0,    0,    0, -234,
 -243,    0, -243, -225,    0,    0, -231, -212, -257, -215,
    0,    0, -234, -223, -213, -210, -202, -193, -168, -165,
    0, -203, -198,  -85,    0,    0,    0, -257,    0, -212,
 -234, -161,    0, -212,  -77, -167, -166,    0,  -92, -243,
 -126, -271, -234, -234, -234, -234, -234, -234, -234,    0,
    0, -234,    0,    0, -234, -212, -243, -167, -256, -212,
 -234, -271, -283, -212, -124, -212,    0,    0,    0,    0,
    0,    0, -234,    0,    0, -112,    0, -260, -196, -267,
 -155, -149, -131, -108,  -85,    0, -167,    0, -115,    0,
 -167, -254,    0, -166, -144,    0,    0,  -90, -234, -234,
    0,    0, -234, -234,    0,  -96,  -82,  -69,    0,    0,
    0,    0, -106, -104, -102, -100,    0, -234,  -80,  -88,
    0,    0,    0,    0, -251, -234,    0,    0, -249,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,  187,    0,  210,    1,  211,    1,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,    3,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -172,    0,    0,    0,    1,    0,    0,
    0,    0,    0,    0, -125,  -65, -160,    0,    0,    3,
  -54,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,  -63,    0,    0,
    0,  -86,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -142,    0,  -62,    0,    0,    0,
  -61,    0,    0, -123,  217,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,  -20,    0,    0,    0,  -44,
    0,    0,    0,    8,  146,    0,  144,    0,    0,    0,
    0,    0,    6,    0,  -21,    0,    0,    0,    0,    0,
  136,  135,  129,    0,
};
#define YYTABLESIZE 282
static const short yytable[] = {                         43,
   51,   49,   55,   14,  113,   78,   17,   18,   84,   83,
   17,   18,   62,   19,   23,   22,   97,   17,   18,  119,
  121,   17,   18,   17,   18,   20,   17,   18,   17,   18,
   79,  107,   46,   82,   60,  111,   30,   15,   94,   31,
   32,   25,   98,   99,  100,  101,  102,  103,  104,  110,
   50,  129,   33,   77,  148,  108,  150,   53,   30,   61,
  112,   31,   32,   63,   34,   35,   36,   37,   38,   39,
   40,   70,   41,   64,   54,   42,   65,    1,    2,   17,
   18,   17,   18,  120,   66,   71,   34,   35,   36,   37,
   38,   39,   40,   67,   41,   10,   11,   42,  133,  134,
    3,    4,  135,  136,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   80,   16,   61,  145,   68,   16,
   16,   69,   17,   18,   84,  149,   86,   61,   17,   18,
  123,   61,  122,   16,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   95,   15,   17,   18,  124,   15,
   15,   72,  115,   60,  118,   72,   72,   72,   72,   72,
   72,  127,   72,   15,   60,  130,   72,   72,   60,   17,
   18,   17,   18,   17,   18,   17,   18,   17,   18,  125,
  137,  141,  147,  142,  132,  143,   43,  144,   87,   88,
   89,   90,   91,   92,   72,   72,   72,   72,   72,   72,
   17,   18,   26,   27,   73,   74,  138,  139,  146,    1,
    2,   40,   28,   13,   53,   10,   45,  105,  106,  114,
  116,  117,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   51,    0,   51,   51,
   55,   55,
};
static const short yycheck[] = {                         20,
    0,   23,    0,  276,  288,   50,  278,  279,  292,   54,
  278,  279,   33,    6,    9,    8,  288,  278,  279,  280,
  288,  278,  279,  278,  279,  283,  278,  279,  278,  279,
   51,   76,  276,   54,   29,   80,  271,  310,   60,  274,
  275,  289,   63,   64,   65,   66,   67,   68,   69,  306,
  276,  306,  287,   48,  306,   77,  306,  289,  271,  275,
   81,  274,  275,  287,  299,  300,  301,  302,  303,  304,
  305,  275,  307,  287,  287,  310,  287,  272,  273,  278,
  279,  278,  279,  280,  287,  284,  299,  300,  301,  302,
  303,  304,  305,  287,  307,  297,  298,  310,  119,  120,
  295,  296,  123,  124,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  276,  288,  277,  138,  287,  292,
  293,  287,  278,  279,  292,  146,  293,  288,  278,  279,
  280,  292,  288,  306,  277,  278,  279,  280,  281,  282,
  283,  284,  285,  286,  271,  288,  278,  279,  280,  292,
  293,  277,  277,  277,  267,  281,  282,  283,  284,  285,
  286,  277,  288,  306,  288,  310,  292,  293,  292,  278,
  279,  278,  279,  278,  279,  278,  279,  278,  279,  288,
  277,  288,  271,  288,  275,  288,    0,  288,  281,  282,
  283,  284,  285,  286,  281,  282,  283,  284,  285,  286,
  278,  279,  297,  298,  290,  291,  289,  277,  289,    0,
    0,  277,  267,  277,  277,  277,    0,   72,   75,   84,
   86,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  276,   -1,  278,  279,
  278,  279,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"DSC","O","US","CO","S","CARET",
"D","PD","ESCL","DISTANCE","POINT","ID","OBRCS","CBRCS","VBAR","MA","FU","NUM",
"STRING","OBRCK","CBRCK","MINUS","PLUS","COMMA","NE","EQ","LT","GT","LE","GE",
"OPAR","CPAR","COLON","MOLT","DIV","OR","AND","NOT","MD","TD","WHEN","EVER",
"MAXT","MINT","INV","SQRT","POW","COMB","FACT","SEMICOLON","REALNUM","NEWLINE",
"UNDERSCORE","DIESIS","FLUSH","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : grammar",
"grammar : MA marking",
"grammar : FU function",
"grammar : MD mdrate",
"grammar : TD transguard",
"$$1 :",
"mdrate : condlist EVER COLON $$1 kexpression SEMICOLON",
"$$2 :",
"mdrate : EVER COLON $$2 kexpression SEMICOLON",
"$$3 :",
"$$4 :",
"condlist : condlist WHEN $$3 OBRCK pred $$4 CBRCK COLON kexpression SEMICOLON",
"$$5 :",
"$$6 :",
"condlist : WHEN $$5 OBRCK pred $$6 CBRCK COLON kexpression SEMICOLON",
"kexpression : kexpression plusop vterm",
"kexpression : vterm",
"vterm : vterm mulop vfatt",
"vterm : vfatt",
"vfatt : INV OPAR kexpression CPAR",
"vfatt : SQRT OPAR kexpression CPAR",
"vfatt : POW OPAR kexpression COMMA kexpression CPAR",
"vfatt : FACT OPAR kexpression CPAR",
"vfatt : COMB OPAR kexpression COMMA kexpression CPAR",
"vfatt : OPAR kexpression CPAR",
"vfatt : REALNUM",
"vfatt : NUM",
"vfatt : STRING",
"$$7 :",
"$$8 :",
"vfatt : VBAR STRING $$7 POINT STRING $$8 VBAR",
"vfatt : VBAR STRING VBAR",
"vfatt : MAXT OPAR kexpression COMMA kexpression CPAR",
"vfatt : MINT OPAR kexpression COMMA kexpression CPAR",
"vfatt : DIESIS STRING",
"plusop : PLUS",
"plusop : MINUS",
"mulop : MOLT",
"mulop : DIV",
"$$9 :",
"$$10 :",
"transguard : OBRCK $$9 pred $$10 CBRCK opzRESET",
"transguard : DIESIS",
"transguard :",
"opzRESET : DIESIS",
"opzRESET :",
"$$11 :",
"marking : $$11 opzexpression opzguard",
"$$12 :",
"marking : marking plusop $$12 opzexpression opzguard",
"opzexpression : LT kexpression GT",
"opzexpression :",
"$$13 :",
"$$14 :",
"opzguard : OBRCK $$13 pred $$14 CBRCK",
"opzguard :",
"$$15 :",
"function : $$15 opzexpression opzguard",
"$$16 :",
"function : function plusop $$16 opzexpression opzguard",
"pred : pred OR pterm",
"pred : pterm",
"pterm : pterm AND pfatt",
"pterm : pfatt",
"pfatt : OPAR pred CPAR",
"pfatt : predop relop predop",
"relop : EQ",
"relop : NE",
"relop : LT",
"relop : LE",
"relop : GT",
"relop : GE",
"predop : kexpression",

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
#line 498 "TRANSL/wn_2.yac"
#include "../SUPPORT/lex.c"
void yyerror()
{
 fprintf(stdout,"Syntax error while parsing\n");
 switch(parsing_flag)
  {/* Tipo di errore */
   case TRANSITION :
	fprintf(stdout,"predicate of transition %s\n",TRANS_NAME(ntr));
	break;
   case PLACE :
	fprintf(stdout,"color domain of place %s\n",PLACE_NAME(npl));
	break;
   case MDRATE :
	fprintf(stdout,"MD rate definition of transition %s\n",TRANS_NAME(nmd));
	break;
   case FUNCTION :
	fprintf(stdout,"color function labeling arc connecting\n");
	fprintf(stdout,"place %s and transition %s\n",PLACE_NAME(pl_ind),TRANS_NAME(ntr));
	break;
   case COLOR_CLASS :
	fprintf(stdout,"color class definition %s\n",error_name);
	break;
   case STATIC_SUBCLASS :
	fprintf(stdout,"static subclass definition %s\n",error_name);
	break;
   case DYNAMIC_SUBCLASS :
	fprintf(stdout,"dynamic subclass definition %s\n",error_name);
	break;
   case INITIAL_MARKING :
	fprintf(stdout,"initial marking definition %s\n",error_name);
	break;
   default:
	break;
  }/* Tipo di errore */
 exit(1);
}
#line 495 "y.tab.c"

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
case 5:
#line 91 "TRANSL/wn_2.yac"
	{
	 pmd = (MDrate_p)emalloc(sizeof(struct MD_RATE));
	 pmd->next = mdptr;
	 mdptr = pmd;
	 pmd->guard = NULL;
	 pmd->code = NULL;
	 prd_h = prd_t = NULL;
	 pcode_h = pcode_t = NULL;
	}
break;
case 6:
#line 101 "TRANSL/wn_2.yac"
	{
	 if(exp_on)
          {
           emit(TYPEEND,"",0.0,0);
	   pmd->code = pcode_h;
          } 
         else
	  pmd->code = NULL;
	 tabt[nmd].md_rate_val = mdptr;
	 mdptr = NULL;
	}
break;
case 7:
#line 115 "TRANSL/wn_2.yac"
	{
	 pmd=(MDrate_p)emalloc(sizeof(struct MD_RATE));
	 pmd->next = mdptr;
	 mdptr = pmd;
	 pmd->guard = NULL;
	 pmd->code = NULL;
	 prd_h = prd_t = NULL;
	 pcode_h = pcode_t = NULL;
	}
break;
case 8:
#line 125 "TRANSL/wn_2.yac"
	{
         if(exp_on)
          {
	   emit(TYPEEND,"",0.0,0);
	   pmd->code = pcode_h;
          }
         else
          pmd->code = NULL;
	 tabt[nmd].md_rate_val = mdptr;
	 mdptr = NULL;
	}
break;
case 9:
#line 138 "TRANSL/wn_2.yac"
	{
	 pmd = (MDrate_p)emalloc(sizeof(struct MD_RATE));
	 pmd->next = mdptr;
	 mdptr = pmd;
	 pmd->guard = NULL;
	 pmd->code = NULL;
	 prd_h = prd_t = NULL;
	 pcode_h = pcode_t = NULL;
	}
break;
case 10:
#line 149 "TRANSL/wn_2.yac"
	{
	 gen(TYPEEND,"");
	 pmd->guard = prd_h;
	 check_predicate(pmd->guard,MDRATE);
	}
break;
case 11:
#line 156 "TRANSL/wn_2.yac"
	{
         if(exp_on)
          {
	   emit(TYPEEND,"",0.0,0);
	   pmd->code = pcode_h;
          }
         else
          pmd->code = NULL;
	}
break;
case 12:
#line 166 "TRANSL/wn_2.yac"
	{
	 pmd=(MDrate_p)emalloc(sizeof(struct MD_RATE));
	 pmd->next=mdptr;
	 mdptr=pmd;
	 pmd->guard = NULL;
	 pmd->code = NULL;
	 prd_h = prd_t = NULL;
	 pcode_h = pcode_t = NULL;
	}
break;
case 13:
#line 177 "TRANSL/wn_2.yac"
	{
	 gen(TYPEEND,"");
	 pmd->guard = prd_h;
	 check_predicate(pmd->guard,MDRATE);
	}
break;
case 14:
#line 184 "TRANSL/wn_2.yac"
	{
         if(exp_on)
          {
	   emit(TYPEEND,"",0.0,0);
	   pmd->code = pcode_h;
          }
         else
          pmd->code = NULL;
	}
break;
case 15:
#line 195 "TRANSL/wn_2.yac"
	{
	 emit(sign==1 ? TYPEPLUS : TYPEMINUS,"",0.0,0);
	}
break;
case 17:
#line 201 "TRANSL/wn_2.yac"
	{
	 emit(prsign==1 ? TYPEMOLT : TYPEDIV,"",0.0,0);
	}
break;
case 19:
#line 208 "TRANSL/wn_2.yac"
	{
         if(parse_DEF != MDRATE)
          {
           fprintf(stdout,"Error: INV rule, token %s floating in expression\n",str_in);
           exit(1);
          }
	 emit(TYPEINV,"",0.0,0);
	}
break;
case 20:
#line 217 "TRANSL/wn_2.yac"
	{
	 emit(TYPESQRT,"",0.0,0);
	}
break;
case 21:
#line 221 "TRANSL/wn_2.yac"
	{
	 emit(TYPEPOW,"",0.0,0);
	}
break;
case 22:
#line 225 "TRANSL/wn_2.yac"
	{
         emit(TYPEFACT,"",0.0,0);
        }
break;
case 23:
#line 229 "TRANSL/wn_2.yac"
	{
         emit(TYPECOMB,"",0.0,0);
        }
break;
case 25:
#line 234 "TRANSL/wn_2.yac"
	{
         if(parse_DEF != MDRATE)
          {
           fprintf(stdout,"Error: REALNUM rule token %s floating in expression\n",str_in);
           exit(1);
          }
	 emit(TYPEREALNUM,"",real_val,0);
	}
break;
case 26:
#line 243 "TRANSL/wn_2.yac"
	{
         emit(TYPENUM,str_in,atof(str_in),str_val);
        }
break;
case 27:
#line 247 "TRANSL/wn_2.yac"
	{
	 emit(TYPEPAR,str_in,0.0,0);
	}
break;
case 28:
#line 251 "TRANSL/wn_2.yac"
	{
#ifdef GSPN
	 fprintf(stdout,"Coloured marking definition is not allowed in GSPN specification\n");
         exit(1);
#endif
#ifdef SWN
         strcpy(class_name,str_in);
#endif
        }
break;
case 29:
#line 261 "TRANSL/wn_2.yac"
	{
#ifdef GSPN
	 fprintf(stdout,"Colour class cardinality is not allowed in GSPN specification\n");
         exit(1);
#endif
#ifdef SWN
         strcpy(sbc_name,str_in);
#endif
        }
break;
case 30:
#line 271 "TRANSL/wn_2.yac"
	{
#ifdef GSPN
	 fprintf(stdout,"Colour class cardinality is not allowed in GSPN specification\n");
         exit(1);
#endif
#ifdef SWN
         /* Controllo su esistenza della classe */
	 if((ind=get_index(class_name))==-1)
	  out_error(ERROR_MISSING_CLASS,0,0,0,0,class_name,NULL);
	 else
          {  
           /* Controllo su esistenza sottoclasse */
	   if((sbc_ind=already_exist(sbc_name,ind,STAT))==0)
	    out_error(ERROR_MISSING_STATIC,0,0,0,0,sbc_name,NULL);
	   else 
	    emit(TYPENUM,"",0.0,tabc[ind].sbclist[sbc_ind-1].card);
          }
#endif
        }
break;
case 31:
#line 291 "TRANSL/wn_2.yac"
	{
#ifdef GSPN
	 fprintf(stdout,"Colour class cardinality is not allowed in GSPN specification\n");
         exit(1);
#endif
#ifdef SWN
         /* Controllo su esistenza della classe */
         if((ind=get_index(str_in))==-1)
          {
           /* Controllo su esistenza sottoclasse */
           for(i=0,stop=FALSE;!stop && i<ncl;i++)
            if((ind=already_exist(str_in,i,STAT))!=0) stop=TRUE;
	   if(stop==FALSE)
	    out_error(ERROR_MISSING_CLASS,0,0,0,0,str_in,NULL);
	   else 
	    emit(TYPENUM,"",0.0,tabc[i-1].sbclist[ind-1].card);
           /* Questa cardinalita'e'quella della prima sottoclasse */
           /* trovata con quel nome                               */
          }
         else 
	  emit(TYPENUM,"",0.0,get_class_card(ind));
#endif
        }
break;
case 32:
#line 315 "TRANSL/wn_2.yac"
	{
	 emit(TYPEMAX,"",0.0,0);
	}
break;
case 33:
#line 319 "TRANSL/wn_2.yac"
	{
	 emit(TYPEMIN,"",0.0,0);
	}
break;
case 34:
#line 323 "TRANSL/wn_2.yac"
	{
#ifdef GSPN
	 emit(TYPEMARK,str_in,0.0,0);
#endif
#ifdef SWN
	 fprintf(stdout,"Place marking #%s is not allowed in SWN specification\n",str_in);
         exit(1);
#endif
	}
break;
case 35:
#line 334 "TRANSL/wn_2.yac"
	{
	 sign = 1;
	}
break;
case 36:
#line 338 "TRANSL/wn_2.yac"
	{
	 sign = -1;
	}
break;
case 37:
#line 343 "TRANSL/wn_2.yac"
	{
	 prsign = 1;
	}
break;
case 38:
#line 347 "TRANSL/wn_2.yac"
	{
	 prsign = 0;
	}
break;
case 39:
#line 352 "TRANSL/wn_2.yac"
	{
	 tabt[ntr].guard = NULL;
	 prd_h = prd_t = NULL;
	}
break;
case 40:
#line 357 "TRANSL/wn_2.yac"
	{
	 gen(TYPEEND,"");
	 tabt[ntr].guard = prd_h;
	}
break;
case 42:
#line 364 "TRANSL/wn_2.yac"
	{
	 tabt[ntr].reset = TRUE;
	}
break;
case 44:
#line 370 "TRANSL/wn_2.yac"
	{
	 tabt[ntr].reset = TRUE;
	}
break;
case 46:
#line 375 "TRANSL/wn_2.yac"
	{totm0=addm0=0;enn_sign=1;}
break;
case 48:
#line 376 "TRANSL/wn_2.yac"
	{ enn_sign = sign; sign=1;}
break;
case 50:
#line 378 "TRANSL/wn_2.yac"
	{
                emit(TYPEEND,"",0.0,0);
                if(parse_DEF == INITIAL_MARKING)
                 {
                  addm0 = evaluate_expression(pcode_h,NULL) * enn_sign;
                  push_expression(pcode_h,pcode_t);
                 }
                else if(parse_DEF==FUNCTION)
                 ptr->expression = pcode_h;
                pcode_h = pcode_t = NULL;
               }
break;
case 51:
#line 390 "TRANSL/wn_2.yac"
	{ 
                if(parse_DEF == INITIAL_MARKING) 
                 addm0 = enn_sign;
               }
break;
case 52:
#line 396 "TRANSL/wn_2.yac"
	{
	 prd_h = prd_t = NULL;
	}
break;
case 53:
#line 400 "TRANSL/wn_2.yac"
	{
         gen(TYPEEND,"");
         if(parse_DEF==FUNCTION)
          ptr->guard = prd_h;
         else if(parse_DEF==INITIAL_MARKING)
          {
	   addm0 *= verify_predicate_constraint(prd_h,NULL);
           push_predicate(prd_h,prd_t);
	   prd_h = prd_t = NULL;
           totm0 += addm0;
          }
	}
break;
case 55:
#line 414 "TRANSL/wn_2.yac"
	{
           if(parse_DEF==INITIAL_MARKING)
            totm0 += addm0;
          }
break;
case 56:
#line 419 "TRANSL/wn_2.yac"
	{
            ptr=(Coeff_p)emalloc(sizeof(struct ENN_COEFF));
            enn_sign=1;
            ptr->enn_coef = enn_sign;
	    ptr->guard = NULL;
            ptr->expression = NULL;
	    ptr->next = fun_ptr;/* Settare fun_ptr a NULL prima di parse */
	    fun_ptr = ptr;
           }
break;
case 58:
#line 429 "TRANSL/wn_2.yac"
	{
	    enn_sign = sign;
	    sign=1;
            ptr=(Coeff_p)emalloc(sizeof(struct ENN_COEFF));
            ptr->enn_coef = enn_sign;
	    ptr->guard = NULL;
            ptr->expression = NULL;
	    ptr->next = fun_ptr;/* Settare fun_ptr a NULL prima di parse */
	    fun_ptr = ptr;
           }
break;
case 60:
#line 442 "TRANSL/wn_2.yac"
	{
	 gen(TYPEOR,"");
	}
break;
case 62:
#line 450 "TRANSL/wn_2.yac"
	{
	 gen(TYPEAND,"");
	}
break;
case 65:
#line 461 "TRANSL/wn_2.yac"
	{
	    gen(relfl," ");
	   }
break;
case 66:
#line 466 "TRANSL/wn_2.yac"
	{
	 relfl = TYPEEQ;
	}
break;
case 67:
#line 470 "TRANSL/wn_2.yac"
	{
	 relfl = TYPENE;
	}
break;
case 68:
#line 474 "TRANSL/wn_2.yac"
	{
	 relfl = TYPELT;
	}
break;
case 69:
#line 478 "TRANSL/wn_2.yac"
	{
	 relfl = TYPELE;
	}
break;
case 70:
#line 482 "TRANSL/wn_2.yac"
	{
	 relfl = TYPEGT;
	}
break;
case 71:
#line 486 "TRANSL/wn_2.yac"
	{
	 relfl = TYPEGE;
	}
break;
case 72:
#line 491 "TRANSL/wn_2.yac"
	{
	 emit(TYPEEND,"",0.0,0);
         gen(TYPENUM,"");
         pcode_h = pcode_t = NULL;
        }
break;
#line 1173 "y.tab.c"
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
