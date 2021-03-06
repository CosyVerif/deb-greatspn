

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "medd.h"



extern ifstream fin;
extern ofstream fout;
extern int Max_Token_Bound;
extern int AState;
extern double _prec;
extern int _iter;
extern int out_mc;

namespace dddRS
{


RSRG::RSRG(const int& npl,std::string netname){
  
this->cardinality=0.0;  
this->npl=npl;
this->netname=netname;


MEDDLY::initialize(); 


//Create DD domain
d = createDomain();
int* bounds = (int *) malloc((npl) * sizeof(int*));
for (int i=0;i<npl;i++)
  	{
    	bounds[i]=Max_Token_Bound;
  	}
d->createVariablesBottomUp(bounds, npl);

// Create DD forests
fRS = d->createForest(false, forest::BOOLEAN,forest::MULTI_TERMINAL);	
fRS->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fRS->setNodeDeletion(forest::OPTIMISTIC_DELETION);

fTranB =d->createForest(true, forest::BOOLEAN, forest::MULTI_TERMINAL);
fTranB->setReductionRule(forest::IDENTITY_REDUCED);
//fTranB->setReductionRule(forest::QUASI_REDUCED);
fTranB->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fTranB->setNodeDeletion(forest::OPTIMISTIC_DELETION);

fTranR=d->createForest(true, forest::REAL, forest::MULTI_TERMINAL);
fTranR->setReductionRule(forest::IDENTITY_REDUCED);
fTranR->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fTranR->setNodeDeletion(forest::OPTIMISTIC_DELETION);

//it is initialized only when it needs
fEV=NULL;


//Create DD edge

rs = new dd_edge(fRS);
initMark = new dd_edge(fRS);
indexrs= NULL;
NSFt = new dd_edge(fTranB);
//For priorities
for (int i=0;i<MAXPRIO;i++)
	{
	prioNSFt[i]=defNSFt[i]=NULL;
	}
//For priorities

NSFi = new dd_edge(fTranB);
NSFtReal = new dd_edge(fTranR);
DiagReal = new dd_edge(fTranR);
VectNSFtReal = (dd_edge **) malloc((ntr)* sizeof(dd_edge*));
for (int i=0; i<ntr;i++)
	{
	VectNSFtReal[i]= new dd_edge(fTranR);
	}

//Create vector
to= (int **) malloc((1)* sizeof(int*));
to[0]=(int *) malloc((npl+1) * sizeof(int));
from= (int **) malloc((1)* sizeof(int*));
from[0] =(int *) malloc((npl+1) * sizeof(int));
ins=(int **) malloc((1)* sizeof(int*));
ins[0]=(int *) malloc((npl+1) * sizeof(int));

pfrom=(int **) malloc((1)* sizeof(int*));
pfrom[0]=(int *) malloc((npl+1) * sizeof(int));

for (int i=0;i<npl+1;i++)
	{
	to[0][i]=pfrom[0][i]=from[0][i]=ins[0][i]=-2;
	}


//Create mapping  between Place name and interger
for (int i=0;i<npl;i++)
	{
	S2Ipl[std::string(tabp[i].place_name)]=i;
	}

for (int i=0;i<ntr;i++)
	{
	S2Itr[std::string(tabt[i].trans_name)]=i;
	}

//Free memory
free(bounds);
}


bool RSRG::init_RS(const Net_Mark_p& net_mark){

ins[0][0]=0;
for(int pl = 0 ; pl < npl; pl++)
	{/* foreach place */
        ins[0][pl+1]=net_mark[pl].total;
  	}/* foreach place */
fRS->createEdge(ins, 1, *rs); 
fRS->createEdge(ins, 1, *initMark);
#if DEBUG
for (int i=0;i<npl+1;i++)
		{
		cout<<"["<<i<<"]"<<ins[0][i]<<" ";
		}
cout<<endl<<endl;
#endif

for(int pl = 0 ; pl < npl; pl++)
	{/* foreach place */
        ins[0][pl+1]=-1;
  	}

#if DEBUG1
  cout<<"\nInitial Marking\n";
  (*rs).show(stdout,true);
#endif
return 0;
}

//Questo metodo va ricontrollato e ottimizzato!!!
void RSRG::MakeNextState(int* f,int* t, int* h,const int& tt,int pl)
{
pl++;
while ((f[pl]==0)&&(t[pl]==0))
	pl++;

if (pl==npl)
	{
	float rate=tabt[tt].mean_t;	
	dd_edge temp(fTranB);
	dd_edge tempReal(fTranR);
	dd_edge tempDiagReal(fTranR);
	
	fTranB->createEdge(from,to, 1, temp);
	fTranR->createEdge(from,to,&rate,1,tempReal);
#if DEBUG
	for(int i=1;i<npl+1;i++)
		{
		cout<<from[0][i]<<" ";
		}
	cout<<endl;
	for(int i=1;i<npl+1;i++)
		{
		cout<<to[0][i]<<" ";
		}
	cout<<endl;
#endif
	rate=rate;
	fTranR->createEdge(from,from,&rate,1,tempDiagReal);
	(*NSFt)+=temp;
	(*NSFtReal)+=tempReal;
	(*DiagReal)+=tempDiagReal;
	//throughput
	(*VectNSFtReal[tt])+=tempDiagReal;
	temp.clear();
	tempReal.clear();
	tempDiagReal.clear();
	//rate=1;
	tempReal.clear();
	}
else
	{
	int b=Max_Token_Bound-1;
	if (f[pl]>0)
		{
		while ((b-f[pl]>=0))
			{
			from[0][pl+1]=b;
			to[0][pl+1]=b-f[pl]+t[pl];
			if (to[0][pl+1]<=Max_Token_Bound-1)
				{
				this->MakeNextState(f,t,h,tt,pl);
				}
			b--;
			}
		}
	else
		{
		if (t[pl]>0)
			{
			while ((b>=0)&&(t[pl]>0))
				{
				from[0][pl+1]=b;
				to[0][pl+1]=b+t[pl];
				if (to[0][pl+1]<=Max_Token_Bound-1)
					{
					this->MakeNextState(f,t,h,tt,pl);
					}
				b--;
				}
			}
		else
			{
			this->MakeNextState(f,t,h,tt,pl);
			}
		}
to[0][pl+1]=from[0][pl+1]=-2;
	}
}




bool RSRG::MakeNextState(int* f,int* t, int* h,const int& tt)
{

dd_edge nsf(fTranB);
dd_edge asf(fTranB);



dd_edge temp(fTranB);
dd_edge Adif(fTranB);
dd_edge tempAdif(fTranB);

//fTranB->createEdge(true,Adif);


int aa=0;


float rate=tabt[tt].mean_t;
int prio=tabt[tt].pri;
int server=tabt[tt].no_serv;
if (server==0)
	server=MAXSERV;
float enable=0.0;


for (int i=0;i<npl+1;i++)
	{
	if ((i>0)&&(f[i-1]==0)&&(t[i-1]==0)&&(h[i-1]==0))
		to[0][i]=from[0][i]=-2;
	else
		to[0][i]=from[0][i]=-1;
	pfrom[0][i]=-1;
	}
fTranB->createEdge(from,to,1,asf);
fTranB->createEdge(pfrom,ins,1,Adif);

for (int pl=0;pl<npl;pl++)
	{
	int b=Max_Token_Bound-1;
//archi inibitori
	if (h[pl]!=0)
		{
		b=h[pl]-1;
		}
//archi inibitori
 	nsf.clear();
	tempAdif.clear();
	aa=0;

	if (b-f[pl]<0) return 0; //transition never  enable!!

	while ((b-f[pl]>=0)&&(f[pl]>0))
		{
		pfrom[0][pl+1]=from[0][pl+1]=b;
		to[0][pl+1]=b-f[pl]+t[pl];
		enable= (int)b/f[pl] > server ? server : (int)b/f[pl];
		enable= rate * enable;
		if (to[0][pl+1]<=Max_Token_Bound-1)
			{
			fTranB->createEdge(from,to, 1, temp);
			nsf+=temp;
			if (prio!=0)
				{
				fTranB->createEdge(pfrom,ins, 1, temp);
				tempAdif+=temp;
				temp.clear();
				}
			aa=1;
			}
		b--;
		}
	pfrom[0][pl+1]=to[0][pl+1]=from[0][pl+1]=-1;		
	if(aa==1)
		{
		asf*=nsf;
		if (prio!=0)
			{
			Adif*=tempAdif;
			}
		}
	nsf.clear();
	tempAdif.clear();

	aa=0;
//archi inibitori
	if (h[pl]!=0)
		{
		b=h[pl]-1;
		}
	else
		b=Max_Token_Bound-1;
//archi inibitori
	enable=rate*server;	
	while ((b>=0)&&(t[pl]>0)&&(f[pl]==0))
		{
		pfrom[0][pl+1]=from[0][pl+1]=b;
		to[0][pl+1]=b+t[pl];
		b--;
		if ((to[0][pl+1]<=Max_Token_Bound-1))
			{
			fTranB->createEdge(from,to, 1, temp);
  			nsf += temp;
			temp.clear();
			aa=1;
			}
		}
	pfrom[0][pl+1]=from[0][pl+1]=to[0][pl+1]=-1;	
	if (aa==1)
		{
		asf*=nsf;
		}
	nsf.clear();

//archi inibitori
	if (h[pl]!=0)
		{
		b=h[pl]-1;
		}
	else
		b=Max_Token_Bound-1;
//archi inibitori

	enable=rate*server;
	aa=0;	
	while (((b>=0)&&(t[pl]==0)&&(f[pl]<=0)&&(h[pl]!=0))||((b>=0)&&(t[pl]==0)&&(b-f[pl]<0)&&(h[pl]!=0)))
		{
		pfrom[0][pl+1]=to[0][pl+1]=from[0][pl+1]=b;
		b--;
		fTranB->createEdge(from,to, 1, temp);
  		nsf += temp;
		temp.clear();
		if (prio!=0)
			{
			fTranB->createEdge(pfrom,ins, 1, temp);
			tempAdif+=temp;
			temp.clear();
			}
		aa=1;
		}
	pfrom[0][pl+1]=from[0][pl+1]=to[0][pl+1]=-1;
	if (aa==1)
		{
		asf*=nsf;
		if(prio!=0)
			{
			Adif*=tempAdif;
			}
		}

	aa=0;
	 nsf.clear();
	
	} 

if (prio!=0)
	{
	if (prioNSFt[prio]==NULL)
		{
		prioNSFt[prio]=new dd_edge(fTranB);
		defNSFt[prio]=new dd_edge(fTranB);
		}
	(*prioNSFt[prio])+=asf;
	(*defNSFt[prio])+=Adif;
	//(*NSFi)+=asf;
	}
else
	{
	(*NSFt)+=asf;
	}




#if DEBUG
	cout<<"size :"<<(*DiagReal).getCardinality()<<endl;
#endif
return 0;
}


bool RSRG::genRSTimed(){
//Here we assume to work with SPN (without immediate transition)
//un_marking encodes only the initial marking.
clock_t startGlobal,endGlobal;
startGlobal=clock();

//For prio
for (int i=1;i<MAXPRIO;i++)
	{
	if (prioNSFt[i]!=NULL)
		{
		try
		{
		(*NSFt)-=(*defNSFt[i]);
		}
		catch(...)	
			{
			cerr<<"Error encoding firing rules"<<endl;
			return false;
			}
		(*NSFt)+=(*prioNSFt[i]);
		}
	}
//


//UPDATE 23-12-11
try
	{
	apply(REACHABLE_STATES_DFS,*rs, *NSFt, *rs);
	}
catch(...)
	{
	cerr<<"Error REACHABLE_STATES_DFS "<<endl;
	return false;
	}

endGlobal=clock();
cout<<"\tTime RS: "<<((double)(endGlobal-startGlobal))/CLOCKS_PER_SEC<<endl;
startGlobal=clock();
endGlobal=clock();
cout<<"\tTime Card: "<<((double)(endGlobal-startGlobal))/CLOCKS_PER_SEC<<endl;


// dd_edge tmpRS(fRS);
// 
// try
// 	{
// 	apply(PRE_IMAGE,*rs, *NSFt, tmpRS);
// 	}
// catch(...)
// 	{
// 	cerr<<"Error PRE_IMAGE "<<endl;
// 	return false;
// 	}
// cout<<"PRE_IMAGE_SIZE"<<tmpRS.getCardinality()<<endl;
// cout<<"RS"<<rs->getCardinality()<<endl;
// 
// dd_edge::iterator i = rs->begin();
// 		int val,z=0;
// 		while(i!=0)
// 			{
// 			cout<<"M"<<z<<"\n\t"; 
// 			for(int j=1; j <= npl; j++)
// 				{
// 				val = *(i.getAssignments() + j );
// 				if ((val!=0))
// 					cout<<getPL(j-1)<<"("<<val<<")";
// 				}//per ogni posto
// 			cout<<endl;
// 			++i;
// 			++z;	
// 			}//per 
// cout<<"----------------------------"<<endl;
// cout<<"PRE_IMAGE MARKINGS"<<endl;
//  i = tmpRS.begin();
// 		z=0;
// 		while(i!=0)
// 			{
// 			cout<<"M"<<z<<"\n\t"; 
// 			for(int j=1; j <= npl; j++)
// 				{
// 				val = *(i.getAssignments() + j );
// 				if ((val!=0))
// 					cout<<getPL(j-1)<<"("<<val<<")";
// 				}//per ogni posto
// 			cout<<endl;
// 			++i;
// 			++z;	
// 			}//pe
// 
// 
// cout<<"----------------------------"<<endl;
//  NSFt->show(stdout,2);
// 
// 
// try
// 	{
// 	apply(INTERSECTION,*rs,tmpRS , tmpRS);
// 	}
// 		
// catch(...)
// 	{
// 	cerr<<"Error Intersection"<<endl;
// 	return false;
// 	}
// cout<<"INTERSECTION"<<(long long)tmpRS.getCardinality()<<endl;
return 0;
}



bool RSRG::genRSAll()
{

double first,second;

dd_edge reached(fRS);
dd_edge sourceXT(fRS);
dd_edge source(fRS);
dd_edge tmp(fRS);



sourceXT+=*rs;
do
	{
	//UPDATE 23-12-11
	try
		{
		apply(POST_IMAGE,sourceXT, *NSFt, reached);
		}
	catch(...)
		{
		cerr<<"Error  POST_IMAGE"<<endl;
		return false;		
		}
	sourceXT.clear();
	sourceXT+=reached;
	second=rs->getCardinality();
	(*rs)+=reached;
	do
		{
		//UPDATE 23-12-11
		try
			{
			apply(POST_IMAGE,reached, *NSFi,tmp);
			}
		catch(...)
			{
			cerr<<"Error POST_IMAGE "<<endl;
			return -1;
			}
		first=rs->getCardinality();
		sourceXT+=tmp-(*rs);
		(*rs)+=tmp;
		//UPDATE 23-12-11
		/*if (cm->apply(compute_manager::PRE_IMAGE,tmp, *NSFi,source)!=0)
			{
			cerr<<"Error PRE_IMAGE"<<endl;
			return -1;
			}*/
		//UPDATE 23-12-11
		try	
			{
			apply(PRE_IMAGE,tmp, *NSFi,source);		
			}
		catch(...)
			{
			cerr<<"Error POST_IMAGE "<<endl;
			return false;
			}
		sourceXT-=source;
		source.clear();
		reached.clear();
		reached+=tmp;
		tmp.clear();
		}
	while ((rs->getCardinality()-first)>_DIFFMIN(double));
	reached.clear();
	}
while((rs->getCardinality()-second)>_DIFFMIN(double));
return 0;
}



bool RSRG::IndexRS()
{
fEV= d->createForest(false, forest::INTEGER, forest::EVPLUS);
indexrs=new dd_edge(fEV);
indexrs->clear();

//UPDATE 23-12-1
try
	{
	apply(CONVERT_TO_INDEX_SET, *rs, *indexrs);
	}
catch(...)
	{
	cerr<<"Error  CONVERT_TO_INDEX_SET"<<endl;
	return false;
	}
return 0;
}


bool RSRG::JacobiSolver()
{

int jj=0;



#if DEBUG
for (int i=0;i<npl+1;i++)
		{
		cout<<"["<<i<<"]"<<v[0][i]<<" ";
		}
cout<<endl<<endl;
#endif

double cardinality = this->getSizeRS();
if (cardinality<1)
	{
	return 0;
	}

double* q1 =(double *) malloc((int)cardinality * sizeof(double));
double* q2 =(double *) malloc((int)cardinality * sizeof(double));
double* qold =(double *) malloc((int)cardinality * sizeof(double));
double* h =(double *) malloc((int)cardinality * sizeof(double));
for (jj=0;jj<(int)cardinality;jj++)
	{
	q1[jj]=1/cardinality;
	q2[jj]=0.0;
	qold[jj]=1.0;
	h[jj]=0.0;
	}



//UPDATE 23-12-1
 numerical_operation* VM = VECT_MATR_MULT->buildOperation(*indexrs, *DiagReal , *indexrs);
try
	{
	VM->compute(h, qold);
	}
catch(...)
	{
	cerr<<"Error  generation diagonal"<<endl;
	return false;
	}
numerical_operation* VM1 = VECT_MATR_MULT->buildOperation(*indexrs,*NSFtReal,*indexrs);	

int ss=0;
double sum=0.0,diff=0.0,norm=0.0;
bool precision=false;
while ((ss<_iter)&&(!precision))
	{
	//UPDATE 23-12-1
	try
		{
		VM1->compute(q2,q1);
		}
	catch(...)
		{
		cerr<<"Error  vectorMatrixMultiply"<<endl;
		return false;
		}

	if (ss%1000==0)
		cout<<"\tIteration: "<<ss<<" error: "<<diff<<"\n";
#if DEBUG
	cout<<"Iteration: "<<ss<<" error: "<<diff<<"\n\t";
#endif
sum=diff=norm=0.0;
	for (int jj=0;jj<(int)cardinality;jj++)
		{
		q2[jj]=(q2[jj])/h[jj]+q1[jj];
		sum+=q2[jj];
		}
	for (int jj=0;jj<(int)cardinality;jj++)
		{
		q1[jj]=q2[jj]/sum;
		diff+=pow(q1[jj],2)-pow(qold[jj],2);
		norm+=pow(qold[jj],2);
		qold[jj]=q1[jj];
		q2[jj]=0.0;
		}
	
	diff=(sqrt(fabs(diff)))/sqrt(norm);
	if (diff<_prec)
		precision=true;
#if DEBUG1
	cout<<"error: "<<diff<<endl;
#endif
	ss++;
}
if (diff>_prec)
	{
	cerr<<"\nError: Precision  was not reached!!!"<<endl;
	return -1;
	}
else
	{
#if DEBUG1
	for (int jj=0;jj<(int)cardinality;jj++)
		{
		cout<<q1[jj]<<" ";
		}
	cout<<endl;
#endif
	std::string file=netname+std::string(".prob");
	ofstream out(file.c_str(),ofstream::out);
	if(!out) 
		{
		cerr << "\n*****Error opening output stream .prob *****" << endl;
		return -1;
		}
	out<<setprecision (IOPRECISION);
	for (int jj=0;jj<(int)cardinality;jj++)
		{
		out<<q1[jj]<<endl;
		}
	out.close();
	file=netname+std::string(".sta");
	out.open(file.c_str(),ofstream::out);
	if(!out) 
		{
		cerr << "\n*****Error opening output stream .sta *****" << endl;
		return -1;
		}
	out<<setprecision (IOPRECISION);
	for (int tt=0;tt<ntr;tt++)
		{
		//UPDATE 23-12-1
		/*if (cm->vectorMatrixMultiply(q2, *indexrs,  q1, *indexrs,*(VectNSFtReal[tt]))!=0)
			{
			cerr<<"Error  vectorMatrixMultiply"<<endl;
			return -1;
			}*/
		//UPDATE 23-12-1
		numerical_operation* VMT = VECT_MATR_MULT->buildOperation(*indexrs, *(VectNSFtReal[tt]), *indexrs);
		try
			{	
			VMT->compute(q2, q1);
			}
		catch(...)
			{
			cerr<<"Error  vectorMatrixMultiply"<<endl;
			return false;
			}
		sum=0.0;
		for (int jj=0;jj<(int)cardinality;jj++)
			{
			sum+=q2[jj];
			q2[jj]=0.0;
			}
		out<<"Thru_"<<tabt[tt].trans_name<<" = "<<sum<<endl;
		}
	out.close();
	}
//end implementazione esplicita

//free memory
free(q1);
free(q2);
free(qold);
free(h);

return 0;
}


RSRGAuto::RSRGAuto(const int& npl,std::string netname){
  
this->cardinality=0.0;  
this->npl=npl;
this->netname=netname;

//Create DD ComputeManager
//cm = MEDDLY_getComputeManager();

//Create DD domain
d = createDomain();
int* bounds = (int *) malloc((npl+1) * sizeof(int*));
for (int i=0;i<npl+1;i++)
  	{
    	bounds[i]=Max_Token_Bound;
  	}
bounds[npl+1]=AState;
d->createVariablesBottomUp(bounds, npl+1);

// Create DD forests
fRS = d->createForest(false, forest::BOOLEAN,forest::MULTI_TERMINAL);	
fRS->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fRS->setNodeDeletion(forest::OPTIMISTIC_DELETION);

fTranB =d->createForest(true, forest::BOOLEAN, forest::MULTI_TERMINAL);
fTranB->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fTranB->setNodeDeletion(forest::OPTIMISTIC_DELETION);

fTranR=d->createForest(true, forest::REAL, forest::MULTI_TERMINAL);
fTranR->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fTranR->setNodeDeletion(forest::OPTIMISTIC_DELETION);

//it is initialized only when it needs
fEV=NULL;


//Create DD edge

rs = new dd_edge(fRS);
initMark = new dd_edge(fRS);
indexrs= NULL;
NSFt = new dd_edge(fTranB);
NSFi = new dd_edge(fTranB);
NSFtReal = new dd_edge(fTranR);
DiagReal = new dd_edge(fTranR);
VectNSFtReal = (dd_edge **) malloc((ntr)* sizeof(dd_edge*));
for (int i=0; i<ntr;i++)
	{
	VectNSFtReal[i]= new dd_edge(fTranR);
	}

//Create vector
to= (int **) malloc((1)* sizeof(int*));
to[0]=(int *) malloc((npl+2) * sizeof(int));
from= (int **) malloc((1)* sizeof(int*));
from[0] =(int *) malloc((npl+2) * sizeof(int));
ins=(int **) malloc((1)* sizeof(int*));
ins[0]=(int *) malloc((npl+2) * sizeof(int));

for (int i=0;i<npl+2;i++)
	{
	to[0][i]=from[0][i]=ins[0][i]=-2;
	}


//Create mapping  between Place name and interger
for (int i=0;i<npl;i++)
	{
	S2Ipl[std::string(tabp[i].place_name)]=i;
	}

for (int i=0;i<ntr;i++)
	{
	S2Itr[std::string(tabt[i].trans_name)]=i;
	}

fRG=d->createForest(false, forest::REAL, forest::MULTI_TERMINAL);
fRG->setNodeStorage(forest::FULL_OR_SPARSE_STORAGE);
fRG->setNodeDeletion(forest::OPTIMISTIC_DELETION);



//Free memory
free(bounds);
}

bool RSRGAuto::MakeNextState(int* f,int* t, int* h,const int& tt,int AA,map <int, map <int, class ATRANSITION> > & automa)
{

dd_edge nsf(fTranB);
dd_edge nsfminus(fTranB);//used to remove transition

dd_edge asf(fTranB);
dd_edge asfminus(fTranB);//used to remove transition

dd_edge nsfReal(fTranR);
dd_edge nsfRealminus(fTranR);//used to remove transition

dd_edge asfReal(fTranR);
dd_edge asfRealminus(fTranR);//used to remove transition



dd_edge temp(fTranB);

dd_edge tempReal(fTranR);



int aa=0;

float rate=tabt[tt].mean_t;
int prio=tabt[tt].pri;

int server=tabt[tt].no_serv;
if (server==0)
	server=MAXSERV;
float enable=0.0;

//Automaton state
to[0][npl+1]=automa[AA][tt].getD();
from[0][npl+1]=AA;
//Automaton state

for (int i=0;i<npl+1;i++)
	{
	if ((i>0)&&(f[i-1]==0)&&(t[i-1]==0)&&(h[i-1]==0)&&(!automa[AA][tt].findPre(i-1))&&(!automa[AA][tt].findPost(i-1)))
		to[0][i]=from[0][i]=-2;
	else
		to[0][i]=from[0][i]=-1;
	}

int Max,Min,MinTemp,initb,b;

for (int pl=0;pl<npl;pl++)
	{
	initb=Max_Token_Bound-1;
	Max=Min=MinTemp=-1;	
//archi inibitori
	if (h[pl]!=0)
		{
		initb=h[pl]-1;
		}
//archi inibitori
//Pre conditions
	if (automa[AA][tt].getBoundPre(pl,Max,Min))
		{
		initb = initb > Max ? Max : initb;
		}
//Post conditions
	
	if (automa[AA][tt].getBoundPost(pl,Max,MinTemp))
		{
		initb = initb > (Max-t[pl])? (Max-t[pl]) : initb;
		Min = Min < (MinTemp -t[pl]) ? (MinTemp-t[pl]) : Min;
		}
	
 	nsf.clear();
	nsfminus.clear();
	nsfReal.clear();
	nsfRealminus.clear();
	aa=0;
	
	b=initb;

	if ((b-f[pl]<0)|| (b<Min)) return 0; //transition never  enable!!
	
	while ((b-f[pl]>=0)&&(f[pl]>0)&&(b>=Min))
		{
		from[0][pl+1]=b;
		to[0][pl+1]=b-f[pl]+t[pl];
		enable= (int)b/f[pl] > server ? server : (int)b/f[pl];
		enable= ((tt+1)*INCTRAN)+(rate * enable);
		//enable= rate * enable;
		if (to[0][pl+1]<=Max_Token_Bound-1)
			{
			fTranB->createEdge(from,to, 1, temp);
			nsf+=temp;
			temp.clear();
			fTranR->createEdge(from,to,&enable,1,tempReal); //rate solo la prima volta
			nsfReal+=tempReal;
			tempReal.clear();
			//to remove
			to[0][npl+1]=from[0][npl+1]=AA;
			fTranB->createEdge(from,to, 1, temp);
			nsfminus+=temp;
			temp.clear();
			fTranR->createEdge(from,to,&enable,1,tempReal);
	 		nsfRealminus+=tempReal;
			tempReal.clear();
			to[0][npl+1]=automa[AA][tt].getD();
			from[0][npl+1]=AA;
			//to remove
			aa=1;
			}
		b--;
		to[0][pl+1]=from[0][pl+1]=-1;
		}		
	if(aa==1)
		{
		if (asf.getNode()!=0)
			{
			asf*=nsf;
			asfminus*=nsfminus;
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				apply(MINIMUM, asfRealminus,nsfRealminus, asfRealminus);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
			}
		else
			{
			asf+=nsf;
			asfminus+=nsfminus;
			asfReal+=nsfReal;
			asfRealminus+=nsfRealminus;
			}
		nsf.clear();
		nsfminus.clear();
		nsfReal.clear();
		nsfRealminus.clear();
		}
	aa=0;
	b=initb;
	enable=((tt+1)*INCTRAN)+server*rate;
	//enable=server*rate;
	while ((b>=0)&&(t[pl]>0)&&(f[pl]==0)&&(b>=Min))
		{
		from[0][pl+1]=b;
		to[0][pl+1]=b+t[pl];
		b--;
		if ((to[0][pl+1]<=Max_Token_Bound-1))
			{
			fTranB->createEdge(from,to, 1, temp);
  			nsf += temp;
			temp.clear();
			fTranR->createEdge(from,to,&enable,1, tempReal);
  			nsfReal += tempReal;
			tempReal.clear();

			//to remove
			to[0][npl+1]=from[0][npl+1]=AA;
			fTranB->createEdge(from,to, 1, temp);
			nsfminus+=temp;
			temp.clear();
			fTranR->createEdge(from,to,&enable,1,tempReal);
	 		nsfRealminus+=tempReal;
			tempReal.clear();
			to[0][npl+1]=automa[AA][tt].getD();
			from[0][npl+1]=AA;
			//to remove
			aa=1;
			}
		from[0][pl+1]=to[0][pl+1]=-1;
		}
	if (aa==1)
		{
		if (asf.getNode()!=0)
			{
			asf*=nsf;
			asfminus*=nsfminus;
			//UPDATE 23-12-11
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				apply(MINIMUM, asfRealminus,nsfRealminus, asfRealminus);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
			//UPDATE 23-12-11
			}
		else
			{
			asf+=nsf;
			asfminus+=nsfminus;
			asfReal+=nsfReal;
			asfRealminus+=nsfRealminus;
			}
		}
	aa=0;
	b=initb;

	while (((b>=0)&&(t[pl]==0)&&(f[pl]<=0)&&(h[pl]!=0)&&(b>=Min))||((b>=0)&&(t[pl]==0)&&(b-f[pl]<0)&&(h[pl]!=0)&&(b>=Min)))
		{
		to[0][pl+1]=from[0][pl+1]=b;
		b--;
		fTranB->createEdge(from,to, 1, temp);
  		nsf += temp;
		temp.clear();
		fTranR->createEdge(from,to,&enable,1, tempReal);
  		nsfReal += tempReal;
		tempReal.clear();
		aa=1;
		
		//to remove
		to[0][npl+1]=from[0][npl+1]=AA;
		fTranB->createEdge(from,to, 1, temp);
		nsfminus+=temp;
		temp.clear();
		fTranR->createEdge(from,to,&enable,1,tempReal);
	 	nsfRealminus+=tempReal;
		tempReal.clear();
		to[0][npl+1]=automa[AA][tt].getD();
		from[0][npl+1]=AA;
		//to remove
		from[0][pl+1]=to[0][pl+1]=-1;
		}

	if (aa==1)
		{
		if (asf.getNode()!=0)
			{
			asf*=nsf;
			asfminus*=nsfminus;
			//UPDATE 23-12-11
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				apply(MINIMUM, asfRealminus,nsfRealminus, asfRealminus);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
			
			}
		else
			{
			asf+=nsf;
			asfminus+=nsfminus;
			asfReal+=nsfReal;
			asfRealminus+=nsfRealminus;
			//aDiagReal+=tempDiagReal;
			}
		}

	aa=0;
	b=initb;
		
	while (((automa[AA][tt].findPre(pl))||(automa[AA][tt].findPost(pl)))&&(((b>=0)&&(t[pl]==0)&&(f[pl]<=0)&&(h[pl]==0)&&(b>=Min))||((b>=0)&&(t[pl]==0)&&(b-f[pl]<0)&&(h[pl]==0)&&(b>=Min))))
		{
		to[0][pl+1]=from[0][pl+1]=b;
		b--;
		fTranB->createEdge(from,to, 1, temp);
  		nsf += temp;
		temp.clear();
		fTranR->createEdge(from,to,&enable,1, tempReal);
  		nsfReal += tempReal;
		tempReal.clear();
		aa=1;
	
		//to remove
		to[0][npl+1]=from[0][npl+1]=AA;
		fTranB->createEdge(from,to, 1, temp);
		nsfminus+=temp;
		temp.clear();
		fTranR->createEdge(from,to,&enable,1,tempReal);
	 	nsfRealminus+=tempReal;
		tempReal.clear();
		to[0][npl+1]=automa[AA][tt].getD();
		from[0][npl+1]=AA;
		//to remove
		from[0][pl+1]=to[0][pl+1]=-1;
		}

	if (aa==1)
		{
		if (asf.getNode()!=0)
			{
			asf*=nsf;
			asfminus*=nsfminus;
			//UPDATE 23-12-11
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				apply(MINIMUM, asfRealminus,nsfRealminus, asfRealminus);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
			}
		else
			{
			asf+=nsf;
			asfminus+=nsfminus;
			asfReal+=nsfReal;
			asfRealminus+=nsfRealminus;
			}
		}
	
	} 

if (prio!=0)
	{
	(*NSFi)+=asf;
	(*NSFi)-=asfminus;
	}
else
	{
	(*NSFt)+=asf;
	(*NSFt)-=asfminus;
	(*NSFtReal)+=asfReal;
	(*NSFtReal)-=asfRealminus;
//controllare--> lento se abilitato!!!!
	//(*DiagReal)+=aDiagReal;
	//(*VectNSFtReal[tt])+=aDiagReal;
	}
asf.clear();
asfminus.clear();
asfReal.clear();
asfRealminus.clear();



#if DEBUG
	cout<<"size :"<<(*DiagReal).getCardinality()<<endl;
#endif
return 0;
}



bool RSRGAuto::MakeNextState(int* f,int* t, int* h,const int& tt,int AA)
{

dd_edge nsf(fTranB);
dd_edge asf(fTranB);
dd_edge nsfReal(fTranR);
dd_edge asfReal(fTranR);

dd_edge temp(fTranB);
dd_edge tempReal(fTranR);



int aa=0;

float rate=tabt[tt].mean_t;
int prio=tabt[tt].pri;

int server=tabt[tt].no_serv;
if (server==0)
	server=MAXSERV;
float enable=0.0;

//Automaton state
to[0][npl+1]=from[0][npl+1]=AA;
//Automaton state


for (int i=0;i<npl+1;i++)
	{
	if ((i>0)&&(f[i-1]==0)&&(t[i-1]==0)&&(h[i-1]==0))
		to[0][i]=from[0][i]=-2;
	else
		to[0][i]=from[0][i]=-1;
	}


for (int pl=0;pl<npl;pl++)
	{
	int b=Max_Token_Bound-1;
//archi inibitori
	if (h[pl]!=0)
		{
		b=h[pl]-1;
		}
//archi inibitori
 	nsf.clear();
	nsfReal.clear();

	aa=0;
	
	if (b-f[pl]<0) return 0; //transition never  enable!!
	
	while ((b-f[pl]>=0)&&(f[pl]>0))
		{
		from[0][pl+1]=b;
		to[0][pl+1]=b-f[pl]+t[pl];
		enable= (int)b/f[pl] > server ? server : (int)b/f[pl];
		enable= ((tt+1)*INCTRAN)+(rate * enable);
		//enable=(rate * enable);
		if (to[0][pl+1]<=Max_Token_Bound-1)
			{
			fTranB->createEdge(from,to, 1, temp);
			nsf+=temp;
			temp.clear();
			fTranR->createEdge(from,to,&enable,1,tempReal); //rate solo la prima volta
			nsfReal+=tempReal;
			tempReal.clear();
			aa=1;
			}
		b--;
		to[0][pl+1]=from[0][pl+1]=-1;
		}		
	if(aa==1)
		{
		if (asf.getNode()!=0)
		{
			asf*=nsf;
			//UPDATE 23-12-11
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
		}
		else
		{
			asf+=nsf;
			asfReal+=nsfReal;
		}
		nsf.clear();
		nsfReal.clear();
	
		
		}
	aa=0;
//archi inibitori
	if (h[pl]!=0)
		{
		b=h[pl]-1;
		}
	else
		b=Max_Token_Bound-1;
//archi inibitori
	enable=((tt+1)*INCTRAN)+rate * server;
	//enable=enable= rate * server;
	while ((b>=0)&&(t[pl]>0)&&(f[pl]==0))
		{
		from[0][pl+1]=b;
		to[0][pl+1]=b+t[pl];
		b--;
		if ((to[0][pl+1]<=Max_Token_Bound-1))
			{
			fTranB->createEdge(from,to, 1, temp);
  			nsf += temp;
			temp.clear();
			fTranR->createEdge(from,to,&enable,1, tempReal);
  			nsfReal += tempReal;
			tempReal.clear();
			aa=1;
			}
		from[0][pl+1]=to[0][pl+1]=-1;
		}
	if (aa==1)
		{
		if (asf.getNode()!=0)
			{
			asf*=nsf;
			//UPDATE 23-12-11
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
			}
		else
			{
			asf+=nsf;
			asfReal+=nsfReal;
			};
		}
	aa=0;
//archi inibitori
	if (h[pl]!=0)
		{
		b=h[pl]-1;
		}
	else
		b=Max_Token_Bound-1;
//archi inibitori

	//enable=enable= rate * server;
	while (((b>=0)&&(t[pl]==0)&&(f[pl]<=0)&&(h[pl]!=0))||((b>=0)&&(t[pl]==0)&&(b-f[pl]<0)&&(h[pl]!=0)))
		{
		to[0][pl+1]=from[0][pl+1]=b;
		b--;
		fTranB->createEdge(from,to, 1, temp);
  		nsf += temp;
		temp.clear();
		fTranR->createEdge(from,to,&enable,1, tempReal);
  		nsfReal += tempReal;
		tempReal.clear();
		aa=1;
		from[0][pl+1]=to[0][pl+1]=-1;
		}
	if (aa==1)
		{
		if (asf.getNode()!=0)
			{
			asf*=nsf;
			//UPDATE 23-12-11
			try
				{
				apply(MINIMUM, asfReal,nsfReal, asfReal);
				}
			catch(...)
				{
				cerr<<"Error MIN"<<endl;
				return false;
				}
			}
		else
			{
			asf+=nsf;
			asfReal+=nsfReal;
			}
		
		}	
	} 


if (prio!=0)
	{
	(*NSFi)+=asf;
	}
else
	{
	(*NSFt)+=asf;
	(*NSFtReal)+=asfReal;
	}
asf.clear();
asfReal.clear();

#if DEBUG
	cout<<"size :"<<(*DiagReal).getCardinality()<<endl;
#endif
return 0;
}


bool RSRGAuto::init_RS(const Net_Mark_p& net_mark){

ins[0][0]=0;
for(int pl = 0 ; pl < npl; pl++)
	{/* foreach place */
        ins[0][pl+1]=net_mark[pl].total;
  	}/* foreach place */
ins[0][npl+1]=0;
fRS->createEdge(ins, 1, *rs);
fRS->createEdge(ins, 1, *initMark);
#if DEBUG
for (int i=0;i<npl+1;i++)
		{
		cout<<"["<<i<<"]"<<ins[0][i]<<" ";
		}
cout<<endl<<endl;
#endif



#if DEBUG1
  cout<<"\nInitial Marking\n";
  (*rs).show(stdout,true);
#endif
return 0;
}




bool RSRGAuto::ComputingRG(const bool& output, FILE * wngr,FILE* f_outState,const int& Top,const int& Bot,set <int>& InitSet, bool outState)
{


dd_edge::iterator i = this->rs->begin();
const int* psource;
const int* plmark;




dd_edge src(fRG);

float num=1.0,val=0.0;
int idm=0;
//char c;
//int card;


if (output)
	cout<<"================= RG X A Output ================"<<endl;


fprintf(wngr,"1\n");
//fwrite(&idm,sizeof(int), 1,wngr);

while(i!=0)
	{
	psource=i.getAssignments();
	fRG->createEdge(&psource,&num, 1, src);
	//get id marking
	fEV->evaluate((*indexrs),psource,idm);
	//get id marking
	if (outState)
		{
		if (psource[npl+1]==Top)
			{
			//c='E';
			//fwrite(&c,sizeof(char), 1,f_outState);
			//fwrite(&idm,sizeof(int), 1,f_outState);
			fprintf(f_outState,"E:%d\n",idm);
			}
		if (psource[npl+1]==Bot)
			{
			//c='F';
			fprintf(f_outState,"F:%d\n",idm);
			}
		if (InitSet.find(psource[npl+1])!=InitSet.end())
			{
			//c='S';
			fprintf(f_outState,"S:%d\n",idm);
			}

		}
	if (output)
		cout<<"Source: "<<idm<<endl;
	//UPDATE 23-12-11
	try
		{
		apply(POST_IMAGE, src, *NSFtReal, src);
		}
	catch(...)
		{
		cerr<<"Error REACHABLE_STATES_BFS "<<endl;
		return false;
		}
	fprintf(wngr,"%ld\n",(long int)src.getCardinality());
	dd_edge::iterator j = src.begin();//
	while(j!=0)
		{
		plmark=j.getAssignments();
		fEV->evaluate((*indexrs),plmark,idm);
		fRG->evaluate(src,plmark,val);
		checkRate(val,psource);
		if (output)
			cout<<"\tDest: "<<idm<<" Rate: "<<val<<endl;
		fprintf(wngr,"\t%d %f\n",idm,val);
		++j;
		}
	++i;
	} 
fprintf(wngr,"%ld\n",(long int)rs->getCardinality());
if (output)
	cout<<"================================================\n\n"<<endl;
return true;
}


void RSRGAuto::checkRate(float& val,const int* plmark)
{
//cout<<"VAL:"<<val<<endl;
int idT = ((int)val/INCTRAN)-1;
#if DEBUG
cout<<val<<" "<<this->getTR(idT)<<" "<<idT<<endl;
#endif
val=val-(float)((idT+1)*INCTRAN);
//For marking dependent 
#if DEBUG
for (int i=0;i<npl+1;i++)
	{
	cout<<plmark[i];
	}
	cout<<endl;
#endif

/*
//cout<<idT<<" "<<this->getTR(idT)<<endl;
//T23t2 mu23*(#p3/(#p3+#P32))
if (idT == this->getTR("T23t2"))
	{
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("p3")+1]/((float)plmark[this->getPL("p3")+1]+(float)plmark[this->getPL("P32")+1]));
	//cout<<"\t"<<val<<" "<<plmark[this->getPL("P32")+1]<<" "<<plmark[this->getPL("p3")+1]<<endl;
	}
else
//T23t28 mu23*(#P32/(#p3+#P32))
if (idT == this->getTR("T23t28"))
	{
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("P32")+1]/((float)plmark[this->getPL("p3")+1]+(float)plmark[this->getPL("P32")+1]));
	//cout<<val<<" "<<plmark[this->getPL("P32")+1]<<" "<<plmark[this->getPL("p3")+1]<<endl;
	}
else
//T23t28t26 mu23*(#P32/(#p3+#P32))
if (idT == this->getTR("T23t28t26"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("P32")+1]/((float)plmark[this->getPL("p3")+1]+(float)plmark[this->getPL("P32")+1]));
else
//T23t2t26 mu23*(#p3/(#p3+#P32))
if (idT == this->getTR("T23t2t26"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("p3")+1]/((float)plmark[this->getPL("p3")+1]+(float)plmark[this->getPL("P32")+1]));
else
//T22t26 mu22*(#P29/(#p5+#P29))
if (idT == this->getTR("T22t26"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("P29")+1]/((float)plmark[this->getPL("p5")+1]+(float)plmark[this->getPL("P29")+1]));
else
//T22t3 mu22*(#p5/(#p5+#P29))
if (idT == this->getTR("T22t3"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("p5")+1]/((float)plmark[this->getPL("p5")+1]+(float)plmark[this->getPL("P29")+1]));
else
//T22t26t25  mu22*(#P29/(#p5+#P29))
if (idT == this->getTR("T22t26t25"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("P29")+1]/((float)plmark[this->getPL("p5")+1]+(float)plmark[this->getPL("P29")+1]));
else
//T22t3t25  mu22*(#p5/(#p5+#P29))
if (idT == this->getTR("T22t3t25"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("p5")+1]/((float)plmark[this->getPL("p5")+1]+(float)plmark[this->getPL("P29")+1]));
else
//T24t27 mu24*(#P30/(#p1+#P30))
if (idT == this->getTR("T24t27"))
	val=tabt[idT].mean_t * ((float)plmark[this->getPL("P30")+1]/((float)plmark[this->getPL("p1")+1]+(float)plmark[this->getPL("P30")+1]));
else
//T24t1  mu24*(#p1/(#p1+#P30))
if (idT == this->getTR("T24t1"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p1")+1]/((float)plmark[this->getPL("p1")+1]+(float)plmark[this->getPL("P30")+1]));
else
//T24t1t28  mu24*(#p1/(#p1+#P30))
if (idT == this->getTR("T24t1t28"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p1")+1]/((float)plmark[this->getPL("p1")+1]+(float)plmark[this->getPL("P30")+1]));
else
//T24t27t28 mu24*(#P30/(#p1+#P30))
if (idT == this->getTR("T24t27t28"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("P30")+1]/((float)plmark[this->getPL("p1")+1]+(float)plmark[this->getPL("P30")+1]));
else
//T21t4  mu21*(#p7/(#p7+#P28))
if (idT == this->getTR("T21t4"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p7")+1]/((float)plmark[this->getPL("p7")+1]+(float)plmark[this->getPL("P28")+1]));
else
//T21t25  mu21*(#P28/(#p7+#P28))
if (idT == this->getTR("T21t25"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("P28")+1]/((float)plmark[this->getPL("p7")+1]+(float)plmark[this->getPL("P28")+1]));
//T10t5  muPaperW*#p21 
if (idT == this->getTR("T10t5"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p21")+1]);
//T10t6 muPaperW*#p21 
if (idT == this->getTR("T10t6"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p21")+1]);
// T9t6  muTravel*#p19
if (idT == this->getTR("T9t6"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p19")+1]);
//T9t5 muTravel*#p19
if (idT == this->getTR("T9t5"))
	val=tabt[idT].mean_t* ((float)plmark[this->getPL("p19")+1]);
*/
}


}



