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
extern YYSTYPE yylval;
