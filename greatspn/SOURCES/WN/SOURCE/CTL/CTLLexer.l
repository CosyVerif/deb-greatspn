%{

#include "CTLParser.h"

int yyFlexLexer::yywrap(void){
	return 1;
}
%} 
%%
"//".*     		/* ignore comment */;
[ \t]+                  /* ignore whitespace */;
<<EOF>>	{return -1;}
"en"	{return ENABLED;}
"deadlock"	{return DEADLOCK;}
"ndeadlock"	{return NDEADLOCK;}
"true"	{return TRUEv;}
"false"	{return FALSEv;}
"or"	{return OR;}
"and"	{return AND;}
"not"   {return NOT;}
"->"	{return IMPL;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return TIMES;}
"/"	{return DIV;}
"<"	{return MINOR;}
">"	{return MAJOR;}
"<="	{return MINOREQ;}
">="	{return MAJOREQ;}
"="	{return EQ;}
"!="	{return NEQ;}
"("	{return LPARENT;}
")"	{return RPARENT;}
"["	{return LQPARENT;}
"]"	{return RQPARENT;}
"A"	{return A;}
"E"	{return E;}
"X"	{return X;}
"G"	{return G;}
"F"	{return F;}
"U"	{return U;}
[0-9]+("."[0-9]*)?      {mmlval.num= atof(yytext); return NUMBER;}
[A-Za-z_][A-Za-z0-9_]*	{strcpy(mmlval.var,yytext); return VAR;}
%%
