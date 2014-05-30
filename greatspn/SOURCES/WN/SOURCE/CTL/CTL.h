/*
 * CTL.h
 *
 *  Created on: 11/gen/2011
 *      Author: Erica Turin
 */

#ifndef CTL_H_
#define CTL_H_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <meddly.h>
#include <meddly_expert.h>
#define DOUBLELEVEL false


namespace std {
/*-----------------
 ---	CTLMDD	---
 ------------------*/
/**
 * This class contains all reference about RS next state function and their forest.
 *
 **/
 using namespace MEDDLY;
class CTLMDD {
private:
	static CTLMDD * instance;
	domain *my_domain;
	forest *my_mtmdd_forest;
	forest *my_mdd_forest;
	dd_edge *rs;
	dd_edge *initMark;
	dd_edge *nsf;
	int** ins;
	CTLMDD(){}

public:
	static CTLMDD *getInstance(){
		if(instance==NULL){
			static CTLMDD tmp;
			instance = &tmp;
		}
		return instance;
	}

	virtual ~CTLMDD();
	void CTLinit(dd_edge *rs,dd_edge *initMark,dd_edge *nsf, domain *d);
    domain *getDomain() const;
    forest *getMTMDDForest() const;
    forest *getMDDForest() const;
    dd_edge *getRS() const;
    dd_edge *getNsf() const;
    dd_edge *getInitMark() const;
    int **getIns() const;
    dd_edge *copy(dd_edge * source);
};
/*---------------------
 ---	CTLFormula	---
 -----------------------*/
/**
 * CTL Formula.
 * */

class CTLFormula {
private:
	int countOwner;
protected:
	/**
	 * proposition MDD (boolean)
	 * */
	dd_edge *MDD;
	/**
	 * create proposition MDD (boolean)
	 * */
	virtual void createMDD()=0;
public:
	CTLFormula(){ countOwner = 0;}
	virtual ~CTLFormula(){
		if (MDD != NULL)
				delete (MDD);
	}
	/**
	 * Create, if not yet, and return a MDD representation of the term.
	 * @return MDD representation of the term
	 * */
	dd_edge *getMDD();
	void addOwner();
	void removeOwner();
};

/*-----------------------------
 ---	ComplexBoolFormula	---
 ------------------------------*/
/**
 * Bool expression compose by two CTL formula linked through operator.
 * This class represent bool expression with form formula1 op formula2 for binary operator (AND and OR).
 * This class represent bool expression with form op formula1 for unary operator (only NOT).
 * */
class ComplexBoolFormula: public std::CTLFormula {
public:
	/**
	 * Type of logic operator
	 * */
	enum op_type {
		NOT = 0, AND = 1, OR = 2
	};
private:
	CTLFormula *formula1;
	CTLFormula *formula2; // if op = NOT this value is null
	op_type op;
	void createMDD();
public:
	/**
	 * Constructor for bool expression with binary operator.
	 * @param formula1 value of the first CTL formula
	 * @param formula2 value of the second CTL formula
	 * @param op value of operator (AND or OR)
	 * */
	ComplexBoolFormula(CTLFormula *formula1, CTLFormula *formula2, op_type op);
	/**
	 * Constructor for bool expression with unary operator. The operator is NOT.
	 * @param formula1 value of the first CTL formula
	 *
	 * */
	ComplexBoolFormula(CTLFormula *formula1);
	virtual ~ComplexBoolFormula();

	/**
	 * Return the first CTL formula.
	 * @return formula1
	 * */
	CTLFormula * getFormula1() const;
	/**
	 * Set the first formula.
	 * @param formula1 the CTL formula to set
	 * */
	void setFormula1(CTLFormula * formula1);
	/**
	 * Return the second formula.
	 * @return formula2
	 * */
	CTLFormula * getFormula2() const;
	/**
	 * Set the second formula.
	 * @param formula2 the CTL formula to set
	 * */
	void setFormula2(CTLFormula * formula2);
	/**
	 * Return the operator value.
	 * @return op
	 * */
	ComplexBoolFormula::op_type getOp() const;
	/**
	 * Set the operator value.
	 *@param op value to set
	 * */
	void setOp(ComplexBoolFormula::op_type op);
};
/*-------------------------
 ---	CTLOperation	---
 --------------------------*/
/**
 * Representing operation CTL.
 * Representing operation CTL:
 * EX formula
 * E formula U formula
 * EG formula
 * */
class CTLOperation: public std::CTLFormula {
public:
	/**
	 * This is the type of CTL operator.
	 * */
	enum op_type {
		EX = 0, EU = 1, EG = 2, EF = 3
	};
private:
	CTLFormula * formula1;
	CTLFormula * formula2;
	op_type op;
	virtual void createMDD();
	void createEXMDD();
	void createEGMDD();
	void createEUMDD();
	void createEFMDD();
public:
	/**
	 * Constructor for CTL formula with binary operator EU.
	 * @param formula1 value of the first CTL formula
	 * @param formula2 value of the second CTL formula
	 * */
	CTLOperation(CTLFormula *formula1, CTLFormula *formula2);
	/**
	 * Constructor for CTL formula with unary operator.
	 * @param formula1 value of the CTL formula
	 * @param op value of operator (EX or EG)
	 * */
	CTLOperation(CTLFormula *formula1, CTLOperation::op_type op);
	virtual ~CTLOperation();
	/**
	 * Return the first CTL formula.
	 * @return formula1
	 * */
	CTLFormula * getFormula1() const;
	/**
	 * Set the first formula.
	 * @param formula1 the CTL formula to set
	 * */
	void setFormula1(CTLFormula * formula1);
	/**
	 * Return the second formula.
	 * @return formula2
	 * */
	CTLFormula * getFormula2() const;
	/**
	 * Set the second formula.
	 * @param formula2 the CTL formula to set
	 * */
	void setFormula2(CTLFormula * formula2);
	/**
	 * Return the operator value.
	 * @return op
	 * */
	CTLOperation::op_type getOp() const;
	/**
	 * Set the operator value.
	 *@param op value to set
	 * */
	void setOp(CTLOperation::op_type op);
	dd_edge *getMDD();
};

/*-----------------------------
 ---	AtomicProposition	---
 ------------------------------*/
/**
 * Representing atomic proposition.
 * */
class AtomicProposition: public CTLFormula {

public:
	AtomicProposition() {
	}
	virtual ~AtomicProposition() {
	}

};

/*-------------------------
 ---	BoolValue	---
 ---------------------------*/
/**
 * Atomic proposition as boolean value.
 * */

class BoolValue: public std::AtomicProposition {
private:
	bool value;
	void createMDD();
public:
	/**
	 * Constructor.
	 * @param value a boolean value
	 * */
	BoolValue(bool value);
	virtual ~BoolValue();
	/**
	 * Set a new boolean value.
	 * @param value a boolean value
	 * */
	void setValue(bool value);
	/**
	 * Return the boolean value.
	 * @return boolean value
	 * */
	bool getValue();
};

/*-------------------------
 ---	Deadlock	---
 ---------------------------*/
/**
 * Atomic proposition for deadlock state o deadlock free state.
 * If value is true it finds deadlock state, otherwise it finds deadlock free state.
 * */

class Deadlock: public std::AtomicProposition {
private:
	bool value;
	void createMDD();
public:
	/**
	 * Constructor.
	 * @param value a boolean value
	 * */
	Deadlock(bool value);
	virtual ~Deadlock();
	/**
	 * Set a new boolean value.
	 * @param value a boolean value
	 * */
	void setValue(bool value);
	/**
	 * Return the boolean value.
	 * @return boolean value
	 * */
	bool getValue();
};


/*---------------------
 ---	Expression	---
 ----------------------*/
/**
 * Abstract class. This class representing arithmetic expression with tree structure.
 * */
class Expression {
public:
	/**
	 * This is the type of operator
	 * */
	enum op_type {
		PLUS = 0, MINUS = 1, TIMES = 2, DIV = 3
	};
	/**
	 * Array for translate op_type to string.
	 * */
	static char op_string[4];
protected:
	int countOwner; // number of owner
	/**
	 * expression MTMDD (real)
	 * */
	dd_edge *MTMDD;
	/**
	 * create expression MTMDD (real)
	 * */
	virtual void createMTMDD()=0;

public:
	Expression();
	virtual ~Expression();
	/**
	 * Create, if not yet, and return a MDD representation of the term.
	 * @return MTMDD representation of the term
	 * */
	dd_edge *getMTMDD();
	void addOwner();
	void removeOwner();
};

/*---------------------
 ---	Inequality	---
 ----------------------*/
/**
 * Inequality class. This class representing inequality with the follow form:
 * expression op constant
 *
 * */

class Inequality: public AtomicProposition {
public:
	/**
	 * Type of compare operator*/
	enum op_type {
		MIN = 0, MAJ = 1, MINEQ = 2, MAJEQ = 3, EQ = 4, NEQ = 5
	};
private:
	op_type op;
	Expression *expr;
	float constant;
	void createMDD();
	void createMDDByComplement();
public:
	/**
	 * Constructor.
	 * @param op operator
	 * @param expr expression
	 * @param constant value of constant
	 * */
	Inequality(op_type op, Expression *expr, float constant);
	virtual ~Inequality();
	/**
	 * Return the constant value.
	 * @return constant value.
	 * */
	float getConstant() const;
	/**
	 * Return the expression.
	 * @return expression.
	 * */
	Expression *getExpr() const;
	/**
	 * Set a new constant value.
	 * @param constant value to set
	 * */
	void setConstant(float constant);
	/**
	 * Set a new expression.
	 * @param expr value to set
	 * */
	void setExpr(Expression *expr);
	/**
	 * Return the op value.
	 * @return op value.
	 * */
	op_type getOp() const;
	/**
	 * Set a new op value.
	 * @param op value to set
	 * */
	void setOp(op_type op);
};


/*---------------------
 ---	ComplexExpr	---
 ----------------------*/
/**
 * Expression compose by two sub expression linked through operator.
 * This class represent expression with form expr1 op expr2
 * */

class ComplexExpr: public Expression {
private:
	Expression * expr1;
	Expression * expr2;
	Expression::op_type op;
	void createMTMDD();
public:
	/**
	 * Constructor.
	 * @param expr1 value of the first expression
	 * @param expr2 value of the second expression
	 * @param op value of operator
	 * */
	ComplexExpr(Expression * expr1, Expression * expr2, Expression::op_type op =
			Expression::PLUS);
	virtual ~ComplexExpr();
	/**
	 * Return the first expression.
	 * @return expr1
	 * */
	Expression * getExpr1() const;
	/**
	 * Set the first expression.
	 * @param expr1 the expression to set
	 * */
	void setExpr1(Expression * expr1);
	/**
	 * Return the second expression.
	 * @return expr2
	 * */
	Expression * getExpr2() const;
	/**
	 * Set the second expression.
	 * @param expr2 the expression to set
	 * */
	void setExpr2(Expression * expr2);
	/**
	 * Return the operator value.
	 * @return op
	 * */
	Expression::op_type getOp() const;
	/**
	 * Set the operator value.
	 *@param op value to set
	 * */
	void setOp(Expression::op_type op);
};

/*-----------------
 ---	Term	---
 ------------------*/
/**
 * Term Class. This class representing term with the follow form:
 * coeff op variable
 *
 * */
class Term: public Expression {
private:
	int variable;//indice della variabile in MDD e non label!!! Maching tra indice e variabile a livello di parser!
	float coeff;
	Expression::op_type op;
	void createMTMDD();
public:
	/**
	 * Constructor.
	 * @param coeff value of the term coefficient
	 * @param variable value of id variable
	 * @param op value of operator
	 * */
	Term(float coeff, int variable, Expression::op_type op = Expression::TIMES);
	~Term();
	/**
	 * Return the coefficient value.
	 * @return coefficient value.
	 * */
	float getCoeff() const;
	/**
	 * Return the variable id value.
	 * @return variable id value
	 * */
	int getVariable() const;
	/**
	 * Set a new coefficient value.
	 * @param coeff coefficient value*/
	void setCoeff(float coeff);
	/**
	 * Set a new variable id.
	 * @param variable a variable id*/
	void setVariable(int variable);
	/**
	 * Create, if not yet, and return a MDD representation of the term.
	 * @return MDD representation of the term*/
	Expression::op_type getOp() const;
	/**
	 * Set the operator value.
	 *@param op value to set
	 * */
	void setOp(Expression::op_type op);

};


/*-------------------------
 ---	ConstantExpr	---
 --------------------------*/
/**
 * Representing a constant
 * */
class ConstantExpr: public Expression {
private:
	float constant;
	void createMTMDD();
public:
	/**
	 * Constructor
	 * @param constant constant value
	 * */
	ConstantExpr(float constant);
	virtual ~ConstantExpr();
	/**
	 * Set constant value.
	 * @param constant constant value
	 * */
	void setConstant(float constant);
	/**
	 * Return constant value
	 * @return constant value
	 * */
	float getConstant();
};



}

#endif /* CTL_H_ */
