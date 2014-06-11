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

#line 2 "TRANSL/wn.yac"
# include <stdio.h>
# include <string.h>
# include "../INCLUDE/const.h"
# include "../INCLUDE/struct.h"
# include "../INCLUDE/var_ext.h"
# include "../INCLUDE/macros.h"

extern void check_predicate();
extern void push_expression();
extern void push_predicate();
extern double evaluate_expression();
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

int read_domain[MAX_PLACE_DOMAIN];
int base[MAX_PLACE_DOMAIN];
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

#ifdef SWN
Obj_p start_list = NULL;
Obj_p ob_ptr = NULL;
#endif


Pred_p prd_h = NULL;
Pred_p prd_t = NULL;

Expr_p pcode_h = NULL;
Expr_p pcode_t = NULL;

struct MARKBUF * mpt = NULL;

#ifdef SWN
Dyn_p dpt = NULL;
#endif

char temp[MAX_BUFFER][MAX_TAG_SIZE];

char class_read[MAX_TAG_SIZE];
char class_name[MAX_TAG_SIZE];
char sbc_name[MAX_TAG_SIZE];
char buffer[MAX_TAG_SIZE];
char error_name[MAX_TAG_SIZE];
#line 98 "y.tab.c"

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
#define POINT 264
#define ESCL 265
#define ID 266
#define OBRCS 267
#define CBRCS 268
#define DISTANCE 269
#define VBAR 270
#define MA 271
#define FU 272
#define NUM 273
#define STRING 274
#define OBRCK 275
#define CBRCK 276
#define MINUS 277
#define PLUS 278
#define COMMA 279
#define NE 280
#define EQ 281
#define LT 282
#define GT 283
#define LE 284
#define GE 285
#define OPAR 286
#define CPAR 287
#define COLON 288
#define MOLT 289
#define DIV 290
#define OR 291
#define AND 292
#define NOT 293
#define MD 294
#define PD 295
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
    0,    0,    0,    0,    0,    0,    0,   10,    5,   11,
    5,   12,   14,    8,   15,   16,    8,    9,    9,   18,
   18,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   21,   22,   20,   20,   20,   20,   20,   17,   17,   19,
   19,   24,   26,    3,   28,    3,   25,   25,   29,   27,
   31,   32,   27,   30,   30,   23,   23,    6,    6,   33,
   34,    7,    7,    7,   35,   35,   36,   37,    2,    1,
    1,   39,   39,   44,   42,   45,   42,   43,   43,   43,
   43,   40,    4,    4,   48,   46,   50,   51,   46,   52,
   53,   47,   47,   55,   49,   56,   49,   54,   54,   57,
   57,   57,   57,   58,   58,   58,   59,   60,   41,   41,
   38,   38,   61,   62,   38,   38,   13,   13,   63,   63,
   64,   64,   66,   66,   66,   66,   66,   66,   65,   65,
   65,   65,   65,   67,   65,
};
static const short yylen[] = {                            2,
    2,    2,    2,    2,    2,    2,    2,    0,    6,    0,
    5,    0,    0,   10,    0,    0,    9,    3,    1,    3,
    1,    4,    4,    6,    4,    6,    3,    1,    1,    1,
    0,    0,    7,    3,    6,    6,    2,    1,    1,    1,
    1,    0,    0,    4,    0,    2,    3,    1,    0,    4,
    0,    0,    8,    3,    1,    1,    1,    3,    1,    0,
    0,    6,    1,    0,    1,    0,    0,    0,    7,    1,
    1,    4,    6,    0,    4,    0,    2,    1,    1,    2,
    2,    2,    1,    2,    0,    6,    0,    0,    9,    0,
    0,    5,    0,    0,    2,    0,    4,    1,    3,    1,
    1,    3,    1,    3,    3,    2,    3,    2,    1,    0,
    1,    2,    0,    0,    7,    3,    3,    1,    3,    1,
    3,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    4,    2,    2,    0,    7,
};
static const short yydefred[] = {                         0,
   67,    0,    0,    0,    0,    0,    0,    0,    2,    0,
    3,    0,    0,    0,  111,    0,    1,  109,    0,   71,
    0,    4,    0,    0,   15,    0,    5,    0,   59,    0,
   60,   63,    7,    0,   56,   57,   43,   51,   46,    0,
    0,  112,   39,   38,    0,   82,   76,   84,    0,   87,
    0,   10,   12,    0,    0,    0,   68,    0,    0,    0,
  116,    0,    0,    0,    0,   90,    0,    0,    0,    0,
    0,    8,   58,    0,    0,    0,    0,  129,  130,    0,
    0,    0,  120,    0,    0,   48,    0,    0,   55,    0,
    0,   76,   74,   72,    0,   78,   77,    0,   94,   88,
    0,    0,   29,   30,    0,    0,    0,    0,    0,    0,
    0,    0,   28,    0,    0,    0,   21,    0,    0,  133,
    0,  132,    0,    0,    0,    0,    0,  124,  123,  125,
  127,  126,  128,    0,    0,    0,   52,   50,    0,  114,
    0,    0,   80,   81,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   37,   11,
    0,   40,   41,    0,    0,    0,    0,  134,  121,    0,
    0,  119,  122,    0,   47,    0,   54,    0,   73,   75,
    0,   96,   86,    0,    0,    0,   98,  100,  101,  103,
    0,    0,   34,    0,   27,    0,    0,    0,    0,    0,
    0,    0,    0,   20,    0,    9,  131,    0,   65,   62,
   69,    0,  115,   92,    0,    0,    0,    0,  108,    0,
   94,    0,    0,    0,    0,   22,   23,    0,    0,   25,
    0,    0,    0,    0,  102,  104,  105,  107,   99,    0,
    0,   32,    0,    0,    0,    0,    0,    0,   53,   89,
   17,    0,   35,   36,   24,   26,    0,  135,   33,   14,
};
static const short yydgoto[] = {                          8,
   17,    9,   11,   22,   27,   30,   33,   28,  115,  119,
   70,   71,   81,  205,   51,  149,  161,  116,  164,  117,
  194,  252,   37,   12,   87,   58,   39,   13,   40,   90,
   59,  176,   56,  126,  210,   10,   85,   18,   19,   20,
  185,   64,   97,  142,   65,   24,   67,   49,  146,   68,
  148,   98,  181,  186,  147,  215,  187,  188,  189,  190,
   62,  178,   82,   83,   84,  134,  208,
};
static const short yysindex[] = {                      -247,
    0,    0, -244, -244, -282, -236, -271,    0,    0, -222,
    0, -115, -234, -196,    0, -161,    0,    0,  -74,    0,
 -255,    0, -156,  -74,    0, -172,    0, -117,    0, -160,
    0,    0,    0, -136,    0,    0,    0,    0,    0, -109,
 -129,    0,    0,    0, -244,    0,    0,    0,  -63,    0,
  -62,    0,    0, -120, -108, -174,    0,  -60,  -56,  -58,
    0,  -47,  -59, -265, -177,    0,  -57, -244, -174, -228,
  -55,    0,    0,  -53,  -67,  -52,  -54,    0,    0, -174,
  -73,  -66,    0,  -97,  -51,    0,  -50,  -49,    0, -257,
  -46,    0,    0,    0,  -68,    0,    0, -174,    0,    0,
  -73,  -44,    0,    0, -228,  -48,  -45,  -43,  -42,  -41,
  -40,  -39,    0,  -38, -216,  -82,    0, -174, -228,    0,
  -35,    0,  -34, -204, -174,  -28, -174,    0,    0,    0,
    0,    0,    0, -134, -244,  -32,    0,    0,  -25,    0,
 -169, -177,    0,    0,  -73, -119, -250,  -63,  -26,  -37,
 -153, -228, -228, -228, -228, -228, -228, -228,    0,    0,
 -228,    0,    0, -228,  -73, -210,  -36,    0,    0,  -66,
  -79,    0,    0,  -33,    0,  -24,    0,  -18,    0,    0,
  -21,    0,    0, -244, -159,  -74,    0,    0,    0,    0,
  -23,  -31,    0,  -30,    0,  -87,  -83, -145, -141,  -80,
  -77, -130,  -82,    0,  -20,    0,    0,  -17,    0,    0,
    0,  -15,    0,    0, -250,  -14,  -64,  -13,    0, -250,
    0, -228,  -11, -228, -228,    0,    0, -228, -228,    0,
  -22,  -10,   -3,  -74,    0,    0,    0,    0,    0, -106,
 -208,    0, -128, -126, -124, -122, -228,  -16,    0,    0,
    0,   -1,    0,    0,    0,    0, -197,    0,    0,    0,
};
static const short yyrindex[] = {                         0,
    0, -173, -252, -254,    0,    0,  227,    0,    0,    0,
    0,    0,    1,    0,    0,    0,    0,    0,  235,    0,
    0,    0, -164,  267,    0,    0,    0,    0,    0,  270,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8,    0,    0,    0,   -9,    0,    0,    0,   -8,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -113,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2, -184,    0,    0,    0,    0,  275,    0,    0,    0,
    0,    0,    0,    0, -105,    0,    0,    0,    0,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -246,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    0, -144,   -8,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    0, -183,
  277,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    9,    0, -104,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -243,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -144,    0, -107,    0,    0, -144,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -90,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0, -102,    0,
    0,    0,  -61,    0,    0,    0,  -19,  121,    0,  120,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  150,    0,    0,
   -2,  194,  145,    0,    0,    0,  140,    0,   68,    0,
    0,    0,    0,   75,    0,    0,   71,    0,    0,    0,
    0,    0,  167,  166,  160,    0,    0,
};
#define YYTABLESIZE 294
static const short yytable[] = {                         45,
   21,   23,  151,   31,   50,   46,  110,  101,  110,    1,
  138,  184,    2,   93,   25,   26,  166,   94,  124,   14,
  110,  139,   15,    3,    4,   14,   47,  110,   15,  110,
   19,   19,   19,   18,   18,   18,  145,   29,   32,   38,
   19,  102,   63,   18,  103,  104,    5,    6,    7,  196,
  197,  198,  199,  200,  201,  202,  165,  105,   16,   19,
   43,   44,   18,   34,   16,  100,   43,   44,   43,   44,
  106,  107,  108,  109,  110,  111,  112,   41,  113,   43,
   44,  114,  169,   95,   42,   42,  125,   74,   75,  160,
   76,  118,  117,   45,   77,  206,   96,  251,   78,   79,
   45,  217,  118,  117,   48,  218,  118,  117,  260,   93,
   85,   80,   42,  179,  219,   52,  110,   85,   55,  241,
  110,  243,  244,   43,   44,  245,  246,   74,   75,  110,
   76,   43,   44,  195,   77,   43,   44,   57,   78,   79,
   61,  226,   35,   36,  257,  227,   43,   44,   43,   44,
   43,   44,   43,   44,   43,   44,  230,   60,  253,  182,
  254,  110,  255,  183,  256,   73,  220,   72,  110,  106,
  106,  106,  182,   79,   95,  106,  250,   79,   95,   53,
   54,  216,  128,  129,  130,  131,  132,  133,   97,   43,
   44,  224,   97,   43,   44,  225,   43,   44,  228,   43,
   44,  229,   43,   44,  143,  144,  162,  163,  236,  237,
   88,   66,   69,   86,  220,   89,   91,  125,  121,  118,
  120,  122,   92,  137,   99,  127,   64,  140,  136,  150,
  209,  123,  193,  223,   70,  159,  135,  152,  167,  168,
  153,  175,  154,  155,  156,  157,  158,  171,  177,  192,
  207,  213,  212,  211,  214,  231,  222,  233,  221,  235,
  238,  232,  242,  248,  249,  247,   83,   49,  259,    6,
  258,  113,  110,   93,   44,   31,   66,   61,   16,   91,
   13,  203,  110,  204,  174,  141,  180,  191,  240,  234,
  239,  170,  172,  173,
};
static const short yycheck[] = {                         19,
    3,    4,  105,  275,   24,  261,  261,   69,  261,  257,
  268,  262,  260,  279,  297,  298,  119,  283,   80,  270,
  275,  279,  273,  271,  272,  270,  282,  282,  273,  282,
  277,  278,  279,  277,  278,  279,   98,  274,  310,  274,
  287,  270,   45,  287,  273,  274,  294,  295,  296,  152,
  153,  154,  155,  156,  157,  158,  118,  286,  309,  306,
  277,  278,  306,  286,  309,   68,  277,  278,  277,  278,
  299,  300,  301,  302,  303,  304,  305,  274,  307,  277,
  278,  310,  287,  261,  258,  259,  291,  262,  263,  306,
  265,  276,  276,  267,  269,  306,  274,  306,  273,  274,
  274,  261,  287,  287,  261,  265,  291,  291,  306,  279,
  275,  286,  274,  283,  274,  288,  261,  282,  279,  222,
  265,  224,  225,  277,  278,  228,  229,  262,  263,  274,
  265,  277,  278,  287,  269,  277,  278,  274,  273,  274,
  270,  287,  258,  259,  247,  287,  277,  278,  277,  278,
  277,  278,  277,  278,  277,  278,  287,  267,  287,  279,
  287,  275,  287,  283,  287,  274,  186,  288,  282,  277,
  278,  279,  279,  279,  279,  283,  283,  283,  283,  297,
  298,  184,  280,  281,  282,  283,  284,  285,  279,  277,
  278,  279,  283,  277,  278,  279,  277,  278,  279,  277,
  278,  279,  277,  278,  273,  274,  289,  290,  273,  274,
  267,  275,  275,  274,  234,  274,  264,  291,  286,  275,
  274,  274,  282,  273,  282,  292,    0,  274,  279,  274,
  310,  286,  270,  264,    0,  274,  288,  286,  274,  274,
  286,  274,  286,  286,  286,  286,  286,  276,  274,  276,
  287,  270,  277,  287,  276,  276,  288,  273,  282,  274,
  274,  279,  274,  274,  268,  288,    0,  267,  270,    0,
  287,  264,  282,  282,    0,  264,    0,  276,  276,  276,
  276,  161,  274,  164,  135,   92,  142,  148,  221,  215,
  220,  125,  127,  134,
};
#define YYFINAL 8
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
"D","POINT","ESCL","ID","OBRCS","CBRCS","DISTANCE","VBAR","MA","FU","NUM",
"STRING","OBRCK","CBRCK","MINUS","PLUS","COMMA","NE","EQ","LT","GT","LE","GE",
"OPAR","CPAR","COLON","MOLT","DIV","OR","AND","NOT","MD","PD","TD","WHEN",
"EVER","MAXT","MINT","INV","SQRT","POW","COMB","FACT","SEMICOLON","REALNUM",
"NEWLINE","UNDERSCORE","DIESIS","FLUSH","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : grammar",
"grammar : MA marking",
"grammar : DSC dynamic_subclass",
"grammar : CO colors",
"grammar : FU function",
"grammar : MD mdrate",
"grammar : PD placedom",
"grammar : TD transdom",
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
"colors : $$9 prefix $$10 namelist",
"$$11 :",
"colors : $$11 static",
"namelist : namelist COMMA STRING",
"namelist : STRING",
"$$12 :",
"static : $$12 OBRCS objects CBRCS",
"$$13 :",
"$$14 :",
"static : STRING $$13 OBRCS NUM $$14 MINUS NUM CBRCS",
"objects : objects COMMA STRING",
"objects : STRING",
"prefix : O",
"prefix : US",
"placedom : placedom COMMA STRING",
"placedom : STRING",
"$$15 :",
"$$16 :",
"transdom : OBRCK $$15 pred $$16 CBRCK opzRESET",
"transdom : DIESIS",
"transdom :",
"opzRESET : DIESIS",
"opzRESET :",
"$$17 :",
"$$18 :",
"dynamic_subclass : $$17 OPAR STRING $$18 COLON coefficient_type CPAR",
"marking : objmark",
"marking : shortmark",
"objmark : coefficient LT oblist GT",
"objmark : objmark plusop coefficient LT oblist GT",
"$$19 :",
"oblist : oblist COMMA $$19 obj",
"$$20 :",
"oblist : $$20 obj",
"obj : STRING",
"obj : S",
"obj : S NUM",
"obj : S STRING",
"shortmark : coefficient S",
"function : funlist",
"function : coefficient S",
"$$21 :",
"funlist : coefficient $$21 opzguard LT funzseq GT",
"$$22 :",
"$$23 :",
"funlist : funlist plusop $$22 coefficient $$23 opzguard LT funzseq GT",
"$$24 :",
"$$25 :",
"opzguard : OBRCK $$24 pred $$25 CBRCK",
"opzguard :",
"$$26 :",
"funzseq : $$26 kernel",
"$$27 :",
"funzseq : funzseq COMMA $$27 kernel",
"kernel : term",
"kernel : kernel plusop term",
"term : sterm",
"term : nterm",
"term : CARET coefficient STRING",
"term : xterm",
"sterm : coefficient S NUM",
"sterm : coefficient S STRING",
"sterm : coefficient S",
"nterm : coefficient ESCL STRING",
"xterm : coefficient STRING",
"coefficient : coefficient_type",
"coefficient :",
"coefficient_type : NUM",
"coefficient_type : UNDERSCORE STRING",
"$$28 :",
"$$29 :",
"coefficient_type : VBAR STRING $$28 POINT STRING $$29 VBAR",
"coefficient_type : VBAR STRING VBAR",
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
"predop : NUM",
"predop : STRING",
"predop : D OPAR STRING CPAR",
"predop : ESCL STRING",
"predop : CARET STRING",
"$$30 :",
"predop : DISTANCE OPAR STRING $$30 COMMA STRING CPAR",

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
#line 1292 "TRANSL/wn.yac"
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
#line 622 "y.tab.c"

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
case 8:
#line 108 "TRANSL/wn.yac"
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
case 9:
#line 118 "TRANSL/wn.yac"
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
case 10:
#line 132 "TRANSL/wn.yac"
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
case 11:
#line 142 "TRANSL/wn.yac"
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
case 12:
#line 155 "TRANSL/wn.yac"
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
case 13:
#line 166 "TRANSL/wn.yac"
	{
	 gen(TYPEEND,"");
	 pmd->guard = prd_h;
	 check_predicate(pmd->guard,MDRATE);
	}
break;
case 14:
#line 173 "TRANSL/wn.yac"
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
#line 183 "TRANSL/wn.yac"
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
case 16:
#line 194 "TRANSL/wn.yac"
	{
	 gen(TYPEEND,"");
	 pmd->guard = prd_h;
	 check_predicate(pmd->guard,MDRATE);
	}
break;
case 17:
#line 201 "TRANSL/wn.yac"
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
case 18:
#line 212 "TRANSL/wn.yac"
	{
	 emit(sign==1 ? TYPEPLUS : TYPEMINUS,"",0.0,0);
	}
break;
case 20:
#line 218 "TRANSL/wn.yac"
	{
	 emit(prsign==1 ? TYPEMOLT : TYPEDIV,"",0.0,0);
	}
break;
case 22:
#line 225 "TRANSL/wn.yac"
	{
         if(parse_DEF != MDRATE)
          {
           fprintf(stdout,"Error: INV rule, token %s floating in expression\n",str_in);
           exit(1);
          }
	 emit(TYPEINV,"",0.0,0);
	}
break;
case 23:
#line 234 "TRANSL/wn.yac"
	{
	 emit(TYPESQRT,"",0.0,0);
	}
break;
case 24:
#line 238 "TRANSL/wn.yac"
	{
	 emit(TYPEPOW,"",0.0,0);
	}
break;
case 25:
#line 242 "TRANSL/wn.yac"
	{
         emit(TYPEFACT,"",0.0,0);
        }
break;
case 26:
#line 246 "TRANSL/wn.yac"
	{
         emit(TYPECOMB,"",0.0,0);
        }
break;
case 28:
#line 251 "TRANSL/wn.yac"
	{
         if(parse_DEF != MDRATE)
          {
           fprintf(stdout,"Error: REALNUM rule token %s floating in expression\n",str_in);
           exit(1);
          }
	 emit(TYPEREALNUM,"",real_val,0);
	}
break;
case 29:
#line 260 "TRANSL/wn.yac"
	{
         emit(TYPENUM,str_in,atof(str_in),str_val);
        }
break;
case 30:
#line 264 "TRANSL/wn.yac"
	{
	 emit(TYPEPAR,str_in,0.0,0);
	}
break;
case 31:
#line 268 "TRANSL/wn.yac"
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
case 32:
#line 278 "TRANSL/wn.yac"
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
case 33:
#line 288 "TRANSL/wn.yac"
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
case 34:
#line 308 "TRANSL/wn.yac"
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
case 35:
#line 332 "TRANSL/wn.yac"
	{
	 emit(TYPEMAX,"",0.0,0);
	}
break;
case 36:
#line 336 "TRANSL/wn.yac"
	{
	 emit(TYPEMIN,"",0.0,0);
	}
break;
case 37:
#line 340 "TRANSL/wn.yac"
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
case 38:
#line 351 "TRANSL/wn.yac"
	{
	 sign = 1;
	}
break;
case 39:
#line 355 "TRANSL/wn.yac"
	{
	 sign = -1;
	}
break;
case 40:
#line 360 "TRANSL/wn.yac"
	{
	 prsign = 1;
	}
break;
case 41:
#line 364 "TRANSL/wn.yac"
	{
	 prsign = 0;
	}
break;
case 42:
#line 369 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
          {
	   /* controllo ripetizione nome classi di colori */
	   for(ind=0;ind<ncl;ind++)
            {
             if(strcmp(tabc[ind].col_name,bufname)==0)
	      {/* Errore */
	       out_error(ERROR_CLASS_REDECLARATION,0,0,0,0,bufname,NULL);
	      }/* Errore */
	    }
	   tabc[ncl].col_name = (char *)ecalloc(strlen(bufname)+1,sizeof(char));
	   strcpy(tabc[ncl].col_name,bufname);
	 }
	}
break;
case 43:
#line 385 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  tabc[ncl].type=str_val;
	}
break;
case 44:
#line 390 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   tot_sbc_num+=n_sbcl;
	   tabc[ncl].sbc_num=n_sbcl;
	   tabc[ncl].sbclist=(Static_p)ecalloc(n_sbcl,sizeof(struct STATICSBC));
	   for(ind=0;ind<tabc[ncl].sbc_num;ind++)
	    {
	     tabc[ncl].sbclist[ind].name =
	       (char *)ecalloc(strlen(temp[ind])+1,sizeof(char));
	     strcpy(tabc[ncl].sbclist[ind].name,temp[ind]);
	     tabc[ncl].sbclist[ind].card = 0;
	     tabc[ncl].sbclist[ind].dynlist=NULL;
	    }
	  }
         if(parse_DEF == FALSE || parse_DEF == COLOR_CLASS)
	  ncl++ ;
	}
break;
case 45:
#line 409 "TRANSL/wn.yac"
	{
	 parsing_flag = STATIC_SUBCLASS;
        }
break;
case 47:
#line 415 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	  /* controllo ripetizione nome sottoclassi */
	   for(ind=0;ind<n_sbcl;ind++)
            {
             if(strcmp(temp[ind],str_in)==0)
	      {/* Errore */
	       out_error(ERROR_TWICE_THE_SAME_STATIC,0,0,0,0,str_in,NULL);
	      }/* Errore */
            }
	   strcpy(temp[n_sbcl],str_in);
	   n_sbcl++;
	  }
	}
break;
case 48:
#line 431 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   strcpy(temp[0],str_in);
	   n_sbcl=1;
	  }
	}
break;
case 49:
#line 440 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   for(i=0,stop=FALSE;!stop && i<ncl;i++)
	    if((ind=already_exist(bufname,i,STAT))!=0) stop=TRUE;
	   if(stop==FALSE)
	    {
	     not_decl=TRUE;
	     sbc_pun=(struct SBCBUF*)emalloc(sizeof(struct SBCBUF));
	     strcpy(sbc_pun->name,bufname);
	    }
	   else
	    {
	     tabc[i-1].sbclist[ind-1].name =
	      (char *)ecalloc(strlen(bufname)+1,sizeof(char));
	     strcpy(tabc[i-1].sbclist[ind-1].name,bufname);
	    }
	  }
	}
break;
case 50:
#line 460 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   if(not_decl)
	    {
	     sbc_pun->card=numobj;
	     sbc_pun->obj_list=start_list;
	     insert_buf(sbc_pun);
	    }
	   else
	    {
	     if(tabc[i-1].sbclist[ind-1].card==0)
	      {
	       sbc_def_num++;
	       tabc[i-1].sbclist[ind-1].obj_list=start_list;
	       if((disj=intersection(tabc[i-1].sbclist,ind-1,tabc[i-1].sbc_num))<0)
	        {/* Errore */
                 disj++;disj=-disj;
	         out_error(ERROR_INTERSECTION,0,0,i-1,0,GET_STATIC_NAME(i-1,ind-1),GET_STATIC_NAME(i-1,disj));
	        }/* Errore */
	       tabc[i-1].sbclist[ind-1].card=numobj;
	      }
	     else
	      {/* Errore */
	       out_error(ERROR_REDEFINITION,0,0,i-1,ind-1,NULL,NULL);
	      }/* Errore */
	    }
	   start_list=NULL;
	   not_decl=FALSE;
	  }
	}
break;
case 51:
#line 492 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   for(i=0,stop=FALSE;!stop && i<ncl;i++)
	    if((ind=already_exist(bufname,i,STAT))!=0) stop=TRUE;
	   if(stop==FALSE)
	    {
	     not_decl=TRUE;
	     sbc_pun=(struct SBCBUF *)emalloc(sizeof(struct SBCBUF));
	     strcpy(sbc_pun->name,bufname);
	     strcpy(sbc_pun->obj_name,str_in);
	     sbc_pun->obj_list=NULL;
	    }
	   else
	    {
	     tabc[i-1].sbclist[ind-1].name =
	         (char *)ecalloc(strlen(bufname)+1,sizeof(char));
	     tabc[i-1].sbclist[ind-1].obj_name =
	         (char *)ecalloc(strlen(str_in)+1,sizeof(char));
	     strcpy(tabc[i-1].sbclist[ind-1].name,bufname);
	     strcpy(tabc[i-1].sbclist[ind-1].obj_name,str_in);
	     tabc[i-1].sbclist[ind-1].obj_list=NULL;
	    }
	  }
	}
break;
case 52:
#line 518 "TRANSL/wn.yac"
	{ 
	 if(parse_DEF == COLOR_CLASS)
	  low_val=str_val; 
	}
break;
case 53:
#line 523 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   if(str_val<low_val)
	    {/* Errore */
	     out_error(ERROR_OBJECT_DESCRIPTION,0,0,0,0,bufname,NULL);
	    }/* Errore */
	   if(not_decl)
	    {
	     sbc_pun->card=str_val-low_val+1;
	     sbc_pun->low=low_val;
	     insert_buf(sbc_pun);
	    }
	   else
	    {
	     if(tabc[i-1].sbclist[ind-1].card==0)
	      {
	       sbc_def_num++;
	       tabc[i-1].sbclist[ind-1].card=str_val-low_val+1;
	       tabc[i-1].sbclist[ind-1].low=low_val;
	       if((disj=intersection(tabc[i-1].sbclist,ind-1,tabc[i-1].sbc_num))<0)
	        {/* Errore */
                 disj++;disj=-disj;
	         out_error(ERROR_INTERSECTION,0,0,i-1,0,GET_STATIC_NAME(i-1,ind-1),GET_STATIC_NAME(i-1,disj));
	        }/* Errore */
	      }
	     else
	      {/* Errore */
	       out_error(ERROR_REDEFINITION,0,0,i-1,ind-1,NULL,NULL);
	      }/* Errore */
	    }
	   not_decl=FALSE;
	  }
	}
break;
case 54:
#line 559 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   if(check_obj_name(str_in,start_list)==-1)
	    {/* Errore */
	     out_error(ERROR_OBJECT_REDECLARATION,0,0,0,0,str_in,NULL);
	    }/* Errore */
	   ob_ptr=(Obj_p)emalloc(sizeof(struct OBJ));
	   ob_ptr->nome = (char *)ecalloc(strlen(str_in)+1,sizeof(char));
	   ob_ptr->next=start_list;
	   start_list=ob_ptr;
	   strcpy(ob_ptr->nome,str_in);
	   numobj++;
	  }
	}
break;
case 55:
#line 575 "TRANSL/wn.yac"
	{
	 if(parse_DEF == COLOR_CLASS)
	  {
	   ob_ptr=(Obj_p)emalloc(sizeof(struct OBJ));
	   ob_ptr->nome = (char *)ecalloc(strlen(str_in)+1,sizeof(char));
	   ob_ptr->next=start_list;
	   start_list=ob_ptr;
	   strcpy(ob_ptr->nome,str_in);
	   numobj=1;
	  }
	}
break;
case 56:
#line 588 "TRANSL/wn.yac"
	{ 
	 if(parse_DEF == COLOR_CLASS)
	  n_ord++; 
	}
break;
case 57:
#line 593 "TRANSL/wn.yac"
	{ 
	 if(parse_DEF == COLOR_CLASS)
	  n_unord++;
        }
break;
case 58:
#line 599 "TRANSL/wn.yac"
	{/* Parsificazione del dominio di un posto */
	 if((ind=get_index(str_in))==-1)
	  {/* Errore */
	   out_error(ERROR_UNEXISTING_CLASS,npl,0,0,0,str_in,NULL);
	  }/* Errore */
	 tabp[npl].comp_num++;
	 if(tabp[npl].comp_num > MAX_PLACE_DOMAIN)
	  {/* Errore */
	   out_error(ERROR_LOW_MAX_PLACE,npl,0,0,0,NULL,NULL);
	  }/* Errore */
	 read_domain[tag] = ind;
	 tag++;
	}
break;
case 59:
#line 613 "TRANSL/wn.yac"
	{/* Parsificazione del dominio di un posto */
	 if((ind=get_index(str_in))==-1)
	  {/* Errore */
	   out_error(ERROR_UNEXISTING_CLASS,npl,0,0,0,str_in,NULL);
	  }/* Errore */
	 tag = 0;
	 tabp[npl].comp_num = 1;
	 read_domain[tag] = ind;
	 tag++;
	}
break;
case 60:
#line 625 "TRANSL/wn.yac"
	{
	 tabt[ntr].guard = NULL;
	 prd_h = prd_t = NULL;
	}
break;
case 61:
#line 630 "TRANSL/wn.yac"
	{
	 gen(TYPEEND,"");

	 tabt[ntr].guard = prd_h;

#ifdef ESYMBOLIC
	tabt[ntr].trans_type=ASYM_T;
#endif
	}
break;
case 63:
#line 642 "TRANSL/wn.yac"
	{
         tabt[ntr].reset = TRUE;
        }
break;
case 65:
#line 648 "TRANSL/wn.yac"
	{
         tabt[ntr].reset = TRUE;
        }
break;
case 67:
#line 655 "TRANSL/wn.yac"
	{
#ifdef COLOURED
	 fprintf(stdout,"Dynamic subclass definition is skipped \n");
         exit(1);
#endif
#ifdef SYMBOLIC
	 parsing_flag = DYNAMIC_SUBCLASS;
#endif
	}
break;
case 68:
#line 665 "TRANSL/wn.yac"
	{
#ifdef COLOURED
	 fprintf(stdout,"Dynamic subclass definition is skipped \n");
         exit(1);
#endif
#ifdef SYMBOLIC
	 strcpy(class_read,str_in);
#endif
	}
break;
case 69:
#line 675 "TRANSL/wn.yac"
	{
#ifdef COLOURED
	 fprintf(stdout,"Dynamic subclass definition is skipped \n");
         exit(1);
#endif
#ifdef SYMBOLIC
	 for(i=0,stop=FALSE;!stop && i<ncl;i++)
	  if((ind=already_exist(class_read,i,STAT))!=0)
	   stop=TRUE;
	 if(!stop)
	  {/* Bufferizzare */
	   mpt=(struct MARKBUF *)emalloc(sizeof(struct MARKBUF));
	   mpt->card=card_val;
	   strcpy(mpt->name,bufname);
	   strcpy(mpt->sbc,class_read);
	   mpt->next=mbuf;
	   mbuf=mpt;
	  }/* Bufferizzare */
	 else
	  {/* Inserimento */
	   if(!already_exist(bufname,i-1,ind-1))
	    {
	     dpt=(Dyn_p)emalloc(sizeof(struct DYNSC));
	     dpt->next=tabc[i-1].sbclist[ind-1].dynlist;
	     dpt->card=card_val;
	     dpt->name=(char  *)ecalloc(strlen(bufname)+1,sizeof(char));
	     strcpy(dpt->name,bufname);
	     tabc[i-1].sbclist[ind-1].dynlist=dpt;
	    }
	   else
	    out_error(ERROR_DYNAMIC_REDECLARATION,0,0,0,0,bufname,NULL);
	  }/* Inserimento */
#endif
	}
break;
case 72:
#line 714 "TRANSL/wn.yac"
	{
	 if(count!=tabp[pl_ind].comp_num-1)
	  out_error(ERROR_LESSER_MARKING_COMPONENTS,pl_ind,0,0,0,NULL,NULL);
	 do
	  {
	   optimized_set_token_marking(cart_place_ptr,coef_val*sign,pl_ind,NULL,TOTAL);
	  }
	 while(optimized_nextvec(cart_place_ptr,tabp[pl_ind].comp_num,base));
	 sign=1;
	}
break;
case 73:
#line 725 "TRANSL/wn.yac"
	{
	 if(count!=tabp[pl_ind].comp_num-1)
	  out_error(ERROR_LESSER_MARKING_COMPONENTS,pl_ind,0,0,0,NULL,NULL);
	 do
	  {
	   optimized_set_token_marking(cart_place_ptr,coef_val*sign,pl_ind,NULL,TOTAL);
	  }
	 while(optimized_nextvec(cart_place_ptr,tabp[pl_ind].comp_num,base));
	 sign=1;
	}
break;
case 74:
#line 737 "TRANSL/wn.yac"
	{
	 if(count==tabp[pl_ind].comp_num-1)
	   out_error(ERROR_GREATER_MARKING_COMPONENTS,pl_ind,0,0,0,NULL,NULL);
	 count++;
	}
break;
case 76:
#line 744 "TRANSL/wn.yac"
	{
	 count=0;
	}
break;
case 78:
#line 750 "TRANSL/wn.yac"
	{
	 cl=tabp[pl_ind].dominio[count];
	 objid = get_obj_id(str_in,cl);
	 if(objid == UNKNOWN)
	  {/* Errore */
	   out_error(ERROR_UNKNOWN_ELEMENT_IN_MARKING,pl_ind,0,cl,0,str_in,NULL);
	  }/* Errore */
	 cart_place_ptr->up[count] = cart_place_ptr->low[count] = base[count] = objid;
        }
break;
case 79:
#line 760 "TRANSL/wn.yac"
	{
	 cl = tabp[pl_ind].dominio[count];
	 cart_place_ptr->low[count]=base[count]=0;
	 cart_place_ptr->up[count]=fill_with_elements(count,cl);
	}
break;
case 80:
#line 766 "TRANSL/wn.yac"
	{
	 cl = tabp[pl_ind].dominio[count];
	 if(str_val <1 || str_val >tabc[cl].sbc_num)
	  {/* Errore */
	   out_error(ERROR_WRONG_STATIC_INDEX_IN_MARKING,pl_ind,0,cl,0,NULL,NULL);
	  }/* Errore */
	 str_val--;
	 cart_place_ptr->low[count] = base[count] = GET_STATIC_OFFSET(cl,str_val);
	 cart_place_ptr->up[count] = set_number_of_elements(count,cl,str_val);
	}
break;
case 81:
#line 777 "TRANSL/wn.yac"
	{
	 cl = tabp[pl_ind].dominio[count];
	 if((sbc_ind=already_exist(str_in,cl,STAT))==0)
	  {/* Errore */
	   out_error(ERROR_WRONG_STATIC_NAME_IN_MARKING,pl_ind,0,cl,0,str_in,NULL);
	  }/* Errore */
	 sbc_ind--;
	 cart_place_ptr->low[count] = base[count] = GET_STATIC_OFFSET(cl,sbc_ind);
	 cart_place_ptr->up[count] = set_number_of_elements(count,cl,sbc_ind);
	}
break;
case 82:
#line 789 "TRANSL/wn.yac"
	{
	 for(i=0,tag=1;i<tabp[pl_ind].comp_num;i++)
	  {
	   cl = tabp[pl_ind].dominio[i];
	   cart_place_ptr->low[i] = base[i] = 0;
	   cart_place_ptr->up[i] = fill_with_elements(i,cl);
           for(j=0;j<=cart_place_ptr->up[i];j++)
#ifdef SYMBOLIC
#ifdef SIMULATION
            if(IS_UNORDERED(cl))
	     cart_place_ptr->mark[i][j] =  get_dynamic_from_total(cl,j);
	    else
	     cart_place_ptr->mark[i][j] =  j;
#endif
#ifdef REACHABILITY
            if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl)==1))
	     cart_place_ptr->mark[i][j] =  get_dynamic_from_total(cl,j);
	    else
	     cart_place_ptr->mark[i][j] =  j;
#endif
#endif
#ifdef COLOURED
	    cart_place_ptr->mark[i][j] =  j;
#endif
	  }
	 do
          {
	  set_token_marking(cart_place_ptr,coef_val*sign,pl_ind,NULL,TOTAL,UNKNOWN);
          }
	 while(nextvec(cart_place_ptr,tabp[pl_ind].comp_num));
	 sign=1;
	}
break;
case 84:
#line 824 "TRANSL/wn.yac"
	{
	 if(IS_NEUTRAL(pl_ind))
	  out_error(ERROR_NEUTRAL_PLACE_AND_FUNCTION,pl_ind,ntr,0,0,NULL,NULL);
	 ptr=(Coeff_p)emalloc(sizeof(struct ENN_COEFF));
	 ptr->enn_coef=coef_val;
	 ptr->guard=NULL;
	 ptr->next=NULL;
	 ptr->coef=(Func_p)ecalloc(tabp[pl_ind].comp_num,sizeof(struct COEFF));
	 for(i=0;i<tabp[pl_ind].comp_num;i++)
	  {
	   ptr->coef[i].xsucc_coef=(int *)ecalloc(3,sizeof(int));
	   cl=tabp[pl_ind].dominio[i];
#ifndef ESYMBOLIC 
	   ptr->coef[i].sbc_coef=(int *)ecalloc(tabc[cl].sbc_num,sizeof(int));
#else 
  	   ptr->coef[i].sbc_coef=(int *)ecalloc( get_max_cardinality(),sizeof(int));
#endif
	   for(sbc_ind=0;sbc_ind<tabc[cl].sbc_num;sbc_ind++)
	    ptr->coef[i].sbc_coef[sbc_ind]=1;
	   ptr->coef[i].xsucc_coef[0]=0;
	   ptr->coef[i].xsucc_coef[1]=0;
	   ptr->coef[i].xsucc_coef[2]=0;
	  }
         fun_ptr=ptr;
	}
break;
case 85:
#line 851 "TRANSL/wn.yac"
	{
	 if(IS_NEUTRAL(pl_ind))
	  out_error(ERROR_NEUTRAL_PLACE_AND_FUNCTION,pl_ind,ntr,0,0,NULL,NULL);
	 ptr=(Coeff_p)emalloc(sizeof(struct ENN_COEFF));
	 ptr->enn_coef=coef_val * enn_sign;
	 enn_sign=1;
	 ptr->coef=(Func_p)ecalloc(tabp[pl_ind].comp_num ,sizeof(struct COEFF));
	 for(ind=0;ind<tabp[pl_ind].comp_num;ind++)
	  {
	   ptr->coef[ind].xsucc_coef=(int *)ecalloc(3*MAX_COL_RIP,sizeof(int));
#ifndef ESYMBOLIC
	   ptr->coef[ind].sbc_coef=(int *)ecalloc(tabc[tabp[pl_ind].dominio[ind]].sbc_num,sizeof(int));
#else
	  ptr->coef[ind].sbc_coef=(int *)ecalloc( get_max_cardinality(),sizeof(int));
#endif
	  }
	 ptr->next=fun_ptr;/* Settare fun_ptr a NULL prima di parse */
	 fun_ptr=ptr;
	 ptr->guard = NULL;
	}
break;
case 86:
#line 872 "TRANSL/wn.yac"
	{
	 if(count!=tabp[pl_ind].comp_num-1)
	  out_error(ERROR_LESSER_FUNCTION_COMPONENTS,pl_ind,ntr,0,0,NULL,NULL);
	}
break;
case 87:
#line 877 "TRANSL/wn.yac"
	{
	 enn_sign=sign;
	 sign=1;
         pcode_h = pcode_t = NULL;
	}
break;
case 88:
#line 883 "TRANSL/wn.yac"
	{
	 if(IS_NEUTRAL(pl_ind))
	  out_error(ERROR_NEUTRAL_PLACE_AND_FUNCTION,pl_ind,ntr,0,0,NULL,NULL);
	 ptr=(Coeff_p)emalloc(sizeof(struct ENN_COEFF));
	 ptr->enn_coef=coef_val * enn_sign;
	 enn_sign=1;
	 ptr->coef=(Func_p)ecalloc(tabp[pl_ind].comp_num ,sizeof(struct COEFF));
	 for(ind=0;ind<tabp[pl_ind].comp_num;ind++)
	  {
	   ptr->coef[ind].xsucc_coef=(int *)ecalloc(3*MAX_COL_RIP,sizeof(int));
#ifndef ESYMBOLIC 
	/*   ptr->coef[ind].sbc_coef=(int *)ecalloc(tabc[cl].sbc_num,sizeof(int));*/
	   ptr->coef[ind].sbc_coef=(int *)ecalloc(tabc[tabp[pl_ind].dominio[ind]].sbc_num,sizeof(int));
#else 
  	   ptr->coef[ind].sbc_coef=(int *)ecalloc( get_max_cardinality(),sizeof(int));
#endif	 
          
	  }
	 ptr->next=fun_ptr;
	 fun_ptr=ptr;
	 ptr->guard = NULL;
	}
break;
case 89:
#line 906 "TRANSL/wn.yac"
	{
	 if(count!=tabp[pl_ind].comp_num-1)
	  out_error(ERROR_LESSER_FUNCTION_COMPONENTS,pl_ind,ntr,0,0,NULL,NULL);
	}
break;
case 90:
#line 912 "TRANSL/wn.yac"
	{
	 ptr->guard = NULL;
	 prd_h = prd_t = NULL;
	}
break;
case 91:
#line 917 "TRANSL/wn.yac"
	{
	 gen(TYPEEND,"");
	 ptr->guard = prd_h;

#ifdef ESYMBOLIC
	tabt[ntr].trans_type=ASYM_T;
#endif

	}
break;
case 94:
#line 930 "TRANSL/wn.yac"
	{
	 count=0;
	}
break;
case 96:
#line 935 "TRANSL/wn.yac"
	{
	 if(count==tabp[pl_ind].comp_num-1)
	  out_error(ERROR_GREATER_FUNCTION_COMPONENTS,pl_ind,ntr,0,0,NULL,NULL);
	 count++;
        }
break;
case 102:
#line 951 "TRANSL/wn.yac"
	{
	 cl = tabp[pl_ind].dominio[count];
	 if(tabc[cl].type != ORDERED)
	  out_error(ERROR_ILLEGAL_PREDECESSOR,pl_ind,ntr,cl,0,NULL,NULL);
	 proj_num = get_proj_num(str_in,cl);
	 switch(proj_num)
	  {
	   case ERROR_SHARED_NAME :
		out_error(ERROR_SHARED_NAME,pl_ind,ntr,cl,0,str_in,NULL);
	   case ERROR_AMBIGUITY_IN_ARC :
		out_error(ERROR_AMBIGUITY_IN_ARC,pl_ind,ntr,0,0,NULL,NULL);
	   default :
		ptr->coef[count].xsucc_coef[3*(proj_num-1)+2]+=coef_val* sign;
		sign=1;
		break;
	  }
	}
break;
case 104:
#line 972 "TRANSL/wn.yac"
	{
#ifdef ESYMBOLIC
	tabt[ntr].trans_type=ASYM_T;
#endif
	 cl = tabp[pl_ind].dominio[count];
	 if(str_val<1 || str_val>tabc[cl].sbc_num)
	  out_error(ERROR_WRONG_STATIC_INDEX_IN_FUNCTION,pl_ind,ntr,cl,0,NULL,NULL);
	 if(input_flag && tabc[cl].sbclist[str_val-1].card==1)
	  {/* Trasformazione possibile da sincronizzazione a proiezione */
	   sprintf(sbc_name,"%ds!c%d",tabp[pl_ind].dominio[count],str_val-1);
	   strcpy(str_in,sbc_name);
	   if(!already_transformed(sbc_name,tabp[pl_ind].dominio[count]))
	    {/* Produzione del predicato */
	     if(tabt[ntr].guard == NULL)
	      {/* Creare struttura dati per il predicato */
	       tabt[ntr].guard = NULL;
	       prd_h = prd_t = NULL;
	       gen(TYPED,sbc_name);
	       sprintf(sbc_name,"%d",str_val-1);
	       gen(TYPENUM,sbc_name);
	       gen(TYPEEQ,"");
	       gen(TYPEEND,"");
	       tabt[ntr].guard = prd_h;
	      }/* Creare struttura dati per il predicato */
             else
	      {/* Struttura dati esistente */
	       prd_h = prd_t;
	       prd_t = tabt[ntr].guard;
	       for(;prd_t->next->type !=TYPEEND ;prd_t = prd_t->next);
	       gen(TYPED,sbc_name);
	       sprintf(sbc_name,"%d",str_val-1);
	       gen(TYPENUM,sbc_name);
	       gen(TYPEEQ,"");
	       gen(TYPEAND,"");
	       gen(TYPEEND,"");
	       prd_t->next = prd_h;
	      }/* Struttura dati esistente */
	    }/* Produzione del predicato */
	   proj_num=get_proj_num(str_in,tabp[pl_ind].dominio[count]);
           switch(proj_num)
	    {
	     case ERROR_SHARED_NAME :
		  out_error(ERROR_SHARED_NAME,pl_ind,ntr,cl,0,str_in,NULL);
	     case ERROR_AMBIGUITY_IN_ARC :
		  out_error(ERROR_AMBIGUITY_IN_ARC,pl_ind,ntr,0,0,NULL,NULL);
	     default :
		  ptr->coef[count].xsucc_coef[3*(proj_num-1)]+=coef_val* sign;
		  break;
            } 
	  }/* Trasformazione possibile da sincronizzazione a proiezione */
         else
	 ptr->coef[count].sbc_coef[str_val-1]+=coef_val * sign;
	 sign=1;
	}
break;
case 105:
#line 1027 "TRANSL/wn.yac"
	{
#ifdef ESYMBOLIC
	tabt[ntr].trans_type=ASYM_T;
#endif
	 cl = tabp[pl_ind].dominio[count];
	 if((sbc_ind=already_exist(str_in,cl,STAT))==0)
	  out_error(ERROR_WRONG_STATIC_NAME_IN_FUNCTION,pl_ind,ntr,cl,0,str_in,NULL);
	 if(input_flag && tabc[tabp[pl_ind].dominio[count]].sbclist[sbc_ind-1].card==1)
	  {/* Trasformazione possibile da sincronizzazione a proiezione */
	   sprintf(sbc_name,"%ds!c%d",tabp[pl_ind].dominio[count],sbc_ind-1);
	   strcpy(str_in,sbc_name);
	   if(!already_transformed(sbc_name,tabp[pl_ind].dominio[count]))
	    {/* Produzione del predicato */
	     if(tabt[ntr].guard==NULL)
	      {/* Creare struttura dati per il predicato */
	       tabt[ntr].guard = NULL;
	       prd_h = prd_t = NULL;
	       gen(TYPED,sbc_name);
	       sprintf(sbc_name,"%d",sbc_ind-1);
	       gen(TYPENUM,sbc_name);
	       gen(TYPEEQ,"");
	       gen(TYPEEND,"");
	       tabt[ntr].guard = prd_h;
	      }/* Creare struttura dati per il predicato */
             else
	      {/* Struttura dati esistente */
	       prd_h = prd_t;
	       prd_t = tabt[ntr].guard;
	       for(;prd_t->next->type != TYPEEND ; prd_t = prd_t->next);
	       gen(TYPED,sbc_name);
	       sprintf(sbc_name,"%d",sbc_ind-1);
	       gen(TYPENUM,sbc_name);
	       gen(TYPEEQ,"");
	       gen(TYPEAND,"");
	       gen(TYPEEND,"");
	       prd_t->next = prd_h;
	      }/* Struttura dati esistente */
	    }/* Produzione del predicato */
	   proj_num=get_proj_num(str_in,tabp[pl_ind].dominio[count]);
           switch(proj_num)
	    {
	     case ERROR_SHARED_NAME :
		  out_error(ERROR_SHARED_NAME,pl_ind,ntr,cl,0,str_in,NULL);
	     case ERROR_AMBIGUITY_IN_ARC :
		  out_error(ERROR_AMBIGUITY_IN_ARC,pl_ind,ntr,0,0,NULL,NULL);
	     default :
		  ptr->coef[count].xsucc_coef[3*(proj_num-1)]+=coef_val* sign;
		  break;
            } 
	  }/* Trasformazione possibile da sincronizzazione a proiezione */
         else
	  ptr->coef[count].sbc_coef[sbc_ind-1]+=coef_val * sign;
	 sign=1;
	}
break;
case 106:
#line 1082 "TRANSL/wn.yac"
	{
#ifndef ESYMBOLIC
        for(i=0;i<tabc[tabp[pl_ind].dominio[count]].sbc_num;i++)
	   ptr->coef[count].sbc_coef[i]+=coef_val * sign;
	 sign=1;
#else
	for(i=0;i<get_max_cardinality();i++)
           ptr->coef[count].sbc_coef[i]+=coef_val * sign;
	 sign=1;
#endif

	}
break;
case 107:
#line 1096 "TRANSL/wn.yac"
	{
	 cl = tabp[pl_ind].dominio[count];
	 if(tabc[cl].type != ORDERED)
	  out_error(ERROR_ILLEGAL_SUCCESSOR,pl_ind,ntr,cl,0,NULL,NULL);
	 proj_num=get_proj_num(str_in,tabp[pl_ind].dominio[count]);
	 switch(proj_num)
	  {
	   case ERROR_SHARED_NAME :
		out_error(ERROR_SHARED_NAME,pl_ind,ntr,cl,0,str_in,NULL);
	   case ERROR_AMBIGUITY_IN_ARC :
		out_error(ERROR_AMBIGUITY_IN_ARC,pl_ind,ntr,0,0,NULL,NULL);
	   default :
		ptr->coef[count].xsucc_coef[3*(proj_num-1)+1]+=coef_val* sign;
		sign=1;
		break;
	  }
	}
break;
case 108:
#line 1115 "TRANSL/wn.yac"
	{
	 proj_num=get_proj_num(str_in,tabp[pl_ind].dominio[count]);
         switch(proj_num)
	  {
	   case ERROR_SHARED_NAME :
		out_error(ERROR_SHARED_NAME,pl_ind,ntr,cl,0,str_in,NULL);
	   case ERROR_AMBIGUITY_IN_ARC :
		out_error(ERROR_AMBIGUITY_IN_ARC,pl_ind,ntr,0,0,NULL,NULL);
	   default :
		ptr->coef[count].xsucc_coef[3*(proj_num-1)]+=coef_val* sign;
		sign=1;
		break;
          } 
	}
break;
case 110:
#line 1130 "TRANSL/wn.yac"
	{ coef_val = card_val = 1;}
break;
case 111:
#line 1133 "TRANSL/wn.yac"
	{
         coef_val = card_val = str_val;
#ifdef PIPPO
        }
break;
case 112:
#line 1138 "TRANSL/wn.yac"
	{
         coef_val = card_val = get_marking_parameter_value(str_in);
         if(coef_val == UNKNOWN)
          out_error(ERROR_UNKNOWN_MARKING_PARAMETER,pl_ind,ntr,cl,0,str_in,NULL);
#endif
	}
break;
case 113:
#line 1145 "TRANSL/wn.yac"
	{
         strcpy(class_name,str_in);
        }
break;
case 114:
#line 1149 "TRANSL/wn.yac"
	{
         strcpy(sbc_name,str_in);
        }
break;
case 115:
#line 1153 "TRANSL/wn.yac"
	{
         /* Controllo su esistenza della classe */
	 if((ind=get_index(class_name))==-1)
	  out_error(ERROR_MISSING_CLASS,0,0,0,0,class_name,NULL);
	 else
          {  
           /* Controllo su esistenza sottoclasse */
	   if((sbc_ind=already_exist(sbc_name,ind,STAT))==0)
	    out_error(ERROR_MISSING_STATIC,0,0,0,0,sbc_name,NULL);
	   else 
            coef_val = card_val = tabc[ind].sbclist[sbc_ind-1].card;
          }
        }
break;
case 116:
#line 1167 "TRANSL/wn.yac"
	{
         /* Controllo su esistenza della classe */
         if((ind=get_index(str_in))==-1)
          {
           /* Controllo su esistenza sottoclasse */
           for(i=0,stop=FALSE;!stop && i<ncl;i++)
            if((ind=already_exist(str_in,i,STAT))!=0) stop=TRUE;
	   if(stop==FALSE)
	    out_error(ERROR_MISSING_CLASS,0,0,0,0,str_in,NULL);
	   else 
            coef_val = card_val = tabc[i-1].sbclist[ind-1].card;
           /* Questa cardinalita'e'quella della prima sottoclasse */
           /* trovata con quel nome                               */
          }
         else 
          coef_val = card_val = get_class_card(ind);
        }
break;
case 117:
#line 1188 "TRANSL/wn.yac"
	{
	 gen(TYPEOR,"");
	}
break;
case 119:
#line 1196 "TRANSL/wn.yac"
	{
	 gen(TYPEAND,"");
	}
break;
case 122:
#line 1207 "TRANSL/wn.yac"
	{
	    gen(relfl," ");
	   }
break;
case 123:
#line 1212 "TRANSL/wn.yac"
	{
	 relfl = TYPEEQ;
	}
break;
case 124:
#line 1216 "TRANSL/wn.yac"
	{
	 relfl = TYPENE;
	}
break;
case 125:
#line 1220 "TRANSL/wn.yac"
	{
	 fprintf(stdout,"Predicate operator < is not allowed in SWN specification\n");
         exit(1);
	}
break;
case 126:
#line 1225 "TRANSL/wn.yac"
	{
	 fprintf(stdout,"Predicate operator <= is not allowed in SWN specification\n");
         exit(1);
	}
break;
case 127:
#line 1230 "TRANSL/wn.yac"
	{
	 fprintf(stdout,"Predicate operator > is not allowed in SWN specification\n");
         exit(1);
	}
break;
case 128:
#line 1235 "TRANSL/wn.yac"
	{
	 fprintf(stdout,"Predicate operator >= is not allowed in SWN specification\n");
         exit(1);
	}
break;
case 129:
#line 1241 "TRANSL/wn.yac"
	{
	 sprintf(sbc_name,"%d",atoi(jjtext)-1);
	 gen(TYPENUM,sbc_name);
	}
break;
case 130:
#line 1246 "TRANSL/wn.yac"
	{
	 gen(TYPESTRING,str_in);
	}
break;
case 131:
#line 1253 "TRANSL/wn.yac"
	{
	 gen(TYPED,str_in);
	}
break;
case 132:
#line 1258 "TRANSL/wn.yac"
	{
	 gen(TYPESUCCESSOR,str_in);
	}
break;
case 133:
#line 1263 "TRANSL/wn.yac"
	{
	 gen(TYPEPREDECESSOR,str_in);
	}
break;
case 134:
#line 1269 "TRANSL/wn.yac"
	{
#ifdef SYMBOLIC
	 fprintf(stdout,"SWN predicate definition DISTANCE is not allowed in SWN symbolic solution\n");
         exit(1);
#endif
#ifdef COLOURED
	 gen(TYPEDISTANCE,str_in);
#endif
	}
break;
case 135:
#line 1281 "TRANSL/wn.yac"
	{
#ifdef SYMBOLIC
	 fprintf(stdout,"SWN predicate definition DISTANCE is not allowed in SWN symbolic solution\n");
         exit(1);
#endif
#ifdef COLOURED
	 gen(TYPEDISTANCE,str_in);
#endif
	}
break;
#line 2124 "y.tab.c"
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
