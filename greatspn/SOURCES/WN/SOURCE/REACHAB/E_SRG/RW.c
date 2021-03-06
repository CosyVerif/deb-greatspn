#include <stdio.h>
#include "../../../INCLUDE/const.h"
#include "../../../INCLUDE/struct.h"
#include "../../../INCLUDE/var_ext.h"
#include "../../../INCLUDE/macros.h"


extern Canonic_p sfl_h;

TO_MERGEP* TO_MERGE(int ncl,struct COLORS* tabc)
{ int i,j;
  int* sc=NULL; 
  TO_MERGEP* merg=NULL; 
  TO_MERGEP var=NULL;
 
  merg=(TO_MERGEP*)calloc(ncl,sizeof(TO_MERGEP));
 
  for(i=0;i<ncl;i++) 
    {
     
      var=(TO_MERGEP)malloc(sizeof(struct TO_MERGE));
      var->NB=tabc[i].sbc_num;
      var->sbc_num=0;
      var->SSCs= (int*)calloc(tabc[i].sbc_num,sizeof(int));
      for(j=0;j<tabc[i].sbc_num;j++)  var->SSCs[j]=j;

      var->next=NULL;
      var->prev=NULL;                                      
      merg[i]=var;      
    }
  return merg;
}

#ifndef LIBSPOT


void SR_EVENT_POS_STORE(FILE* fp,Tree_p ESM,Tree_Esrg_p event)
{
  LP_ESRG = CACHE_STRING_ESRG;
  fseek(fp,0,SEEK_END);

  if(!event)
    {      	                       
      MY_CHAR_STORE((unsigned long)ESM->marking->marking_as_string);
      MY_CHAR_STORE((unsigned long)ESM->marking->length);
      MY_CHAR_STORE((unsigned long)ESM->marking->d_ptr);
   }
  else
    {
      MY_CHAR_STORE((unsigned long)ESM->marking->cont_tang);
      MY_CHAR_STORE((unsigned long)event->marking->marking_as_string);
      MY_CHAR_STORE((unsigned long)event->marking->length); 
    }

 fwrite(CACHE_STRING_ESRG,1,LP_ESRG-CACHE_STRING_ESRG,fp);
}



int Number_of_Instances(Result_p enb_h ,Result_p enb_h_store, int pri, int type )
{
  Result_p enb=enb_h;
  Event_p ptr=NULL;
  int nb=0;
  int tr;
  while (enb)
    {
      tr= GET_TRANSITION_INDEX(enb->list);
      switch (type)
	{
	case 1 : 
	  if(tabt[tr].pri == pri)
	    {
	      ptr= enb->list;
	      while(ptr)
		{
		  nb+=1;
		  ptr=ptr->next;
		}
	    }
	break;
	
	case 2:
	
	  if( ((tabt[tr].pri==pri) && (IS_ASYMETRIC(tr)))||
	      ((tabt[tr].pri==pri) && (IS_SYMETRIC(tr)) && !enb_h_store )
	     )
	    {
	      ptr= enb->list;
	      while(ptr)
		{
		  nb+=1;
		  ptr=ptr->next;
		}
	    }
	  break;
	} 
      enb=enb->next;
    }
  return nb;
}

int Number_of_Event(Tree_Esrg_p event,Result_p enb_h_store)
{
  Tree_Esrg_p ptr=event;
  int nb=0;

  while(ptr)
    {
      if(Number_of_Instances(ptr->enabled_head ,enb_h_store, ptr->marking->pri, 2 )) 
	nb+=1;
      ptr=ptr->Head_Next_Event;
    }

  return nb;

}
void WRITE_INSTANCE(FILE *fp, Event_p ev_p )

 {
  int tr = GET_TRANSITION_INDEX(ev_p);
  int ii;
  int cl;
 

  fprintf(fp,"%d ", tr);

  if(GET_TRANSITION_COMPONENTS(tr) > 0)
   {
     cl = tabt[tr].dominio[0];

     if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1)) 
       fprintf(fp,"%d %d ",ev_p->npla[0],ev_p->split[0] );
     
     for(ii=1;ii<tabt[tr].comp_num;ii++)
       {
       
	 cl = tabt[tr].dominio[ii];

	 if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1)) 
	   fprintf(fp,"%d %d ",  ev_p->npla[ii], ev_p->split[ii]);
       }
   
     fprintf(fp,"%d ",ev_p->ordinary_instances);  
   }
  
  
 }

void WRITE_REACHED_ESM(FILE* fp,Tree_p ESM,Tree_Esrg_p event )
{
 
  fprintf(fp,"%d ",ESM->marking->cont_tang ) ;

 if(event)
   fprintf( fp,"%d ",event->marking->cont_tang);
 else 
   fprintf (fp,"%d ",-1);
  
 fprintf(fp,"\n");

}

void WRITE_HEAD_EVENT(FILE* fp,Tree_p esm,Tree_Esrg_p event,int NB_INST )
{
 

  fprintf( fp,"%d ",event->marking->cont_tang);
 
  fprintf(fp,"%d ", NB_INST);
 
  fprintf(fp,"\n");
}

void WRITE_HEAD_SR(FILE* fp,Tree_p ESM,Result_p enb_h_store,int NB_INST )
{
 int i,k,l,s;   


 fprintf(fp,"%d ",ESM->marking->cont_tang);

 if(ESM->Marking_Type == SATURED_SYM)
   fprintf(fp,"%d ", SATURED_SYM );
 else
   fprintf(fp,"%d ", NO_SATURED_SYM );

 fprintf(fp,"%d ", NB_INST);

 // fprintf(fp,"%d ", Number_of_Event(ESM->NOT_Treated,enb_h_store));
 
 fprintf(fp,"\n");
}

void END_EV(FILE* fp){
  fprintf( fp,"#\n");
}

#endif
void FIRE_INSTANCE(Event_p ev_p, FILE *fp, int sym)

 {
  int tr = GET_TRANSITION_INDEX(ev_p);
  int ii;
  int cl;
  char name[MAX_TAG_SIZE];

  fprintf(fp,"%s :", tabt[tr].trans_name);

  if(GET_TRANSITION_COMPONENTS(tr) > 0)
   {
    cl = tabt[tr].dominio[0];
    if(ev_p->npla[0] != UNKNOWN)
     {

      if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1)) 
	if(sym==0)
	  {
	    int sb; 
	             
	    sb = get_static_subclass(cl,ev_p->npla[0]); 
	    sprintf(name,"%s_%d:%d",GET_STATIC_NAME(cl,sb),
		    ev_p->npla[0]-GET_STATIC_OFFSET(cl,sb),
		    ev_p->split[0]-GET_STATIC_OFFSET(cl,sb) );

	  }
	else
	  sprintf(name,"%s_%d:%d",tabc[cl].col_name,ev_p->npla[0],ev_p->split[0]);
      else
	get_object_name(cl,ev_p->npla[0],name);
     }
    else
      strcpy(name,"Unk");

    if(strcmp(tabt[tr].names[0],"?"))
      fprintf(fp,"BINDING  : %s <-- %s",tabt[tr].names[0],name);
    else
      fprintf(fp,"BINDING  : (implicit projection) <-- %s",name);

    for(ii=1;ii<tabt[tr].comp_num;ii++)
     {
       cl = tabt[tr].dominio[ii];
       if(ev_p->npla[ii] != UNKNOWN)
	 {

	   if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1)) 
    
	     if(sym==0)
	       {
		 int sb; 
		 
		 sb = get_static_subclass(cl,ev_p->npla[ii]); 
		 sprintf(name,"%s_%d:%d ",GET_STATIC_NAME(cl,sb),
			 ev_p->npla[ii]-GET_STATIC_OFFSET(cl,sb),ev_p->split[ii]-GET_STATIC_OFFSET(cl,sb));
		 
	       }     
	     else 
	       sprintf(name,"%s_%d:%d",tabc[cl].col_name,ev_p->npla[ii],ev_p->split[ii]);
	   
	   else
	     get_object_name(cl,ev_p->npla[ii],name);
	   
	 }
       else
	 strcpy(name,"Unk");
       if(strcmp(tabt[tr].names[ii],"?"))
	 fprintf(fp,", %s <-- %s ",tabt[tr].names[ii],name);
       else
	 fprintf(fp,", (implicit projection) <-- %s ",name);
     }
   }
  else
    fprintf(fp,"NO BINDING (non-colored)");
  
  fprintf(fp,"\n");
 }


void ESM_SOURCE(FILE* fp,Tree_p ESM, int EVENT)
{
 int i,k,l,s;   
 int ARRAY[MAX_CARD];

 fprintf(fp,"%s%d : %d","ESM",ESM->marking->cont_tang,COMPT_EVENT);

 if (EVENT)
   {
     fprintf (fp,"%s",":");
     for(i=0;i<ncl;i++)
       { 
	 if(ASYM_STATIC_STORE[i].sbc_num == 1)
	   {
	     for(l=0;l<SYM_TOT[i];l++)
	       {
		 fprintf(fp,"%s_%d%s",tabc[i].col_name, sfl_h->min[i][l],"[");	 
		 fprintf(fp,"%s%s_%d%s%d%s","(",ASYM_STATIC_STORE[i].ptr[0].name,l,":",
			 RESULT[i][0][sfl_h->min[i][l]][0] ,")");     
	       }
	   }
	 else
	   {
	     for(s=0;s<MAX_CARD;s++) ARRAY[s]=0; 
	     for(l=0;l<SYM_TOT[i];l++)
	       {
		 fprintf(fp,"%s_%d%s",tabc[i].col_name,l,"[");
		 for(k=0;k<ASYM_STATIC_STORE[i].sbc_num;k++)
		   if( RESULT[i][0][l][k]>0) 
		     
		     {
		       fprintf(fp,"%s%s_%d%s%d%s","(",ASYM_STATIC_STORE[i].ptr[k].name,ARRAY[k],":",RESULT[i][0][l][k],")");
		       ARRAY[k] +=1;         
		     }
		 
		 fprintf(fp,"%s","]"); 
	       }
	   }
       }
   }
 fprintf(fp,"\n");
}
void WRITE_ON_ESRG(FILE* srg)

 {
  int pl,k,cl;
  int offset,sb,base;
  char obj_name[MAX_TAG_SIZE];

  for(pl = 0 ; pl < npl; pl++)
   {
    if(IS_FULL(pl))
     {
      fprintf(srg,"%s(",PLACE_NAME(pl));
      if(IS_NEUTRAL(pl))
       {
	fprintf(srg,"%d)",net_mark[pl].total);
       }
      else
       {
	Token_p tk_p;

	for(tk_p = net_mark[pl].marking; tk_p != NULL; tk_p = NEXT_TOKEN(tk_p))
	 {
	  fprintf(srg,"%d<",tk_p->molt);
	  for (k = 0 ; k < tabp[pl].comp_num - 1; k++)
	   {
	    cl = tabp[pl].dominio[k];

            if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1))
	      
	        sprintf(obj_name,"%s_%d",tabc[cl].col_name,tk_p->id[k]);
              
	    else
	     get_object_name(cl,tk_p->id[k],obj_name);

	    fprintf(srg,"%s,",obj_name);
	   }
	  cl = tabp[pl].dominio[k];

          if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1))

           sprintf(obj_name,"%s_%d",tabc[cl].col_name,tk_p->id[k]);
          else
	   get_object_name(cl,tk_p->id[k],obj_name);
	  fprintf(srg,"%s>",obj_name);
	 }
	fprintf(srg,")");
      }

     }
    }
  fprintf(srg,"\n");

  for(cl = 0 ; cl < ncl; cl++)
   {
    if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1))
     {
      for(sb=0,base=0; sb<tabc[cl].sbc_num; sb++)
       {
        for(k = 0; k < GET_NUM_SS(cl,sb); k++)
         {
	 
	    offset = sfl_h->min[cl][k+base];
            sprintf(obj_name,"%s_%d",tabc[cl].col_name,offset);
	    fprintf(srg,"|%s|=%d "
		    ,obj_name
		    ,GET_CARD(cl,sb,offset));
	 
         }
        base += GET_NUM_SS(cl,sb);
       }
     }
   }
  fprintf(srg,"\n");
 }

void ESM_REACHED(FILE* fp,Tree_p ESM, int EVENT)
{
  int i,k,l,s;   

  int ARRAY[MAX_CARD];
  for(i=0;i<MAX_CARD;i++) ARRAY[i]=0; 

  fprintf(fp,"%s%d : %d ","ESM",ESM->marking->cont_tang,COMPT_EVENT);
 
 if (EVENT)
   {
     fprintf (fp,"%s",":");
     for(i=0;i<ncl;i++)
       { 
	 if(ASYM_STATIC_STORE[i].sbc_num == 1)
	   {
	     for(l=0;l<SYM_TOT[i];l++)
	       {
		 fprintf(fp,"%s_%d%s",tabc[i].col_name,l,"[");	 
		 fprintf(fp,"%s%s_%d%s%d%s","(",ASYM_STATIC_STORE[i].ptr[0].name, sfl_h->min[i][l],":",
			 RESULT[i][0][l][0] ,")");     
	       }
	   }
	 else
	   {
	     for(s=0;s<MAX_CARD;s++) ARRAY[s]=0; 
	     for(l=0;l<SYM_TOT[i];l++)
	       {
		 fprintf(fp,"%s_%d%s",tabc[i].col_name,l,"[");
		 for(k=0;k<ASYM_STATIC_STORE[i].sbc_num;k++)
		   if( RESULT[i][0][l][k]>0) 
		     
		     {
		       fprintf(fp,"%s%s_%d%s%d%s","(",ASYM_STATIC_STORE[i].ptr[k].name,ARRAY[k],":",RESULT[i][0][l][k],")");
		       ARRAY[k] +=1;         
		     }
		 
		 fprintf(fp,"%s","]"); 
	       }
	   }
       }
   }
  
 fprintf(fp,"\n");
 WRITE_ON_ESRG(fp); 
 fprintf(fp,"\n");
}
   
#ifndef LIBSPOT

int  EXCEPTION ()

{int i ;

 for(i=0;i<ncl;i++)
   if ((tabc[i].type==ORDERED) && (tabc[i].sbc_num!=1) )
     {
       printf("\n Sorry, ordred classes with more than one static sub-class are not allowed : Class (%s) \n", tabc[i].col_name );
       exit(0);
     } 
 return 0;  
}
#else
int  EXCEPTION ()

{int i ;

 for(i=0;i<ncl;i++)
   if ((tabc[i].type==ORDERED) )
     {
       printf("\n Sorry, ordred classes are not allowed yet  : Class (%s) \n", tabc[i].col_name );
       exit(0);
     } 
 return 0;  
}
#endif
