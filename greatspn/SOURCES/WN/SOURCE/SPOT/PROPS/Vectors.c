#include <stdio.h>
#include "../../../INCLUDE/SCONSSPOT.h"


inline TYPE_P AllocateBV() { return (TYPE_P)calloc(MAX_IND,SIZE_TYPE); }
inline
void VideC(TYPE_P CONJ )
{
  memset(CONJ,0,sizeof(TYPE)*MAX_IND);            
}

inline 
 
TYPE Val (TYPE_P CONJ, TYPE e)
{ 
  TYPE mask=0;  
  mask = (1<<POS(e));
 
  return (CONJ[IND(e)] & mask);   
}
inline 
void Add (TYPE_P CONJ, TYPE e)
{
     CONJ[IND(e)] |= (1<<POS(e));
}
inline
void Minus(TYPE_P CONJ, TYPE e)
{
  TYPE masq=0,i ;

  for (i=1; i<=BIT_TYPE ; i++) 
    if( Val(CONJ,i)!=0 && POS(i)!=POS(e) )
      masq |=(1<<POS(i));
     
  CONJ[IND(e)] &= masq;
}
inline
TYPE COMP(TYPE_P CONJ1, TYPE_P CONJ2)
{
  
  if(memcmp(CONJ1,CONJ2,MAX_IND)==0) return true;
  else return false;
}
inline 
TYPE_P INTER(TYPE_P CONJ1, TYPE_P CONJ2)
{
  TYPE i,flag=false;
  TYPE_P Res=AllocateBV();
  VideC(Res);

  for(i=0;i<MAX_IND;i++)
    if((Res[i]=CONJ1[i] & CONJ2[i])!=0)
      flag=true;

  if (!flag)
     {
       free(Res);
       Res=NULL; 
     }
  return Res;
}
inline 
int INCLUDE (TYPE_P CONJ1, TYPE_P CONJ2)
{
  TYPE i;

  for(i=0;i<MAX_IND;i++)
    if((CONJ1[i] & (~CONJ2[i]))!=0)
      return false;

  return true;
}
inline 
int INTER_Truth(TYPE_P CONJ1, TYPE_P CONJ2)
{
  TYPE i;
  TYPE Res=0;
 
  for(i=0;i<MAX_IND;i++)
    { 
      Res=CONJ1[i] & CONJ2[i];
      if(Res!=0) return true;
    }
  return false;
}
inline 
TYPE_P XOR(TYPE_P CONJ1, TYPE_P CONJ2)
{
  TYPE i,flag=false;
  TYPE_P Res=AllocateBV();

  VideC(Res);

  for(i=0;i<MAX_IND;i++)
    Res[i]=CONJ1[i] ^ CONJ2[i] ;
     
  return Res;
}
