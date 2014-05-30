#ifndef MEDD_H_
#define MEDD_H_

#include <stdio.h>
#include <stdlib.h>
#ifndef __STD_H__
	#define __STD_H__
	#include <stdio.h>
#endif

#ifndef __STDL_H__
	#define __STDL_H__
	#include <stdlib.h>
#endif

#include <iostream> 
#include <meddly.h>
#include <meddly_expert.h>

#ifndef __PRS_H__
	#define __PRS_H__
	#include "../AUTOMA/parser.h"
#endif

extern "C" { 
#include "../../INCLUDE/const.h"
#include "../../INCLUDE/struct.h"
#include "../../INCLUDE/var_ext.h"
#include "../../INCLUDE/fun_ext.h"
#include "../../INCLUDE/macros.h"
}


#define NDEBUG 1

#ifndef __ASS_H__
	#define __ASS_H__
	#include <assert.h>
#endif

 
#ifndef __SSTR_H__
	#define __SSTR_H__
	#include <sstream> 
#endif

#ifndef __FSTR_H__
	#define __FSTR_H__
	#include <fstream> 
#endif

#ifndef __MATH_H__
	#define __MATH_H__
	#include <math.h>
#endif

#ifndef __LIM_H__
	#define __LIM_H__
	#include <limits>
#endif

#ifndef __IOM_H__
	#define __IOM_H__
	#include <iomanip>
#endif

#ifndef __MAP_H__
	#define __MAP_H__
	#include <map>
#endif

#ifndef __LST_H__
	#define __LST_H__
	#include <list>
#endif

#ifndef __PRS_H__
	#define __PRS_H__
	#include "../AUTOMA/parser.h"
#endif


#include <time.h>


#define  DEBUG 0
#define  DEBUG1 0
#define  DEBUG2 0
#define  DEBUG3 0
#define  DEBUG4 0
#define  DEBUGPARSER 0
#define  MAX_ID 32
#define  IOPRECISION 12
#define  MAXSERV 255
#define  MAXPRIO 127
//Use to endoce the id transition in the MTMDD for the AUTOMATON
#define  INCTRAN 1000 
//predefined "machine epsilon", a numeric value representing the difference between 1 and the least value greater than 1 that is representable [1]
#define _DIFFMIN(T) numeric_limits<T>::epsilon()





using namespace std;

//!Exception for Input/Output
class ExceptionIO{

std::string mess;
public:
	//! Empty constructors 
	ExceptionIO() {mess="";};
	//! constructor takes in input a message
	ExceptionIO(std::string mess) {this->mess=mess;};
	//! \name Get of methods use to access at the data structures
  	//@{
	//!it returns message
	std::string get(void) {return mess;};
	//@}
	friend ostream& operator<<(ostream& out,class ExceptionIO d){out<<d.mess<<endl; return out;};
};



namespace dddRS
{
 using namespace std;
 using namespace MEDDLY;

//!Class RS
/*!
This class is used to manage the RS and compute performance indexes
*/


class RSRG{
protected:
domain* d;

//compute_manager* cm;

forest* fRS; //RS forest
forest* fTranB; //transitions forest
forest* fTranR; //transitions + rates forest
forest* fEV; //RS + id states forest 

dd_edge* rs;
dd_edge* indexrs;
dd_edge* NSFt;//timed transitions
dd_edge* NSFtReal;//timed transitions with rates
dd_edge* DiagReal;//Matrix diagonal
dd_edge* NSFi;//immediate transitions
dd_edge** VectNSFtReal;//vector of timed transitions with rates X throughput

//to menage priorities
dd_edge* prioNSFt[MAXPRIO];
dd_edge* defNSFt[MAXPRIO];
//to menage priorities

double cardinality;
std::string netname;
dd_edge *initMark;
int npl; //Places' number

//vector to create MDD and MXM
int** ins; 
int** to; 
int**  from;
int**  pfrom;
//vector to create MDD and MXM

map <std::string, int> S2Ipl;
map <std::string, int> S2Itr;

public:
  
	//! Empty constructor
	RSRG(){d=NULL;fRS=fTranB=fTranR=fEV=NULL;indexrs=rs=NULL;//cm=NULL;
	       NSFt=NSFtReal=DiagReal=NSFi=NULL;VectNSFtReal=NULL;cardinality=0.0;ins=to=pfrom=from=NULL;
	       for (int i=0;i<MAXPRIO;i++)
			{
			prioNSFt[i]=defNSFt[i]=NULL;
			}
	      };
	//!Constructor: it takes in input the  place number and the net name; and initializes the domain and the forest.
	RSRG(const int&, std::string);
	//!it takes in input the initial marking (in GreatSPN format) and  encodes it in DD. For each place a variable is inserted.
	bool init_RS(const Net_Mark_p&);
	//!destructor;
	~RSRG(){
		if (to!=NULL)
		  {
		  free(to[0]);
		  free(to);
		  }
		if (from!=NULL)
		  {
		  free(from[0]);
		  free(from);
		  }
		if (ins!=NULL)
		  {
		  free(ins[0]);
		  free(ins);
		  }
		if (pfrom!=NULL)
		  {
		  free(pfrom[0]);
		  free(pfrom);
		  }
		if (rs!=NULL)
			delete rs;
		if (initMark!=NULL)
			delete initMark;
		if (NSFt!=NULL)
			delete NSFt;
		if (prioNSFt[0]!=NULL)
			{
			for (int i=0;i<MAXPRIO;i++)
				{
				delete prioNSFt[i];
				delete defNSFt[i];
				}
			}
		if (NSFi!=NULL)
			delete NSFi;
		if (NSFtReal!=NULL)
			delete NSFtReal;
		if (DiagReal!=NULL)
			delete DiagReal;
		};
	//! \name Methods use to build the NEXT STATE FUNCTIONS
  	//@{
	//! it takes in input matrices I,O,H for a transition and its type and computes its next state function. 
	bool MakeNextState(int* f,int* t, int* h,const int& tt);
	//! it takes in input matrices I,O,H for a transition and its type and computes recursively its next state function. It returns -1 in case of error 0 otherwise.
	void MakeNextState(int* f,int* t, int* h,const int& tt,int pl);
	//@}
	
	//! \name Methods use to generate the RS
  	//@{
	 //! it generates the RS using the next state function for models with only timed transitions. It returns -1 in case of error 0 otherwise. 
	bool genRSTimed();
	//! it generates the RS using the next state function for models with timed and immediate transitions.  It returns -1 in case of error 0 otherwise.
	bool genRSAll();
	//@}
	
	//! \name Methods use to index the RS
  	//@{
	//! it creates an RS EV+MDD from the RS MDD. It returns -1 in case of error 0 otherwise.
	bool IndexRS();
	//@}
	
	//! \name Methods use to solve the underlying CTMC
	//@{
	//!It computes the probability vector and the transition throughput using Jacobi's method. The results are saved in <netname>.prob and <netname>.sta. It returns -1 in case of error 0 otherwise.
	bool JacobiSolver();
	//@}
	
	//! it prints the RS
	friend ostream& operator<<(ostream& out,class RSRG& rs)
		{
		dd_edge::iterator i = rs.rs->begin();
		int val,z=0;
		while(i!=0)
			{
			out<<"M"<<z<<"\n\t"; 
			for(int j=1; j <= rs.npl; j++)
				{
				val = *(i.getAssignments() + j );
				if ((val!=0))
					out<<rs.getPL(j-1)<<"("<<val<<")";
				}//per ogni posto
			out<<endl;
			++i;
			++z;	
			}//per ogni marcatura
		return out;
		}//fine stampa


	//! \name Methods use to produce output 
	//@{
	//!It returns the RS cardinality
	double getSizeRS(){return rs->getCardinality(); };	
	//!It prints the RS and the domain info.	
	void statistic(){cout<<"\n-----------RS-----------\n";
			 rs->show(stdout,2);
			 
			 cout<<"\n---------RG---------\n";
			NSFt->show(stdout,2);
			 //d->showInfo(stdout);
			 };	
	//@}
	//! \name Methods use to get from the transition/place name its corresponding integer. 
	//@{
	//!It takes in input a place name and returns its corresponding interger.
	int getPL(const std::string& name)
		{
		if (S2Ipl.find(name) == S2Ipl.end())
			return -1;
		else
			return S2Ipl[name];
		};
	//!It takes in input a integer and returns its corresponding place name.
	std::string getPL(const int id)
		{
			return std::string(tabp[id].place_name);
		};
	//!It takes in input a transition name and returns its corresponding interger.
	int getTR(const std::string& name)
		{
		if (S2Itr.find(name) == S2Itr.end())
			return -1;
		else
			return S2Itr[name];
		};
	//!It takes in input a integer and returns its corresponding transition name.
	std::string getTR(const int id)
		{
		return std::string(tabt[id].trans_name);
		};
	//@}
	dd_edge *getRS()  { return rs;};
	dd_edge *getInitMark()  { return initMark;};
	dd_edge *getNSFt()  { return NSFt;};
	domain *getDomain()  { return d;};
	std::string getNetName(){ return netname;};
};


//!Class RSRGAuto
/*!
This class is used to manage the RS augmented with the Automaton
*/
class RSRGAuto: public RSRG{
int Top;
int Bot;
//op_info* OpPOST;
//expert_compute_manager* expcm;
forest* fRG;
public:
	//! Empty constructor
	RSRGAuto(){ RSRG();};
	//!Constructor: it takes in input the  place number and the net name; and initializes the domain and the forest. Observe that the last level (|P|+2) is used to encode the automaton state.
	RSRGAuto(const int&, std::string);
	bool init_RS(const Net_Mark_p& net_mark);
	//! it takes in input matrices I,O,H for a transition and its type and computes its next state function. 
	bool MakeNextState(int* f,int* t, int* h,const int& tt,int AA, map <int, map <int, class ATRANSITION> >& automa);
	//! it takes in input matrices I,O,H for a transition and its type and computes its next state function  considering the automanton state. 
	bool MakeNextState(int* f,int* t, int* h,const int& tt,int AA);
	//! it computes the RG and saves it in the wngr file according to GreatSPN format. Variable outState  enables the saving in the file *.outT 
	bool ComputingRG(const bool& output,FILE *,FILE*,const int& Top,const int& Bot,set <int>& InitSet,bool outState);
	//! it prints the RS
	friend ostream& operator<<(ostream& out,class RSRGAuto& rs)
		{
		dd_edge::iterator i = rs.rs->begin();
		int nvar = rs.fRS->getDomain()->getNumVariables();
		int val;
		while(i!=0)
			{ 
			for(int j=1; j <= nvar; j++)
				{
				val = *(i.getAssignments() + j );
				if ((val!=0)&&(j!=nvar))
					out<<rs.getPL(j-1)<<"("<<val<<")";
				if (j==nvar)
					out<<" - L"<<"("<<val<<")\n";
				}//per ogni posto
			++i;
			}//per ogni marcatura
		return out;
		}//fine stampa
	//!it clears the next state functions
	void clearNSF()
		{
		NSFt->clear();//timed transitions
		NSFtReal->clear();//timed transitions with rates
		DiagReal->clear();//Matrix diagonal
		NSFi->clear();//immediate transitions
		for (int i=0; i<ntr;i++)
			{
			VectNSFtReal[i]->clear();
			}
		}
	//!It takes in input the transition id and its rate encoded in a double and compute the corresponding rate for marking dependent.
	void  checkRate(float& val,const int* plmark);
};


};
#endif /* MEDD_H_ */

