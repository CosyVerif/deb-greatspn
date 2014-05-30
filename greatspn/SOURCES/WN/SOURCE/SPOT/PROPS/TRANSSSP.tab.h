#define IDENT 257
#define ID 258
#define NOT 259
#define EQ 260
#define MAX 261
#define D 262
#define MCOMP 263
#define OR 264
#define AND 265
typedef union { 	

  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
} YYSTYPE;
extern YYSTYPE Translval;
