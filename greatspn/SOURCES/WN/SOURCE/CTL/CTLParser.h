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
typedef union{
double num;
char var[255];
class Term *term;
class Expression *expr;
class Inequality *ineq;
class AtomicProposition *AP;
class CTLFormula *formula;
} YYSTYPE;
extern YYSTYPE mmlval;
