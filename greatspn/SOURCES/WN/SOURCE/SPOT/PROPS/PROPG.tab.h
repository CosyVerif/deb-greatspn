#ifndef YYERRCODE
#define YYERRCODE 256
#endif

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
typedef union { 	

  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
} YYSTYPE;
extern YYSTYPE Proplval;
