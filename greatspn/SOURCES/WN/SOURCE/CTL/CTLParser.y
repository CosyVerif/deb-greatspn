%{
//#include "../../INCLUDE/var_ext.h"
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>
#include <fstream>
#include "CTLLexer.h"
#include "CTL.h"
#include "../SHARED/medd.h"
#define PERFORMANCECTL 1
using namespace std;
CTLMDD *ctl = CTLMDD::getInstance();
CTLFormula *ris = NULL;
dddRS::RSRG *rsrg;
istringstream *buffer;
FlexLexer* lexer;
clock_t startMDD, endMDD, endMDD2; // tempi di clock quando inizia la generazione dell'MDD della formula, quando finisce e dopo aver controllato la presenza dello stato iniziale nella formula


void yyerror(const char *str)
{
  cout<<"Errore in parsificazione: "<<str<<endl;
}
 
int yywrap()
{
	return 0; //con 1 cicla all'infinito
} 
int yylex(void){
	int i = lexer->yylex(); 
	return i;
}
extern int yyparse(void);
extern void getPreTR(const int tID, int *preset);
extern void getInhTR(const int tID, int *set);
extern int output_flag;
extern int Max_Token_Bound;


%}
%union{
double num;
char var[255];
class Term *term;
class Expression *expr;
class Inequality *ineq;
class AtomicProposition *AP;
class CTLFormula *formula;
}
%token <num> NUMBER
%token <var> VAR
%token PLUS MINUS TIMES DIV MINOR MAJOR MINOREQ MAJOREQ EQ NEQ OR AND NOT LPARENT RPARENT TRUEv FALSEv LQPARENT RQPARENT DEADLOCK NDEADLOCK ENABLED
%right E A G X F U ENABLED
%right IMPL
%right OR
%right AND
%right NOT
%left EQ MINOR MAJOR MINOREQ MAJOREQ NEQ
%left PLUS MINUS
%left TIMES DIV
%type <expr> expression
%type <term> term
%type <num> number_expr
%type <AP> atomicProposition
%type <ineq> inequality
%type <AP> boolvalue
%type <formula> CTLformula
%start inizio
%% 
inizio:
CTLformula 	{ris = $1;}
;

CTLformula:
atomicProposition		{$$=$1;}
| LPARENT CTLformula RPARENT 	{$$=$2;}
| CTLformula AND CTLformula	{ComplexBoolFormula *ce = new ComplexBoolFormula($1,$3, (ComplexBoolFormula::op_type)1);$$ = ce;}
| CTLformula OR CTLformula	{ComplexBoolFormula *ce = new ComplexBoolFormula($1,$3, (ComplexBoolFormula::op_type)2);$$ = ce;}
| NOT CTLformula		{ComplexBoolFormula *ce = new ComplexBoolFormula($2);$$ = ce;}
| CTLformula IMPL CTLformula	{ // (not CTLformula1) or CTLformula
				  ComplexBoolFormula *nf1 = new ComplexBoolFormula($1); // (not CTLformula1)
				  ComplexBoolFormula *ce = new ComplexBoolFormula(nf1,$3, (ComplexBoolFormula::op_type)2);
				  $$ = ce;
				}
| E X CTLformula		{CTLOperation *ce = new CTLOperation($3, (CTLOperation::op_type) 0/*CTLOperation::EX*/);$$ = ce;}
| E G CTLformula		{CTLOperation *ce = new CTLOperation($3, (CTLOperation::op_type) 2/*CTLOperation::EG*/);$$ = ce;}
| E LQPARENT CTLformula U CTLformula RQPARENT	{CTLOperation *ce = new CTLOperation($3, $5);$$ = ce;}
| A X CTLformula		{	// not EX not CTLFormula 
					ComplexBoolFormula *cbf = new ComplexBoolFormula($3); //not CTLFormula
					CTLOperation *co = new CTLOperation(cbf, (CTLOperation::op_type) 0/*CTLOperation::EX*/); // EX not CTLFormula
					ComplexBoolFormula *ce = new ComplexBoolFormula(co); //not EX not CTLFormula
					$$ = ce;
				}

| A F CTLformula		{	// not EG not CTLFormula 
					ComplexBoolFormula *cbf = new ComplexBoolFormula($3); //not CTLFormula
					CTLOperation *co = new CTLOperation(cbf, (CTLOperation::op_type) 2/*CTLOperation::EG*/); // EG not CTLFormula
					ComplexBoolFormula *ce = new ComplexBoolFormula(co); //not EG not CTLFormula
					$$ = ce;
				}

| E F CTLformula		{	// E true U CTLFormula 
					//
					//BoolValue *bv = new BoolValue(true); //true
					//CTLOperation *ce = new CTLOperation(bv, $3); // E true U CTLFormula
					CTLOperation *co = new CTLOperation($3, (CTLOperation::op_type) 3/*CTLOperation::EF*/); 					$$ = co;
				}
| A G CTLformula		{	//not (E true U not CTLFormula )
					//BoolValue *bv = new BoolValue(true); //true
					ComplexBoolFormula *cbf = new ComplexBoolFormula($3); //not CTLFormula
					//CTLOperation *eu = new CTLOperation(bv, cbf); // E true U not CTLFormula
					//ComplexBoolFormula *ce = new ComplexBoolFormula(eu); //not E true U not CTLFormula
					//not EF not CTLFormula
					CTLOperation *co = new CTLOperation(cbf, (CTLOperation::op_type) 3/*CTLOperation::EF*/);
					ComplexBoolFormula *ce = new ComplexBoolFormula(co);
					$$ = ce;
				}
| A LQPARENT CTLformula U CTLformula RQPARENT {	//not (E not CTLFormula2 U (not CTLFormula1 and not CTLFormula2) ) and not EG not CTLFormula2
					ComplexBoolFormula *f1 = new ComplexBoolFormula($3); //not CTLFormula1
					ComplexBoolFormula *f2 = new ComplexBoolFormula($5); //not CTLFormula2
					ComplexBoolFormula *f1f2 = new ComplexBoolFormula(f1,f2, (ComplexBoolFormula::op_type)1/*and*/); //(not CTLFormula1 and not CTLFormula2)
					CTLOperation *eu = new CTLOperation(f2, f1f2); //E not CTLFormula2 U (not CTLFormula1 and not CTLFormula2) 
					ComplexBoolFormula *neu = new ComplexBoolFormula(eu); //not (E not CTLFormula2 U (not CTLFormula1 and not CTLFormula2) )
					CTLOperation *eg = new CTLOperation(f2, (CTLOperation::op_type) 2/*CTLOperation::EG*/); // EG not CTLFormula2
					ComplexBoolFormula *neg = new ComplexBoolFormula(eg); //not EG not CTLFormula2
					ComplexBoolFormula *ce = new ComplexBoolFormula(neu,neg, (ComplexBoolFormula::op_type)1/*and*/); //total
					$$ = ce;
				}
|ENABLED LPARENT VAR RPARENT	{std::string v($3); $$=enableTR(v);}
;

atomicProposition:
inequality 					{$$ = $1;}
|boolvalue					{$$ = $1;}
|NDEADLOCK					{$$ = new Deadlock(false);}
|DEADLOCK					{$$ = new Deadlock(true);}
;

boolvalue:
TRUEv 		{BoolValue *be = new BoolValue(true); $$ = be;}
|FALSEv 	{BoolValue *be = new BoolValue(false); $$ = be;}
;
inequality:
expression MINOR number_expr	{ Expression *ex = $1;
				Inequality *in = new Inequality((Inequality::op_type)0,ex,$3);
				$$=in;
				}
| expression MINOREQ number_expr{Expression *ex = $1;
				Inequality *in = new Inequality((Inequality::op_type)2,ex,$3);
				$$=in;
				}
| expression MAJOR number_expr	{Expression *ex = $1;
				Inequality *in = new Inequality((Inequality::op_type)1,ex,$3);
				$$=in;
				}
| expression MAJOREQ number_expr{Expression *ex = $1;
				Inequality *in = new Inequality((Inequality::op_type)3,ex,$3);
				$$=in;
				}
| expression EQ number_expr	{Expression *ex = $1;
				Inequality *in = new Inequality((Inequality::op_type)4,ex,$3);
				$$=in;

				}
| expression NEQ number_expr	{Expression *ex = $1;
				Inequality *in = new Inequality((Inequality::op_type)5,ex,$3);
				$$=in;
				}
;

expression:
LPARENT expression RPARENT	{$$ = $2;}
| LPARENT number_expr RPARENT	{ConstantExpr *ce = new ConstantExpr($2); $$ = ce;}
|term				{ $$=$1;}

|expression PLUS expression	{ComplexExpr *ce = new ComplexExpr($1,$3,(Expression::op_type)0);/*Expression::PLUS);*/	$$=ce;}
|expression MINUS expression 	{ComplexExpr *ce = new ComplexExpr($1,$3,(Expression::op_type)1);/*Expression::MINUS);*/ $$=ce;}
|expression TIMES expression 	{ComplexExpr *ce = new ComplexExpr($1,$3,(Expression::op_type)2);/*Expression::TIMES);*/ $$=ce;}
|expression DIV expression 	{ComplexExpr *ce = new ComplexExpr($1,$3,(Expression::op_type)3);/*Expression::DIV);*/ $$=ce;}

;

term:
number_expr TIMES VAR	{std::string v($3); Term *t = new Term($1,getVarID(v),(Term::op_type)2);/*Term::TIMES);*/ $$=t;}
|number_expr DIV VAR	{std::string v($3);Term *t = new Term($1,getVarID(v),(Term::op_type)3);/*Term::DIV);*/ $$=t;}
|VAR			{std::string v($1); Term *t = new Term(1,getVarID(v),(Term::op_type)2);/*Term::TIMES);*/ $$=t;}
;


number_expr:
NUMBER 				{$$=$1;}
|number_expr PLUS number_expr	{$$=$1 +$3;}
|number_expr MINUS number_expr	{$$=$1 -$3;}
|number_expr TIMES number_expr	{$$=$1 *$3;}
|number_expr DIV number_expr 	{$$=$1 /$3;}
;
%%


std::string getVarName(int v){
	std::string val = rsrg->getPL(v-1);
	return val;//.c_str(); 
}




/**
* Private
*/
dd_edge *parse_formula(std::string formula, bool *val){
	buffer = new istringstream(formula);
	lexer = new yyFlexLexer(buffer);
	yyparse();
	delete lexer;
	delete buffer;
	dd_edge * dd = NULL;
	if(ris!= NULL){
		startMDD=clock();
		dd = ris->getMDD();
		endMDD=clock();
		if(dd!=NULL) dd = ctl->copy(dd);
		delete(ris);
		ris = NULL;
		//Controllo la presenza della marcatura iniziale
		dd_edge r(ctl->getMDDForest());
		try
			{
			apply(INTERSECTION, (*(ctl->getInitMark())), (*dd),(r));
			}
		catch(...)
			{
			cerr << "ERROR in INTERSECTION in Parser";
			}
		endMDD2=clock();
		(*val) = (r.getCardinality()!=0);
	}
	return dd;
}

/**
* It parses formula and returns a dd_edge and a bool value (true is the formula is valid for initia mark)
*
**/
dd_edge *CTLParser(dddRS::RSRG r, std::string formula, bool *val){
	rsrg = &r;
	//inizializzo la classe CTL dove ho i riferimenti a rs foreste e domini per tutte le altre classi
	ctl->CTLinit(rsrg->getRS(),rsrg->getInitMark(), rsrg->getNSFt(), rsrg->getDomain());
	return parse_formula(formula,val);
}

/**
* It parses all formulas into file net_name.ctl and returns a dd_edge
*
**/


dd_edge * CTLParser(dddRS::RSRG *r){
	clock_t startOut, endOut;
	bool val;
	rsrg = r;
	std::string filename = rsrg->getNetName();
	ifstream in;
	filename = filename + ".ctl";
	in.open(filename.c_str());
	//inizializzo la classe CTL dove ho i riferimenti a rs foreste e domini per tutte le altre classi
	ctl->CTLinit(rsrg->getRS(),rsrg->getInitMark(), rsrg->getNSFt(), rsrg->getDomain());
	dd_edge *dd;
	filename = filename + ".output";
	FILE *f = fopen(filename.c_str(), "w"); 
	char tmp[255];
	char *line = &tmp[0];
	while(!in.eof()){
		in.getline(line,255,'\n');
		if(std::string(line)!="") {
			cout<<"--- "<<std::string(line)<<" ---"<<endl;
			dd = parse_formula(std::string(line), &val); 
			fprintf(f,"\n ********** %s *********  \n", line);
			if(dd == NULL){
				fprintf(f,"Error during the computatione\n");
				cout<<"Error"<<endl;
			}
			else{	
				startOut = clock();
				cout<<"\tEvaluation: "<<(val?"true":"false")<<endl;
				val?fprintf(f,"Evaluation: true\n"):fprintf(f,"Evaluation: false\n");
				// STAMPA MARCATURE
				if(output_flag == TRUE){
					dd_edge::iterator i = dd->begin();
					int nvar = ctl->getDomain()->getNumVariables();
					while(i!=NULL){// != dd->end()){ 
						int j;
						for(j=1; j <= nvar; j++){
							int val = *(i.getAssignments() + j );
							std::string s = getVarName(j);
							if(val!=0) fprintf(f,"%s(%d) ",s.c_str(), val);
						}//per ogni posto
						++i;
						fprintf(f,"\n");
						fflush(f);
					}//per ogni marcatura
				}//fine stampa
				dd = NULL;
				endOut = clock();
			
				#if PERFORMANCECTL
				cout<<"\tTime set generation: "<<setprecision(7)<<((double)(endMDD-startMDD))/CLOCKS_PER_SEC<<" sec"<<endl;
				cout<<"\tTime set generation and valutation: "<<setprecision(7)<<((double)(endMDD2-startMDD))/CLOCKS_PER_SEC<<" sec"<<endl;
				cout<<"\tTime print: "<<setprecision(7)<<((double)(endOut-startOut))/CLOCKS_PER_SEC<<" sec"<<endl;
				#endif
			}
			cout<<endl;
		}
	}//per ogni riga file
	in.close();
	fclose(f);
	//cout<<"Risultati scritti su file"<<endl;
	return dd;
}






int getVarID(std::string v){
	int val = rsrg->getPL(v);
	if(val == -1) cout<<"Place "<<v<<" not found"<<endl;
	return val +1; 
}

CTLFormula * enableTR(std::string v){
	int val = rsrg->getTR(v);
	if(val == -1) {
		cout<<"Transizione "<<v<<" non trovata"<<endl;
		return new BoolValue(false);
	}
	else{
		int nvar = ctl->getDomain()->getNumVariables();
		//int b = Max_Token_Bound;
		int * pre = (int *) malloc((nvar) * sizeof(int));
		int * inhib = (int *) malloc((nvar) * sizeof(int));
		getPreTR(val,pre);
		getInhTR(val,inhib);
		bool first = true;
		CTLFormula *formula=NULL;
		for(int i = 0; i<nvar;i++){

			if(pre[i]!=0){
				Term *t = new Term(1,i+1,(Term::op_type)2);/*Term::TIMES);*/;
				Inequality *in = new Inequality((Inequality::op_type)3/*>=*/,t,pre[i]);
				CTLFormula *ce;
				if(first){
					first=false;
					ce = in;
				}
				else
					ce = new ComplexBoolFormula(formula,in, (ComplexBoolFormula::op_type)1/*AND*/);
				formula = ce;
			}
			
			if(inhib[i]!=0){
				Term *t = new Term(1,i+1,(Term::op_type)2);/*Term::TIMES);*/;
				Inequality *in = new Inequality((Inequality::op_type)0/*<*/,t,inhib[i]);
				CTLFormula *ce;
				if(first){
					first=false;
					ce = in;
				}
				else
					ce = new ComplexBoolFormula(formula,in, (ComplexBoolFormula::op_type)1/*AND*/);
				formula = ce;
			}





		}
		free(pre);
		free(inhib);
		return formula;
	}
}

/*int main( int argc, const char* argv[] )
{
	//Settare num variabili in ctlmdd ecc...
        yyparse();
	return 1;
} */
