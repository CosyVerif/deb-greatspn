#ifndef YYERRCODE
#define YYERRCODE 256
#endif

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
typedef union { 	
  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
  struct Perf_Index* Pd;
} YYSTYPE;
extern YYSTYPE Indexlval;
