#include <stdio.h>
#include "../../INCLUDE/const.h"
#include "../../INCLUDE/struct.h"
#include "../../INCLUDE/var_ext.h"
#include "../../INCLUDE/fun_ext.h"
#include "../../INCLUDE/macros.h"

#ifdef REACHABILITY
extern int * code_place;
extern int * min_place;
extern int * max_place;
extern int * init_place;
extern int max_priority;
extern int new_time;
extern int old_time;
extern void get_object_name();
#ifdef SWN
#ifdef SYMBOLIC
extern void get_dynamic_subclass_name();
extern Canonic_p sfl_h;
extern int get_dynamic_from_total();
extern int get_static_subclass();
extern int get_obj_off();
#endif
#endif

/*DOT
*File uses to store the SRG in dot format 
*/
extern FILE *f_dot;
/*DOT
*File uses to store the SRG in dot format 
*/

/*DOT
*Flag to set the store in the f_dot file
*/
extern int dot_flag;
/*DOT
*Flag to set the store in the f_dot file
*/
extern char bname[MAX_TAG_SIZE];
static int last_tang = 0;


/*DOT
*Function 
*/
/**************************************************************/
/* NAME : write_dot*/
/* DESCRIPTION : this fuction write the Marking into the dot file*/
/* PARAMETERS : id marking, pri, mark_type  */
/* RETURN VALUE : */
/**************************************************************/
void write_dot(int id,int pri,int mark_type,int tr)
{
 static int s_id=0;
 static int s_pri=0;
 static int s_tr=0;
 static int num_v=0;
 static int num_t=0; 
 char string_id[90];
 char string2[1024];
 char string1[90];
 string_id[0]='\0';
 string1[0]='\0';
 string2[0]='\0';
 
 if(IS_VANISHING(pri))
    {
     if (id>num_v)
       {
         sprintf(string_id,"V%d [label=\"V%d\" color=gray];\n ",id,id);
         num_v=id;
       }
     sprintf(string1,"V%d",id);	 
     //sprintf(string2,"[style=dotted color=dimgray label=\" %s%s\"]",TRANS_NAME(s_tr),bname);
     sprintf(string2,"[label=\" %s%s\"]",TRANS_NAME(s_tr),bname);
    }
   else if(IS_TANGIBLE(pri))
    {
      if (id>num_t)
        {
         sprintf(string_id,"T%d [label=\"T%d\"];\n ",id,id);
	 num_t=id;
        }
      sprintf(string1,"T%d",id);
      sprintf(string2,"[label=\" %s%s\"]",TRANS_NAME(s_tr),bname);
    }
   else
    {
    sprintf(string_id,"D%d [label=\"D%d\"];\n",id,id);
    sprintf(string1,"D%d",id);
    //sprintf(string2,"[label=\" %s%s\"]",TRANS_NAME(s_tr),bname);
    }
switch(mark_type)
   {/* Tipo di marcatura */
    case NORMAL :
		    if(IS_VANISHING(s_pri))
		     {
		      fprintf(f_dot,"\n %sV%d -> %s [style=dotted color=dimgray label=\" %s%s\"];",string_id,s_id,string1,TRANS_NAME(s_tr),bname);
		     }
		    else if(IS_TANGIBLE(s_pri))
		      {
		       fprintf(f_dot,"\n %sT%d -> %s  %s;",string_id,s_id,string1,string2);
		      }
		   break;
    case TANGIBLE_OR_VANISHING:
		      if((id==1)&&(!(IS_VANISHING(pri))))
		        fprintf(f_dot,"\n T%d [label=\"T%d\"];",id,id);
		      s_id=id;
                      s_pri=pri;
		      s_tr=tr;
		 break;
    case DEAD:
		 fprintf(f_dot,"\n D%d [label=\"D%d\" color=red];",id,id);
		  if(IS_VANISHING(s_pri))
		         fprintf(f_dot,"\n D%d [label=\"D%d\"]; \nV%d -> D%d [style=dotted color=dimgray label=\" %s%s\"];",id,id,s_id,id,TRANS_NAME(s_tr),bname);
		      else 
		         fprintf(f_dot,"\n D%d [label=\"Marking D%d\"]; \nT%d -> D%d [label=\" %s%s\"];",id,id,s_id,id,TRANS_NAME(s_tr),bname);

		 break;
    default:
		 break;
   }/* Tipo di marcatura */
}

/*DOT
*Function 
*/











/* ********************************************************************** */
/*                                                                        */
/*   Scrittura su file del Symbolic Reachability Graph                    */
/*                                                                        */
/* ********************************************************************** */
void write_on_srg(FILE  *srg,  int  dir)
 {/* Init write_on_srg */
  int pl,k,cl;
#ifdef SWN
#ifdef SYMBOLIC
  int offset,sb,base;
#endif
#endif
  char obj_name[MAX_TAG_SIZE];

  for(pl = 0 ; pl < npl; pl++)
   {/* Per ogni posto */
    if(IS_FULL(pl))
     {/* Posto pieno */
#ifdef GSPN
      fprintf(srg,"%s(%d)",PLACE_NAME(pl),net_mark[pl].total);
#endif
#ifdef SWN
      fprintf(srg,"%s(",PLACE_NAME(pl));
      if(IS_NEUTRAL(pl))
       {/* Posto neutro */
	fprintf(srg,"%d)",net_mark[pl].total);
       }/* Posto neutro */
      else
       {/* Posto colorato */
	Token_p tk_p;

	for(tk_p = net_mark[pl].marking; tk_p != NULL; tk_p = NEXT_TOKEN(tk_p))
	 {/* Per ogni token della marcatura */
	  fprintf(srg,"%d<",tk_p->molt);
	  for (k = 0 ; k < tabp[pl].comp_num - 1; k++)
	   {
	    cl = tabp[pl].dominio[k];
#ifdef COLOURED
	    get_object_name(cl,tk_p->id[k],obj_name);
#endif
#ifdef SYMBOLIC
            if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1))
	     get_dynamic_subclass_name(cl,tk_p->id[k],obj_name);
	    else
	     get_object_name(cl,tk_p->id[k],obj_name);
#endif
	    fprintf(srg,"%s,",obj_name);
	   }
	  cl = tabp[pl].dominio[k];
#ifdef COLOURED
	  get_object_name(cl,tk_p->id[k],obj_name);
#endif
#ifdef SYMBOLIC
          if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1))
           get_dynamic_subclass_name(cl,tk_p->id[k],obj_name);
          else
	   get_object_name(cl,tk_p->id[k],obj_name);
#endif
	  fprintf(srg,"%s>",obj_name);
	 }/* Per ogni token della marcatura */
	fprintf(srg,")");
      }/* Posto colorato */
#endif
     }/* Posto pieno */
    }/* Per ogni posto */
  fprintf(srg,"\n");
#ifdef SWN
#ifdef SYMBOLIC
  for(cl = 0 ; cl < ncl; cl++)
   {/* Per ogni classe */
    if(IS_UNORDERED(cl) || (IS_ORDERED(cl) && GET_STATIC_SUBCLASS(cl) == 1))
     {/* Classe non ordinata */
      for(sb=0,base=0; sb<tabc[cl].sbc_num; sb++)
       {/* Per ogni sottoclasse statica */
        for(k = 0; k < GET_NUM_SS(cl,sb); k++)
         {/* Per ogni sottoclasse dinamica */
	  if(dir)
	   {
	    offset = sfl_h->min[cl][k+base];
            get_dynamic_subclass_name(cl,offset,obj_name);
	    fprintf(srg,"|%s|=%d "
		    ,obj_name
		    ,GET_CARD(cl,sb,offset));
	   }
          else
	   {
           get_dynamic_subclass_name(cl,tabc[cl].sbclist[sb].offset+k,obj_name);
	   fprintf(srg,"|%s|=%d "
		    ,obj_name
		    ,GET_CARD_BY_TOTAL(cl,sb,k));
	   }
         }/* Per ogni sottoclasse dinamica */
        base += GET_NUM_SS(cl,sb);
       }/* Per ogni sottoclasse statica */
     }/* Classe non ordinata */
   }/* Per ogni classe */
  fprintf(srg,"\n");
#endif
#endif
 }/* End write_on_srg */

/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/*                                                            */
/*   Scrittura sul file .grg                                  */
/*                                                            */
/**************************************************************/
void write_ctrs(FILE  *ctrs)
 {/* Init write_ctrs */
  register int pl;
  register unsigned char cc;

  for ( pl = 0; pl < npl; pl++)
   {/* Per ogni posto */
    if (code_place[pl] < 255)
     {/* Molteplicita' minore del massimo consentito */
      cc = (unsigned char)(0xFF & code_place[pl]);
     /* putc(cc,ctrs); */
      putc(code_place[pl],ctrs);
     }/* Molteplicita' minore del massimo consentito */
    else
     {/* Molteplicita' >= del massimo consentito */
      out_error(ERROR_MARKING_CODING,pl,0,0,0,NULL,NULL);
     }/* Molteplicita' >= del massimo consentito */
   }/* Per ogni posto */
 }/* End write_ctrs */



#ifdef SWN 
 /**************************************************************/
/* NAME : write the marking*/
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/*                                                            */
/*   Scrittura sul file .grg                                  */
/*                                                            */
/**************************************************************/

void write_cvrs(FILE *f_cvrs,FILE*f_cvrsoff,int evan){/* Init write_ctrs */

int pl,k,cl,sb,token=0;
int lim,numcard;
fprintf(f_cvrsoff,"T%d %d\n",evan, ftell(f_cvrs));
for ( pl = 0; pl < npl; pl++)
	{/* Per ogni posto */
	if (IS_FULL(pl))     
		{/* Posto pieno */
		fprintf(f_cvrs,"%d(",pl);
    		if(IS_NEUTRAL(pl))
       			{/* Posto neutro */
			fprintf(f_cvrs,"%d)",net_mark[pl].total);
       			}/* Posto neutro */
		else
			{
			Token_p tk_p;
			for(tk_p = net_mark[pl].marking; tk_p != NULL; tk_p = NEXT_TOKEN(tk_p))
	 			{/* Per ogni token della marcatura */
				numcard=1;
#ifdef SWN
#ifdef SYMBOLIC
for (k = 0 ; k < tabp[pl].comp_num ; k++)
	   {
	   	  cl = tabp[pl].dominio[k];
	    	  sb = get_static_subclass(cl,tk_p->id[k]); 
		  lim = get_obj_off(sb,cl);
		  numcard=numcard*GET_CARD(cl,sb,lim);	 
	     }
#endif
#endif
	  			token=token+numcard*tk_p->molt;
	  			}/* Per ogni token della marcatura */
			fprintf(f_cvrs,"%d)",token);
			token=0;
      			}/* Posto colorato */			
		}/* Posto pieno */
   	}/* Per ogni posto */
fprintf(f_cvrs,"\n");	
}/* End write_ctrs */
#endif
 

/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/*                                                                        */
/*   Scrittura sul file .grg                                              */
/*                                                                        */
/*   NOTA: il grg e' creato "ad hoc"                                      */
/*   1 byte per ogni posto, max numero codificabile 255, i valori         */
/*   non significativi sono messi a 0                                     */
/*                                                                        */
/* ********************************************************************** */
void write_grg(FILE  *grg)
 {/* Init write_grg */
  register int i;

  fprintf(grg,"%d %d %d %d\n",1,npl,max_priority,ntr);
  fprintf(grg,"%d %d\n",0,npl);
  for(i = 0; i < npl; i++)
   {/* Per ogni posto */
    fprintf(grg," %d %d %d %d %d\n"
	       ,0,0,max_place[i],1,0);
    fprintf(grg,"  %d %d %d %d %d\n"
	       ,i+1,255,0,0,0);
   }/* Per ogni posto */
  for(i=0; i<npl; i++)
   fprintf(grg,"%d %d %d %d %d %d %d %s\n"
	      ,i+1,0,0,0,0,255,init_place[i],PLACE_NAME(i));
 }/* End write_grg */
#ifdef DEBUG_THROUGHPUT
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
void update_thr_files(int  mark_type,  Tree_p  fire,  int  tr,  int  pri)
 {/* Init update_thr_files */
  int pos;

  switch(mark_type)
   {/* Tipo di marcatura */
    case NORMAL :
		 if(IS_VANISHING(pri))
		  fprintf(thr,"V%d\n"
			     ,current_marking->marking->cont_tang);
		 else if(IS_TANGIBLE(pri))
		  fprintf(thr,"T%d\n"
			     ,current_marking->marking->cont_tang);
		 else
		  fprintf(thr,"D%d\n"
			     ,current_marking->marking->cont_tang);
		 break;
    case TANGIBLE_OR_VANISHING:
		 if(IS_VANISHING(pri))
		  fprintf(thr,"V%d ",fire->marking->cont_tang);
		 else
		  {
		   if(evan == 0)
		    {
		     last_tang = fire->marking->cont_tang;
		     pos = ftell(thr);
		     fprintf(vnum,"%d ",pos);
		    }
		   else
		    {
		     if(last_tang != fire->marking->cont_tang)
		      {
		       pos = ftell(thr);
		       fprintf(vnum,"%d\n",evan);
		       fprintf(vnum,"%d ",pos);
		       last_tang = fire->marking->cont_tang;
		      }
		     }
		   fprintf(thr,"T%d ",fire->marking->cont_tang);
		  }
		 fprintf(thr,"%d ",tr);
		 break;
    case DEAD:
		 fprintf(thr,"D%d\n",current_marking->marking->cont_tang);
		 break;
    default:
		 break;
   }/* Tipo di marcatura */
 }/* End update_thr_files */
#endif
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
void update_rg_files(int  mark_type,  Tree_p  fire,  int  tr,  int  pri)
 {/* Init update_rg_files */

  switch(mark_type)
   {/* Tipo di marcatura */
    case NORMAL :
#ifdef GSPN
		 if(IS_VANISHING(pri))
		  fprintf(srg,"MARKING V%ld \n"
			     ,current_marking->marking->cont_tang);
		 else if(IS_TANGIBLE(pri))
		  fprintf(srg,"MARKING T%ld \n"
			     ,current_marking->marking->cont_tang);
		 else
		  fprintf(srg,"MARKING D%ld \n"
			     ,current_marking->marking->cont_tang);
#endif
 /*DOT
  *write file dot
  */
  if (dot_flag)
   write_dot(current_marking->marking->cont_tang,pri,mark_type,tr);
  /*DOT
  *write file dot
  */
#ifdef SWN
#ifdef SYMBOLIC
		 if(IS_VANISHING(pri))
		  fprintf(srg,"MARKING V%ld # ordinary markings : %d\n"
			    ,current_marking->marking->cont_tang
			    ,current_marking->marking->ordinary);
		 else if(IS_TANGIBLE(pri))
		  fprintf(srg,"MARKING T%ld # ordinary markings : %d\n"
			    ,current_marking->marking->cont_tang
			    ,current_marking->marking->ordinary);
		 else
		  fprintf(srg,"MARKING D%ld # ordinary markings : %d\n"
			    ,current_marking->marking->cont_tang
			    ,current_marking->marking->ordinary);
#endif
#ifdef COLOURED
		 if(IS_VANISHING(pri))
		  fprintf(srg,"MARKING V%ld \n"
			     ,current_marking->marking->cont_tang);
		 else if(IS_TANGIBLE(pri))
		  fprintf(srg,"MARKING T%ld \n"
			     ,current_marking->marking->cont_tang);
		 else
		  fprintf(srg,"MARKING D%ld \n"
			     ,current_marking->marking->cont_tang);
#endif
#endif
		 write_on_srg(srg,1);
		 fprintf(srg,"\n");
		 break;
    case TANGIBLE_OR_VANISHING:

 /*DOT
  *write file dot
  */
  if (dot_flag)
   write_dot(fire->marking->cont_tang,pri,mark_type,tr);
  /*DOT
  *write file dot
  */
		 if(IS_VANISHING(pri))
		  fprintf(srg,"MARKING V%ld (vanishing)\n"
			    ,fire->marking->cont_tang);
		 else
		  fprintf(srg,"MARKING T%ld (tangible)\n"
			     ,fire->marking->cont_tang);
	      /* write_on_srg(srg,0); */
		 fprintf(srg,"[%s (<",TRANS_NAME(tr));
		 break;
    case DEAD:
  /*DOT
  *write file dot
  */
  if (dot_flag)
   write_dot(current_marking->marking->cont_tang,pri,mark_type,tr);
  /*DOT
  *write file dot
  */   
#ifdef GSPN
		 fprintf(srg,"MARKING D%ld (dead)\n"
			    ,current_marking->marking->cont_tang);
#endif
#ifdef SWN
#ifdef SYMBOLIC
		 fprintf(srg,"MARKING D%ld # ordinary marking: %d (dead)\n"
			    ,current_marking->marking->cont_tang
			    ,current_marking->marking->ordinary);
#endif
#ifdef COLOURED
		 fprintf(srg,"MARKING D%ld (dead)\n"
			    ,current_marking->marking->cont_tang);
#endif
#endif
		 write_on_srg(srg,1);
		 fprintf(srg,"\n");
		 break;
    default:
		 break;
   }/* Tipo di marcatura */
 }/* End update_rg_files */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
void code_marking()
 {/* Init code_marking */
  register int pl;

  for(pl = 0 ; pl < npl ; pl++)
   {/* Per ogni posto */
    code_place[pl] = net_mark[pl].total;
    if(code_place[pl] < min_place[pl])
     min_place[pl] = code_place[pl];
    else if (code_place[pl] > max_place[pl])
     max_place[pl] = code_place[pl];
   }/* Per ogni posto */
 }/* End code_marking */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
void write_final_results(FILE  *fp)
 {/* Init write_final_results */
  fprintf(fp,"\n");
#ifdef GSPN
  fprintf(fp," ***** Reachability Graph ***** \n");
#endif
#ifdef SWN
#ifdef SYMBOLIC
  fprintf(fp," ***** Symbolic Reachability Graph ***** \n");
#endif
#ifdef COLOURED
  fprintf(fp," ***** Reachability Graph ***** \n");
#endif
#endif
  fprintf(fp,"\n");
  fprintf(fp,"TANGIBLE MARKINGS : %ld\n",tang-dead);
  fprintf(fp,"VANISHING MARKINGS : %ld\n",evan);
  fprintf(fp,"DEAD MARKINGS : %ld\n",dead);
  fprintf(fp,"\n");
  fprintf(fp," *************************************** \n");
  fprintf(fp,"\n");
#ifdef SWN
#ifdef SYMBOLIC
  fprintf(fp,"Ordinary tangible markings : %1.14lg\n",ord_tang);
  fprintf(fp,"Ordinary vanishing markings : %1.14lg\n",ord_evan);
  fprintf(fp,"Ordinary dead markings : %1.14lg\n",ord_dead);
#endif
#endif
  if (home)
   fprintf(fp,"The initial marking is a home state\n"); 
  fprintf(fp,"Time required ----------> %d\n",new_time-old_time);
  fprintf(fp,"\n");
  fprintf(fp," *************************************** \n");
 }/* End write_final_results */
#endif
