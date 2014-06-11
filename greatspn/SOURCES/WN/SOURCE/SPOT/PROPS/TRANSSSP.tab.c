#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
extern int yyparse(void);
#define yyparse Transparse
#define yylex Translex
#define yyerror Transerror
#define yychar Transchar
#define yyval Transval
#define yylval Translval
#define yydebug Transdebug
#define yynerrs Transnerrs
#define yyerrflag Transerrflag
#define yyss Transss
#define yyssp Transssp
#define yyvs Transvs
#define yyvsp Transvsp
#define yylhs Translhs
#define yylen Translen
#define yydefred Transdefred
#define yydgoto Transdgoto
#define yysindex Transsindex
#define yyrindex Transrindex
#define yygindex Transgindex
#define yytable Transtable
#define yycheck Transcheck
#define yyname Transname
#define yyrule Transrule
#define YYPREFIX "Trans"
#line 6 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"

/* .......... Declarations C ........*/
#pragma warning (disable:4786)
#include "../../../INCLUDE/const.h"
#include "../../../INCLUDE/SCONSSPOT.h"
#include "../../../INCLUDE/struct.h"
#include "../../../INCLUDE/SSTRUCTSPOT.h"
#include "../../../INCLUDE/var_ext.h"
#include "../../../INCLUDE/SVAR_EXTSPOT.h"
#include "../../../INCLUDE/macros.h"

/***************** Variables *******************/

static struct Token_Domains TD; 
extern char*   Ptr_Cur;
extern int     Lim_Pos;
int trans;
/**********************************************/

/**************** flex functions ************************/
extern int yylex();
extern FILE *yyin;
void yyerror(char *s){  printf("parsing error: %s\n", s); } 
int Transwrap(){ return (1); }
extern void   flush_buffer();
/*******************************************************/


/************** extern functions needed to compute local partitions *******/

extern void* ecalloc();
extern void* emalloc();
extern int GetIndObj();
extern PART_MAT_P GetMatRepOfTransDom();
extern PART_MAT_P GetMatRepOfPartTransDom();
extern TYPE_P** FindDisjParts2();


/************************************************************************/

int EXISTE_TRANS(char* id){
int i=0;
 
    while (i<ntr){
      if (strcmp(tabt[i].trans_name,id)==0) return i;
       i++;  
     }
    return NOT_PRESENT; 
} 

int EXISTE_FUNC(int t, char* f)
 {
   int i;

   for(i=0; i < tabt[t].comp_num;i++)
     if(strcmp(tabt[t].names[i],f)==0)
       return i;

   return  NOT_PRESENT; 

 }
          
#line 72 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
typedef union { 	

  int j;
  char* s;
  struct CTOKEN * tk;
  struct TREE_NODE * nd;
} YYSTYPE;
#line 108 "TRANSSSP.tab.c"
#define IDENT 257
#define ID 258
#define NOT 259
#define EQ 260
#define MAX 261
#define D 262
#define MCOMP 263
#define OR 264
#define AND 265
#define YYERRCODE 256
short Translhs[] = {                                        -1,
    1,    1,    5,    4,    4,    7,    6,    6,    8,    9,
   10,    0,    0,    3,    3,    3,    2,   11,    2,   12,
    2,   13,    2,
};
short Translen[] = {                                         2,
    1,    2,    0,    4,    1,    0,    4,    1,    4,    0,
    0,    8,    0,    3,    3,    1,    4,    0,    7,    0,
    6,    0,    4,
};
short Transdefred[] = {                                      0,
   10,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,    0,    0,    0,    2,    0,
   20,    0,   15,   14,   11,    0,    0,   18,    0,   17,
    0,    0,   23,    0,    0,    0,   12,    9,    0,    0,
    0,   21,    0,   19,    0,    0,    4,    7,
};
short Transdgoto[] = {                                       2,
   12,    7,    8,   36,   41,   40,   43,   18,    3,   31,
   34,   29,    9,
};
short Transsindex[] = {                                   -254,
    0,    0,  -78, -256, -252,  -26, -255,  -77, -247, -243,
    0, -123, -240, -256, -256,  -40,  -20, -252,    0,  -19,
    0,  -18,    0,    0,    0, -236, -247,    0, -234,    0,
 -254,  -16,    0, -232,    0,  -98,    0,    0,    0,  -13,
  -15,    0,  -14,    0, -234, -232,    0,    0,
};
short Transrindex[] = {                                     31,
    0,    0,    0, -230,    0,    0,  -77,    0,    0,    0,
    0,    0,    0, -230, -230,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,    0,    0,  -43,    0,    0,    0,  -38,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
short Transgindex[] = {                                      2,
   16,    0,   -3,  -10,    0,   -9,    0,    9,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 140
short Transtable[] = {                                      21,
    3,    5,    8,    1,    6,    6,   10,   11,   14,   15,
   23,   24,    4,   13,   17,   16,   19,   22,   25,   26,
   28,   32,   30,   35,   38,   39,   42,   44,   45,   46,
   13,   22,   37,   27,   47,   33,   48,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   20,
};
short Transcheck[] = {                                     123,
   44,  258,   41,  258,  261,   44,  259,  260,  264,  265,
   14,   15,   91,   40,  262,   93,  260,  258,   59,   40,
   40,  258,   41,  258,   41,  258,  125,   41,   44,   44,
    0,  262,   31,   18,   45,   27,   46,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 265
#if YYDEBUG
char *Transname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"IDENT","ID","NOT","EQ","MAX","D","MCOMP","OR","AND",
};
char *Transrule[] = {
"$accept : FORMULES",
"OP : EQ",
"OP : NOT EQ",
"$$1 :",
"VARS : ID $$1 ',' VARS",
"VARS : ID",
"$$2 :",
"COMP : ID $$2 ',' COMP",
"COMP : ID",
"STATIC : D '(' ID ')'",
"$$3 :",
"$$4 :",
"FORMULES : ID $$3 '[' ATOMIC ']' ';' $$4 FORMULES",
"FORMULES :",
"ATOMIC : EXPR AND ATOMIC",
"ATOMIC : EXPR OR ATOMIC",
"ATOMIC : EXPR",
"EXPR : MAX '(' ID ')'",
"$$5 :",
"EXPR : ID OP MCOMP '(' $$5 COMP ')'",
"$$6 :",
"EXPR : ID OP '{' $$6 VARS '}'",
"$$7 :",
"EXPR : $$7 STATIC OP STATIC",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 372 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
  
int guard_parser(FILE* f){

 char c; 
 int i=0; 
 char* ptr; 
 ptr=Ptr_Cur=(char*)malloc(STR_SIZE*sizeof(char));
     
 while((c=fgetc(f))!=EOF)  
   {
     Ptr_Cur[i]=c; 
     i++;
   }
 
   Ptr_Cur[i]='\0';
   Lim_Pos=(int)Ptr_Cur+strlen(Ptr_Cur);   

   
   i=yyparse();
   free(ptr);
  

  return i;
}















#line 296 "TRANSSSP.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

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
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
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
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
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
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 101 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{yyval.j=EQOP;}
break;
case 2:
#line 101 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{yyval.j=NEQOP;}
break;
case 3:
#line 103 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
                       int Cl;
                       int v=GetIndObj(yyvsp[0].s,MTCL,&Cl);
                       if(v==UNKNOWN) {
			 printf("\n The object :%s is not a valid color of the WN to be verfied \n",yyvsp[0].s);
                         return(1);
                       }
                       TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
                       TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
		       TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ;
                       free(yyvsp[0].s);
                      }
break;
case 5:
#line 116 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
			int Cl;
			int v=GetIndObj(yyvsp[0].s,MTCL,&Cl);
			if(v==UNKNOWN) {
			  printf("\n The object :%s is not a valid color of WN to be verfied \n",yyvsp[0].s); 
			  return(1);
			}
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=v ; TD.Domain[TD.NbCl]=Cl; TD.NbCl++ ; 
			                 
			free(yyvsp[0].s);
			
                     }
break;
case 6:
#line 133 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
		         int pos;
			 if((pos=EXISTE_FUNC(trans, yyvsp[0].s))==NOT_PRESENT )
			   {
			     printf("\n Transition '%d' has no function named %s \n",trans,yyvsp[0].s);
			     return(1);					  
			   }

			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=pos+1 ; TD.NbCl++ ;
			
                        }
break;
case 8:
#line 146 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
			 int pos;
			 if((pos=EXISTE_FUNC(trans, yyvsp[0].s))==NOT_PRESENT )
			   {
			     printf("\n Transition '%d' has no function named %s \n",trans,yyvsp[0].s);
			     return(1);					  
			   }
	             
			TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
			TD.Token[TD.NbCl]=pos+1 ; TD.NbCl++ ;
			
		   }
break;
case 9:
#line 161 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
                                 int pos;
				 if((pos=EXISTE_FUNC(trans, yyvsp[-1].s))==NOT_PRESENT )
				   {
				     printf("\n Transition '%d' has nov function named %s \n",trans,yyvsp[-1].s);
				     return(1);					  
				   }
				 else
				   {
			   
				     TD.Token=realloc(TD.Token,(TD.NbCl+1)*sizeof(int));
				     TD.Domain=realloc(TD.Domain,(TD.NbCl+1)*sizeof(int));
				     TD.Token[TD.NbCl]=pos+1 ;  TD.Domain[TD.NbCl]= tabt[trans].dominio[pos] ;
				     TD.NbCl++ ;
	                 	   }
                               }
break;
case 10:
#line 180 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{ 
                         if( (trans=EXISTE_TRANS(yyvsp[0].s))==NOT_PRESENT ) 
                           {  
			     printf("\n Transition  '%s' does'nt exist \n",yyvsp[0].s);
			     return(1);			     
			   }
			 free(yyvsp[0].s);
                     }
break;
case 11:
#line 189 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
                      tabt[trans].dyn_guard=yyvsp[-2].nd;
		    }
break;
case 14:
#line 195 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
		      yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
		      yyval.nd->op=ANDOP;
		      yyval.nd->type=NOTYPE;
		      yyval.nd->FONCT=NULL;
		      yyval.nd->filsg=yyvsp[-2].nd;
		      yyval.nd->filsd=yyvsp[0].nd;
		      
		      if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL )
			{ yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
		      else
			if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL)
			  { yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
			else 
			  if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL)
			     { yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM; }
			  else 
			    {
                               
			      PART_MAT_P var,Part=calloc(2,sizeof(PART_MAT));
                               				
			      Part[0].PART_MAT= yyvsp[-2].nd->PART_MAT;
			      Part[0].NbElPM= yyvsp[-2].nd->NbElPM ;  
			      Part[1].PART_MAT= yyvsp[0].nd->PART_MAT;
			      Part[1].NbElPM= yyvsp[0].nd->NbElPM ; 
			      var=FindDisjParts3(Part ,2);  
			      yyval.nd->PART_MAT=var->PART_MAT;
			      yyval.nd->NbElPM=var->NbElPM;
			    
                              /*free(var);*/
			      free(Part);
			      FreePartMAt(yyvsp[-2].nd->PART_MAT, yyvsp[-2].nd->NbElPM);
			      FreePartMAt(yyvsp[0].nd->PART_MAT, yyvsp[0].nd->NbElPM); 
			    }
                    }
break;
case 15:
#line 231 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
		       yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
		       yyval.nd->op=OROP;
		       yyval.nd->type=NOTYPE;
		       yyval.nd->FONCT=NULL;
		       yyval.nd->filsg=yyvsp[-2].nd;
		       yyval.nd->filsd=yyvsp[0].nd;
		       
		       if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT==NULL ) { yyval.nd->PART_MAT=NULL; yyval.nd->NbElPM=NULL;}
		       else
			 if(yyvsp[-2].nd->PART_MAT==NULL && yyvsp[0].nd->PART_MAT!=NULL)
			   { yyval.nd->PART_MAT=yyvsp[0].nd->PART_MAT; yyval.nd->NbElPM=yyvsp[0].nd->NbElPM; }
			 else 
			   if(yyvsp[-2].nd->PART_MAT!=NULL && yyvsp[0].nd->PART_MAT==NULL)
			     { yyval.nd->PART_MAT=yyvsp[-2].nd->PART_MAT;yyval.nd->NbElPM=yyvsp[-2].nd->NbElPM;}
			   else 
			     { 
			       PART_MAT_P var,Part=calloc(2,sizeof(PART_MAT));
                               				
			       Part[0].PART_MAT= yyvsp[-2].nd->PART_MAT;
			       Part[0].NbElPM= yyvsp[-2].nd->NbElPM ;  
			       Part[1].PART_MAT= yyvsp[0].nd->PART_MAT;
			       Part[1].NbElPM= yyvsp[0].nd->NbElPM ; 
			       var=FindDisjParts3(Part ,2);  
			       yyval.nd->PART_MAT=var->PART_MAT;
			       yyval.nd->NbElPM=var->NbElPM;
			       /* free(var);*/
			       FreePartMAt(yyvsp[-2].nd->PART_MAT, yyvsp[-2].nd->NbElPM);
			       FreePartMAt(yyvsp[0].nd->PART_MAT, yyvsp[0].nd->NbElPM); 
			     }
		       
		     }
break;
case 16:
#line 262 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{yyval.nd=yyvsp[0].nd; }
break;
case 17:
#line 265 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
		       
		       int pos;
		       if((pos=EXISTE_FUNC(trans, yyvsp[-1].s))==NOT_PRESENT )
			 {
			   printf("\n Transition '%d' has no function named %s \n",trans,yyvsp[-1].s);
			   return(1);					  
			 }
		       else
			 { 
			   yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			   yyval.nd->op=pos+1;
			   yyval.nd->type=MAXIMUM ;
			   yyval.nd->FONCT=NULL;
			   PART_MAT_P pm=GetMatRepOfPartTransDom(MTCL,tabt[trans].dominio[pos]); 
			   yyval.nd->PART_MAT=pm->PART_MAT;
			   yyval.nd->NbElPM=pm->NbElPM;
			   yyval.nd->filsg=yyval.nd->filsd=NULL;
			   free(pm);
			   free(yyvsp[-1].s);
			 }
                     }
break;
case 18:
#line 288 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 19:
#line 289 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
			  int pos;
			  if((pos=EXISTE_FUNC(trans, yyvsp[-6].s))==NOT_PRESENT )
			    {
			      printf("\n Transition '%d' has no function named %s \n",trans,yyvsp[-6].s);
			      return(1);					  
			    }
			  free(yyvsp[-6].s);
			  int i,cl =tabt[trans].dominio[pos];
			  for(i=0;i<TD.NbCl;i++)
                            if(tabt[trans].dominio[TD.Token[i]-1]!=cl) 
			      {
				printf("\n incompatible color domain in guard function of transition '%d' \n",trans);
				return(1);
			      }
			  
			  yyval.nd= (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			    yyval.nd->op=yyvsp[-5].j;
			    yyval.nd->type=MAX_COMP ;
			    yyval.nd->FONCT=NULL;
			    PART_MAT_P pm=GetMatRepOfPartTransDom(MTCL,tabt[trans].dominio[pos]); 
			    yyval.nd->PART_MAT=pm->PART_MAT;
			    yyval.nd->NbElPM=pm->NbElPM;
			    yyval.nd->filsg=yyval.nd->filsd=NULL;
                            yyval.nd->FONCT=(CToken_p)emalloc(sizeof(CToken));
                            yyval.nd->FONCT->mult=pos+1;
			   (yyval.nd->FONCT->tok_dom).Token=TD.Token;     
			   (yyval.nd->FONCT->tok_dom).Domain=NULL;
			   (yyval.nd->FONCT->tok_dom).NbCl=TD.NbCl;
			    yyval.nd->FONCT->next=NULL;
			    free(pm);
			    
                        }
break;
case 20:
#line 323 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{  TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 21:
#line 324 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
			int pos;
			if((pos=EXISTE_FUNC(trans, yyvsp[-5].s))==NOT_PRESENT )
			  {
			    printf("\n Transition '%d' has no function named %s \n",trans,yyvsp[-5].s);
			    return(1);					  
			  }
                        else
  		   	   { 
			    yyval.nd = (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			    yyval.nd->op=yyvsp[-4].j;
			    yyval.nd->type=INCLUDED ;
			    yyval.nd->FONCT=(CToken_p)emalloc(sizeof(CToken));
			     yyval.nd->FONCT->mult=pos+1;
                            (yyval.nd->FONCT->tok_dom).Token=TD.Token;     
			    (yyval.nd->FONCT->tok_dom).Domain=TD.Domain;
			    (yyval.nd->FONCT->tok_dom).NbCl=TD.NbCl;
			    PART_MAT_P pm=GetMatRepOfTransDom(MTCL,TD); 
			    yyval.nd->PART_MAT=pm->PART_MAT;
			    yyval.nd->NbElPM=pm->NbElPM;
			    yyval.nd->filsg=yyval.nd->filsd=NULL;
			    free(pm);
			    free(yyvsp[-5].s);
			   }
                       
                      }
break;
case 22:
#line 352 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{TD.NbCl=0;TD.Token=NULL;TD.Domain=NULL;}
break;
case 23:
#line 354 "/data/baarir/Opt_Ver/greatspn/SOURCES/WN/SOURCE/SPOT/PROPS/TRANSSSP.y"
{
		         yyval.nd = (struct TREE_NODE*)emalloc(sizeof(struct TREE_NODE));
			 yyval.nd->op=yyvsp[-1].j;
			 yyval.nd->type=DF;
			 yyval.nd->PART_MAT=NULL;
			 yyval.nd->NbElPM=NULL;
			 yyval.nd->FONCT=(CToken_p)emalloc(sizeof(CToken));
			 yyval.nd->filsg= yyval.nd->filsd=NULL;
			 yyval.nd->FONCT->mult=0;
			 (yyval.nd->FONCT->tok_dom).Token=TD.Token;     
			 (yyval.nd->FONCT->tok_dom).Domain=TD.Domain;
			 (yyval.nd->FONCT->tok_dom).NbCl=TD.NbCl;
			 yyval.nd->FONCT->next=NULL;
		        }
break;
#line 739 "TRANSSSP.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
