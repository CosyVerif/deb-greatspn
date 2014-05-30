/*
 * CTL.cpp
 *
 *  Created on: 11/gen/2011
 *      Author: Erica Turin
 */

#include "CTL.h"

namespace std {
/*-----------------
 ---	CTLMDD	---
 ------------------*/
CTLMDD * CTLMDD::instance = NULL;
void CTLMDD::CTLinit(dd_edge *rs,dd_edge *initMark,dd_edge *nsf, domain *d){
	my_mdd_forest = rs->getForest();
	my_domain = d;
	this->rs = rs;
	this->nsf = nsf;
	this->initMark = initMark;
	int nvar = my_domain->getNumVariables();
	ins = (int **) malloc(sizeof(int *) * 1);
	*ins = (int*) malloc(sizeof(int) * (nvar + 1));
	int j;
	for (j = 1; j <= nvar; j++) {
		ins[0][j] = DOUBLELEVEL ? -2 : -1;
	}
	my_mtmdd_forest = my_domain->createForest(DOUBLELEVEL, forest::REAL,forest::MULTI_TERMINAL);
	if (DOUBLELEVEL)
	  my_mtmdd_forest->setReductionRule(forest::IDENTITY_REDUCED);
	my_mtmdd_forest->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
	my_mtmdd_forest->setNodeDeletion(forest::OPTIMISTIC_DELETION);


}

dd_edge *CTLMDD::copy(dd_edge * source) {
	dd_edge *r = new dd_edge(source->getForest());
	//UPDATE 23-12-11
	apply(UNION, (*r), (*source), (*r));
	return r;
}
domain *CTLMDD::getDomain() const {
	return my_domain;
}

forest *CTLMDD::getMTMDDForest() const {
	return my_mtmdd_forest;
}
dd_edge *CTLMDD::getNsf() const {
	return nsf;
}
dd_edge *CTLMDD::getInitMark() const {
	return initMark;
}
forest *CTLMDD::getMDDForest() const {
	return my_mdd_forest;
}
dd_edge *CTLMDD::getRS() const{
	return rs;
}
int **CTLMDD::getIns() const{
	return ins;
}

CTLMDD::~CTLMDD() {
	if (ins!=NULL)
	{
			  free(ins[0]);
			  free(ins);
	}
}


/*-------------------------
 ---	ConstantExpr	---
 ---------------------------*/
void ConstantExpr::createMTMDD() {
	CTLMDD *ctl = CTLMDD::getInstance();
	forest * mdd_forest = ctl->getMTMDDForest();
	dd_edge *complete = new dd_edge(mdd_forest);
	int** m = ctl->getIns();
	float *t = (float *) malloc(sizeof(float));
	*t = this->constant;
	if (DOUBLELEVEL)
		mdd_forest->createEdge(m, m, t, 1, *complete);
	else
		mdd_forest->createEdge(m, t, 1, *complete);
	if(t!=NULL)
		free(t);
	if (MTMDD != NULL)
		delete (MTMDD);
	MTMDD = complete;
}
ConstantExpr::ConstantExpr(float constant) {
	this->constant = constant;
	MTMDD = NULL;
}
void ConstantExpr::setConstant(float constant) {
	this->constant = constant;
	if (MTMDD != NULL)
		delete (MTMDD);
	MTMDD = NULL;
}
float ConstantExpr::getConstant() {
	return this->constant;
}
ConstantExpr::~ConstantExpr() {
}

/*-----------------
 ---	Term	---
 ------------------*/

Term::Term(float coeff, int variable, Expression::op_type op) {
	this->coeff = coeff;
	this->variable = variable;
	this->op = op;
	MTMDD = NULL;
}
Term::~Term() {

}

float Term::getCoeff() const {
	return coeff;
}

int Term::getVariable() const {
	return variable;
}

void Term::setCoeff(float coeff) {
	this->coeff = coeff;
	if (MTMDD != NULL)
		delete (MTMDD);
	MTMDD = NULL;
}

void Term::setVariable(int variable) {
	this->variable = variable;
	if (MTMDD != NULL)
		delete (MTMDD);
	MTMDD = NULL;
}

Expression::op_type Term::getOp() const {
	return op;
}

void Term::setOp(Expression::op_type op) {
	this->op = op;
	if (MTMDD != NULL)
		delete (MTMDD);
	MTMDD = NULL;
}

void Term::createMTMDD() {
	
	CTLMDD *ctl = CTLMDD::getInstance();
	forest *mdd_forest = ctl->getMTMDDForest();
	dd_edge *tmp_mdd = new dd_edge(mdd_forest);
	int bound = mdd_forest->getDomain()->getVariableBound(variable, true);
	int val;
	int **m = ctl->getIns();
	float *terminale = (float*) malloc(sizeof(float));
	for (val = 0; val < bound; val++) {
		m[0][variable] = val;
		switch (op) {
		case Expression::PLUS:
			*terminale = coeff + (float) val;
			break;
		case Expression::TIMES:
			*terminale = coeff * (float) val;
			break;
		case Expression::MINUS:
			*terminale = coeff - (float) val;
			break;
		case Expression::DIV:
			*terminale = coeff / (float) val;
			break;
		}
		dd_edge tmp_new_ap(mdd_forest);
		dd_edge *new_ap = &tmp_new_ap;
		if (DOUBLELEVEL)
			mdd_forest->createEdge(m, m, terminale, 1, *new_ap);
		else
			mdd_forest->createEdge(m, terminale, 1, *new_ap);
		(*tmp_mdd) += (*new_ap);
	}
	free(terminale);
	m[0][variable] = DOUBLELEVEL ? -2 : -1;
	if (MTMDD != NULL)
		delete (MTMDD);
	this->MTMDD = tmp_mdd;

}

/*---------------------
 ---	ComplexExpr	---
 ----------------------*/
ComplexExpr::ComplexExpr(Expression * expr1, Expression * expr2, Expression::op_type op){
	this->expr1 = expr1;
	this->expr2 = expr2;
	this->op = op;
	MTMDD = NULL;
	expr1->addOwner();
	expr2->addOwner();

}

ComplexExpr::~ComplexExpr() {
	expr1->removeOwner();
	expr2->removeOwner();
}

Expression * ComplexExpr::getExpr1() const{
	return expr1;
}
void ComplexExpr::setExpr1(Expression * expr1){
	this->expr1 = expr1;
	if(MTMDD!=NULL)
		delete(MTMDD);
	MTMDD = NULL;
}
Expression * ComplexExpr::getExpr2() const{
	return expr2;
}
void ComplexExpr::setExpr2(Expression * expr2){
	this->expr2 = expr2;
	if(MTMDD!=NULL)
		delete(MTMDD);
	MTMDD = NULL;
}

Expression::op_type ComplexExpr::getOp() const {
	return op;
}

void ComplexExpr::setOp(Expression::op_type op) {
	this->op = op;
	if(MTMDD!=NULL)
		delete(MTMDD);
	MTMDD = NULL;
}

void ComplexExpr::createMTMDD() {
	dd_edge * e1 = expr1->getMTMDD();
	dd_edge * e2 = expr2->getMTMDD();
	CTLMDD *ctl = CTLMDD::getInstance();
	forest *mdd_forest = ctl->getMTMDDForest();
	dd_edge *r = new dd_edge(mdd_forest);
	switch (op) {
	case Expression::PLUS:
		(*r) = (*e1) + (*e2);
		break;
	case Expression::TIMES:
		(*r) = (*e1) * (*e2);
		break;
	case Expression::MINUS:
		(*r) = (*e1) - (*e2);
		break;
	case Expression::DIV:
		//UPDATE 23-12-11
		apply(DIVIDE, (*e1), (*e2), (*r));
		break;
	}
	if(MTMDD!=NULL)
		delete(MTMDD);
	MTMDD = r;
}

/*---------------------
 ---	Expression	---
 ----------------------*/
Expression::Expression(){
	MTMDD= NULL;
	countOwner=0;
}
Expression::~Expression(){
	if(MTMDD!=NULL)
		delete(MTMDD);

}
void Expression::addOwner(){
	countOwner++;
}
void Expression::removeOwner(){
	countOwner--;
	if(countOwner<1)
		delete(this);
}

dd_edge *Expression::getMTMDD() {
	if (MTMDD==NULL)
		createMTMDD();
	return MTMDD;
}

/*---------------------
 ---	Inequality	---
 ----------------------*/
float Inequality::getConstant() const {
	return constant;
}

Expression *Inequality::getExpr() const {
	return expr;
}
Inequality::op_type Inequality::getOp() const {
	return op;
}

void Inequality::setConstant(float constant) {
	this->constant = constant;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;

}

void Inequality::setExpr(Expression *expr) {
	this->expr = expr;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}

void Inequality::setOp(op_type op) {
	this->op = op;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;

}

Inequality::Inequality(op_type op, Expression *expr, float constant) {
	this->op = op;
	this->expr = expr;
	this->constant = constant;
	MDD = NULL;
	expr->addOwner();
}
Inequality::~Inequality() {
	expr->removeOwner();
}

void Inequality::createMDD() {

	//se minore di const positiva devo fare complemento
	//se maggiore di const negativa devo fare complemento
	//se <= >= o = 0
	if(MDD!=NULL)
		delete(MDD);
	MDD = NULL;
	if (((op == MIN || op == MINEQ) && constant > 0) || ((op == MAJ || op == MAJEQ) && constant < 0) || (op	== MAJEQ && constant == 0) || (op == MINEQ && constant == 0) || (op
			== EQ && constant == 0)) {
		createMDDByComplement();
	}//altrimenti:
	else {
		CTLMDD *ctl = CTLMDD::getInstance();
		forest *mdd_forest = ctl->getMTMDDForest();
		//UPDATE 23-12-11
		//compute_manager* cm = MEDDLY_getComputeManager();
		dd_edge tmp_complete(mdd_forest);
		dd_edge *complete = &tmp_complete;
		int** m = ctl->getIns();
		float *t = (float *) malloc(sizeof(float));
		*t = this->constant;
		if (DOUBLELEVEL)
			mdd_forest->createEdge(m, m, t, 1, *complete);
		else
			mdd_forest->createEdge(m, t, 1, *complete);

		dd_edge *r = expr->getMTMDD();
		dd_edge q(mdd_forest);
		//UPDATE 23-12-11
		try
			{
			switch (op) {
			case MIN:
				//UPDATE 23-12-11
				apply(LESS_THAN, (*r), (*complete), q);
			break;
			case MAJ:
				//UPDATE 23-12-11
				apply(GREATER_THAN, (*r), (*complete), q);
			break;
			case MINEQ:
				//UPDATE 23-12-11
				apply(LESS_THAN_EQUAL, (*r), (*complete),q);
			break;
			case MAJEQ:
				//UPDATE 23-12-11
				apply(GREATER_THAN_EQUAL, (*r),(*complete), q);
			break;
			case EQ:
				//UPDATE 23-12-11
				apply(GREATER_THAN_EQUAL, (*r),(*complete), q);
			break;
			case NEQ:
				//UPDATE 23-12-11
				apply(NOT_EQUAL, (*r), (*complete), q);
			break;
			}
		}
		catch(...)
			{
			cerr << "Error in createMDD inequality"<<endl;
			return;
			}
		try
			{
			dd_edge * rs = ctl->getRS();
			dd_edge *boole = new dd_edge(ctl->getMDDForest());
			apply(COPY, q, (*boole));
			apply(INTERSECTION, (*rs), (*boole), (*boole));//estraggo da rs quelli che 
			MDD = boole;
			if(t!=NULL)
			free(t);
			}
		catch(...)
			{
			cerr << "Error in createMDD inequality"<<endl;
			if(t!=NULL)
				free(t);
			return;
			}
	}
}

void Inequality::createMDDByComplement() {
	CTLMDD *ctl = CTLMDD::getInstance();
	forest *mdd_forest = ctl->getMTMDDForest();
	dd_edge tmp_complete(mdd_forest);
	dd_edge *complete = &tmp_complete;
	int** m = ctl->getIns();
	float *t = (float *) malloc(sizeof(float));
	*t = this->constant;
	if (DOUBLELEVEL)
		mdd_forest->createEdge(m, m, t, 1, *complete);
	else
		mdd_forest->createEdge(m, t, 1, *complete);

	dd_edge *r = expr->getMTMDD();
	dd_edge complement(mdd_forest);
	try
	{
		switch (op) {
			case MIN: // se chiede i minori prendo i maggiori =
				//UPDATE 23-12-11
				apply(GREATER_THAN_EQUAL, (*r),(*complete), complement);
			break;
			case MAJ: // se chiede i maggiori prendo i minori =
				//UPDATE 23-12-11
				apply(LESS_THAN_EQUAL, (*r), (*complete), complement);
			break;
			case MINEQ:
				//UPDATE 23-12-11
				apply(GREATER_THAN, (*r), (*complete), complement);
			break;
			case MAJEQ:
				//UPDATE 23-12-11
				apply(LESS_THAN, (*r), (*complete), complement);
			break;
			case EQ:
				//UPDATE 23-12-11
				apply(NOT_EQUAL, (*r), (*complete), complement);
			break;
			case NEQ:
				//UPDATE 23-12-11
				apply(EQUAL, (*r), (*complete), complement);
			break;
		}
	}
	catch(...)
		{
		cerr << "Error in createMDDCompl inequality";
		return;
		}
	try
		{
		dd_edge * rs = ctl->getRS();
		dd_edge *boole = new dd_edge(ctl->getMDDForest());
		apply(COPY, complement, (*boole));
		apply(DIFFERENCE, (*rs), (*boole), (*boole));
		MDD = boole;
		if(t!=NULL)
			free(t);
		}
	catch(...)
		{
		cerr << "ERROR in intersection mdd to bdd inequality"; //eccezione
		return;
		}
}

/*---------------------
 ---	BoolValue	---
 ----------------------*/

BoolValue::BoolValue(bool value) {
	this->value = value;
	MDD = NULL;

}

BoolValue::~BoolValue() {
}
void BoolValue::setValue(bool value){
	this->value = value;
	if(MDD!=NULL)
		delete(MDD);
	MDD = NULL;
}
bool BoolValue::getValue(){
	return value;
}

void BoolValue::createMDD(){
	MDD = NULL;
	CTLMDD *ctl = CTLMDD::getInstance();
	if(value){
		dd_edge *rs = new dd_edge(ctl->getMDDForest());
		//UPDATE 23-12-11
		try
			{
			apply(UNION, (*rs), (*ctl->getRS()), (*rs));
			}
		catch(...)
			{
			cerr<<"Error in createMDD BoolValue true";
			return;
			}
		MDD = rs;
	}
	else{
		MDD = new dd_edge(ctl->getMDDForest());
	}

}

/*---------------------
 ---	Deadlock	---
 ----------------------*/

Deadlock::Deadlock(bool value) {
	this->value = value;
	MDD = NULL;

}

Deadlock::~Deadlock() {
}
void Deadlock::setValue(bool value){
	this->value = value;
	if(MDD!=NULL)
		delete(MDD);
	MDD = NULL;
}
bool Deadlock::getValue(){
	return value;
}

void Deadlock::createMDD(){
	CTLMDD *ctl = CTLMDD::getInstance();
	dd_edge *labeled = ctl->getRS();
	dd_edge *r = new dd_edge(ctl->getMDDForest());
	//UPDATE 23-12-11
	try
		{
		apply(PRE_IMAGE, (*labeled), *(ctl->getNsf()), (*r));
		}
	catch(...)
		{
		cerr<<"Error PREIMAGE in createMDD for deadlock"<<endl;
		return;
		}
		if(value){ // stati di deadlock
			try
				{
				apply(DIFFERENCE, (*ctl->getRS()), (*r), (*r));
				MDD = r;
				} 
			catch(...)
				{
				cerr<<"Error in createMDD Deadlock true"<<endl;
				return;
				}			
		}
		else{
			MDD = r;
		}

}


/*-------------------------
 ---	CTLOperation	---
 --------------------------*/
CTLOperation::CTLOperation(CTLFormula *formula1,CTLFormula *formula2) {
	this->formula1 = formula1;
	this->formula2 = formula2;
	this->op = EU;
	MDD = NULL;
	formula1->addOwner();
	formula2->addOwner();

}
CTLOperation::CTLOperation(CTLFormula *formula1, CTLOperation::op_type op) {
	this->formula1 = formula1;
	this->formula2 = NULL;
	this->op = op;
	MDD = NULL;
	formula1->addOwner();
}
CTLOperation::~CTLOperation() {
	if(formula1!=NULL) formula1->removeOwner();
	if(formula2!=NULL) formula2->removeOwner();

}
CTLFormula * CTLOperation::getFormula1() const {
	return formula1;
}
void CTLOperation::setFormula1(CTLFormula * formula1) {
	this->formula1 = formula1;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}
CTLFormula * CTLOperation::getFormula2() const {
	return formula2;
}
void CTLOperation::setFormula2(CTLFormula * formula2) {
	this->formula2 = formula2;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}

CTLOperation::op_type CTLOperation::getOp() const {
	return op;
}

void CTLOperation::setOp(CTLOperation::op_type op) {
	this->op = op;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}

void CTLOperation::createMDD(){
	switch(op){
	case EU:
		createEUMDD();
		break;
	case EG:
		createEGMDD();
		break;
	case EF:
			createEFMDD();
			break;
	case EX:
		createEXMDD();
		break;
	}
}

void CTLOperation::createEXMDD(){
	CTLMDD *ctl = CTLMDD::getInstance();
	dd_edge *labeled = formula1->getMDD();
	dd_edge *r = new dd_edge(ctl->getMDDForest());
	//UPDATE 23-12-11
	try
		{
		apply(PRE_IMAGE, (*labeled), *(ctl->getNsf()), (*r));
		apply(INTERSECTION, (*r),((*ctl->getRS())), (*r));
		}
	catch(...)
		{
		cerr<<"Error PREIMAGE in createEXMDD ";
		return;
		}
	MDD = r;

}
void CTLOperation::createEGMDD(){
	CTLMDD *ctl = CTLMDD::getInstance();
	dd_edge *labeled = formula1->getMDD();
	dd_edge *r = new dd_edge(ctl->getMDDForest());
	dd_edge pre_r(ctl->getMDDForest());
	dd_edge pred_of_r(ctl->getMDDForest());
	(*r)=(*labeled);
	do{
		pre_r = (*r); // risultati ottenuti all'iterazione precedente
		try
			{
			apply(PRE_IMAGE, (*r),*(ctl->getNsf()),pred_of_r);// 		}
		//UPDATE 23-12-11
			apply(INTERSECTION,pred_of_r,((*ctl->getRS())), pred_of_r);
			apply(INTERSECTION, pred_of_r,(*r),(*r));
			}
		catch(...)
			{
			cerr<<"Error INTERSECTION in createEGMDD "<<endl;
			return;
			}
	}while(((*r)!=pre_r));
	MDD = r;

}
void CTLOperation::createEFMDD(){
	CTLMDD *ctl = CTLMDD::getInstance();
	dd_edge *labeled = formula1->getMDD();
	dd_edge *r = new dd_edge(ctl->getMDDForest());
	dd_edge pre_r(ctl->getMDDForest());
	dd_edge pred_of_r(ctl->getMDDForest());
	(*r)=(*labeled);
	do{
		pre_r = (*r); // risultati ottenuti all'iterazione precedente
		try
			{
			apply(PRE_IMAGE, (*r),*(ctl->getNsf()),pred_of_r);
		//UPDATE 23-12-11
			apply(INTERSECTION,pred_of_r,((*ctl->getRS())), pred_of_r);
			apply(UNION, pred_of_r,(*r),(*r));
			}
		catch(...)
			{
			cerr<<"Errore in createEGMDD "<<endl;
			return;
			}
	}while(((*r)!=pre_r));
		MDD = r;

}
void CTLOperation::createEUMDD(){
	// E formula1 U formula2
	CTLMDD *ctl = CTLMDD::getInstance();
	dd_edge *labeled1 = formula1->getMDD();
	dd_edge *labeled2 = formula2->getMDD();
	dd_edge *r = new dd_edge(ctl->getMDDForest());
	dd_edge pre_r(ctl->getMDDForest());
	dd_edge pred_of_r(ctl->getMDDForest());
	dd_edge pred_of_r_labeled1(ctl->getMDDForest());
	(*r)=(*labeled2);
	do{
		pre_r = (*r); // risultati ottenuti all'iterazione precedente
		try
			{
			apply(PRE_IMAGE, (*r),*(ctl->getNsf()),pred_of_r);
			apply(INTERSECTION,pred_of_r,((*ctl->getRS())), pred_of_r);
			apply(INTERSECTION, pred_of_r,(*labeled1),pred_of_r_labeled1);
			apply(UNION, pred_of_r_labeled1,(*r),(*r));
			}
		catch(...)
			{
			cerr<<"Error  in createEUMDD"<<endl;
 			return;
			}
	}while(((*r)!=pre_r));
	MDD = r;
}


/*-----------------------------
 ---	ComplexBoolFormula	---
 ------------------------------*/
ComplexBoolFormula::ComplexBoolFormula(CTLFormula *formula1,CTLFormula *formula2, op_type op) {
	this->formula1 = formula1;
	this->formula2 = formula2;
	this->op = op;
	MDD = NULL;
	formula1->addOwner();
	formula2->addOwner();
}
ComplexBoolFormula::ComplexBoolFormula(CTLFormula *formula1) {
	this->formula1 = formula1;
	this->formula2 = NULL;
	this->op = NOT;
	MDD = NULL;
	formula1->addOwner();
}
ComplexBoolFormula::~ComplexBoolFormula() {
	if(formula1!=NULL) formula1->removeOwner();
	if(formula2!=NULL) formula2->removeOwner();

}
CTLFormula * ComplexBoolFormula::getFormula1() const {
	return formula1;
}
void ComplexBoolFormula::setFormula1(CTLFormula * formula1) {
	this->formula1 = formula1;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}
CTLFormula * ComplexBoolFormula::getFormula2() const {
	return formula2;
}
void ComplexBoolFormula::setFormula2(CTLFormula * formula2) {
	this->formula2 = formula2;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}

ComplexBoolFormula::op_type ComplexBoolFormula::getOp() const {
	return op;
}

void ComplexBoolFormula::setOp(ComplexBoolFormula::op_type op) {
	this->op = op;
	if (MDD != NULL)
		delete (MDD);
	MDD = NULL;
}

void ComplexBoolFormula::createMDD() {
	dd_edge * f1 = formula1->getMDD();
	dd_edge * f2 = formula2!=NULL? formula2->getMDD(): NULL;
	CTLMDD *ctl = CTLMDD::getInstance();
	forest *mdd_forest = ctl->getMDDForest();
	dd_edge *r = new dd_edge(mdd_forest);
	try
		{
		switch (op) {
		case NOT:
			{
			dd_edge *rs = new dd_edge(ctl->getMDDForest());
// 		e = cm->apply(compute_manager::UNION, (*rs), (*ctl->getRS()), (*rs));
// 		e = cm->apply(compute_manager::DIFFERENCE, (*rs), (*f1),(*r));
			apply(UNION, (*rs), (*ctl->getRS()), (*rs));
			apply(DIFFERENCE, (*rs), (*f1),(*r));
			break;
			}
		case AND:
			apply(INTERSECTION, (*f1), (*f2),(*r));
		break;
		case OR:
			apply(UNION, (*f1), (*f2),(*r));
		break;
		}
		}
	catch(...)
		{
		cerr << "ERROR in createMDD complex Bool Expr";
		return;
		}
	MDD = r;

}

/*---------------------
 ---	CTLFormula	---
-----------------------*/
dd_edge *CTLFormula::getMDD() {
	if (MDD==NULL)
		this->createMDD();
	return MDD;
}
void CTLFormula::addOwner(){
	countOwner++;
}
void CTLFormula::removeOwner(){
	countOwner--;
	if(countOwner<1)
		delete(this);
}


}

