#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "../../INCLUDE/const.h"
#include "../../INCLUDE/struct.h"
#include "../../INCLUDE/var_ext.h"
#include "../../INCLUDE/fun_ext.h"
#include "../../INCLUDE/macros.h"

#ifdef SIMULATION
extern double random_generate();
extern double read_t_st(); 
extern int events_made;
extern int  event_inst;
extern int old_made;
extern double old_time;
extern double cur_time;
extern time_t newt;
extern time_t oldt;
extern FILE *thptfp;
extern FILE *timefp;
extern FILE *statfp;

static FILE *resfp = NULL;
static FILE *stafp = NULL;

static int transitory = TRUE;
static int batch_events = UNKNOWN;
static int n_batch = 0 ;

static double t_med_n = 0.0;
static double t_med_i = 0.0;

/***************** PER i POSTI *******************/
static double *tok_i = NULL;
static double *tmn = NULL;

/***************** PER LE TRANSIZIONI *******************/
static double *fire_i = NULL;
static double *fire_n = NULL;

/***************** PER ENTRAMBI *******************/
static double *tsq_f = NULL;
static double *ttsq_f = NULL;

extern FILE *statfp;
extern FILE *thptfp;
extern FILE *timefp;
extern int num_event;


#if STATISTICFEL
extern long numEvFEL;
extern long numEvOrdFEL;
#endif

/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
static int is_tagged(ii,type)
 int ii;
 int type;
 {/* Init is_tagged */
  return(  (type==TRANSITION)?tabt[ii].tagged : tabp[ii].tagged );
 }/* End is_tagged */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
static int get_batch_lenght(min,max)
 int min;
 int max;
 {/* Init get_batch_lenght */
  return(min+floor((max-min)*random_generate()));
 }/* Init get_batch_lenght */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
static int end_batch()
 {/* Init end_batch */
  if((events_made-old_made+1)==batch_events)
   {/* Fine del batch */
    old_made=events_made;
    transitory=TRUE;
    fprintf(stdout,"End batch number %d\n",n_batch+1);
   }/* Fine del batch */
  return(transitory);
 }/* End end_batch */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
int end_transitory(first_trans,initial_events,min_lenght,max_lenght)
 int first_trans;
 int initial_events;
 int min_lenght;
 int max_lenght;
 {/* Init transitory */
  int ii;
  int comp;

  if(n_batch == 0)
   comp = first_trans;
  else
   comp = initial_events;

  if(transitory)
   {/* Flag per il transitorio inizialmente a TRUE */
    if((events_made-old_made) == comp)
     {/* Fine del transitorio e determinazione lunghezza batch */
      old_made=events_made;
      transitory=FALSE;
      batch_events=get_batch_lenght(min_lenght,max_lenght);
      for(ii=0;ii<npl;ii++)
       tok_i[ii]=0.0;
      for(ii=0;ii<ntr;ii++)
       fire_i[ii]=0.0;
      t_med_i=0.0;
      fprintf(stdout,"\nStart batch number %d of length %d",n_batch+1,batch_events);
     }/* Fine del transitorio e determinazione lunghezza batch */
   }/* Flag per il transitorio inizialmente a TRUE */
  return(!transitory);
 }/* End transitory */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
static int compute_confidence_level(conf,approx,type,outfp,lstafp)
 int conf;
 int approx;
 int type;
 FILE *outfp;
 FILE *lstafp;
 {/* Init compute_confidence_level */
  int ii,camp,elements,go = TRUE;
  double *nth;
  double t_sigma_quad=0.0;
  double time_value,estimated_value,D,K,mid_value,inf_lim,sup_lim,delta,perc;
  double DEN;
  FILE *filefp = NULL;

  if(n_batch > 1)
   {/* Almeno un batch */
#ifdef GREATSPN
    if(type == TRANSITION || type == GREATSPN)
#else
    if(type == TRANSITION )
#endif
     {
      elements = ntr;
      nth = fire_n;
      filefp = thptfp;
     }
    else
     {
      elements = npl;
      nth = tmn;
      filefp = statfp;
     }
    for(camp = 1; camp <= n_batch ; camp++)
     {/* Per i campioni precedenti */
      fscanf(timefp,"%lf\n",&time_value);
      t_sigma_quad+=(time_value-t_med_n)*(time_value-t_med_n);
      for(ii = 0; ii < elements; ii++)
       {/* Per ogni elemento */
        if(is_tagged(ii,type))
         {/* Elemento per il quale raccogliere le statistiche */
  	  fscanf(filefp,"%lf\n",&estimated_value);
  	  tsq_f[ii]+=(estimated_value - nth[ii])*(estimated_value - nth[ii]);
	  ttsq_f[ii]+=(estimated_value - nth[ii])*(time_value-t_med_n);
         }/* Elemento per il quale raccogliere le statistiche */
       }/* Per ogni elemento */
     }/* Per i campioni precedenti */
    t_sigma_quad /= (n_batch - 1) ;
    K = read_t_st(conf,n_batch - 1);
    K *= K;
    K /= n_batch;
    for(ii = 0 , go = TRUE ; ii < elements ; ii++)
     {/* Per ogni elemento */
      if(is_tagged(ii,type))
       {/* Elemento per il quale raccogliere le statistiche */
        tsq_f[ii]/=(n_batch - 1);
        ttsq_f[ii]/=(n_batch - 1);
	D = (t_med_n * nth[ii] - K*ttsq_f[ii])*(t_med_n*nth[ii]-K*ttsq_f[ii])
	  - (t_med_n*t_med_n-K*t_sigma_quad)*(nth[ii]*nth[ii]-K*tsq_f[ii]);
        if(D < 0.0)
	 D = 0.0;
	DEN = (t_med_n*t_med_n-K*t_sigma_quad);
        if(DEN != 0)
         {/* Denominatore != 0 */
          inf_lim = (t_med_n*nth[ii]-K*ttsq_f[ii]-sqrt(D))/DEN;
          sup_lim = (t_med_n*nth[ii]-K*ttsq_f[ii]+sqrt(D))/DEN;
         }/* Denominatore != 0 */
        else
         {/* Denominatore = 0 */
          inf_lim = 0.0;
          sup_lim = 0.0;
         }/* Denominatore = 0 */
	 delta = (sup_lim - inf_lim) / 2;
	mid_value = delta + inf_lim;
        if(mid_value != 0.0)
         perc = delta * 100.0 / mid_value ;
        else
         perc = 0.0;
	if(type == TRANSITION)
         {
         fprintf(outfp,"Throughput of %s (%lf ): %1.12g <= X <= %1.12g \nValue %1.12g Mean Value %1.12g Accuracy %1.12g\n"
		,tabt[ii].trans_name,fire_i[ii],inf_lim,sup_lim,nth[ii]/t_med_n,mid_value,perc);
         if(lstafp != NULL)
	  fprintf(lstafp,"Thru_%s = %lg\n",tabt[ii].trans_name,nth[ii]/t_med_n);

         }
	else if(type == PLACE)
         {
         fprintf(outfp,"Mean n.of tokens in %s : %1.12g <= mu <= %1.12g\nValue %1.12g Mean Value %1.12g Accuracy %1.12g\n"
		,tabp[ii].place_name,inf_lim,sup_lim,nth[ii]/t_med_n,mid_value,perc);
         if(lstafp != NULL)
          fprintf(lstafp,"%s = %lg\n",tabp[ii].place_name,nth[ii]/t_med_n);
         }
	else
	 fprintf(outfp,"Thru_%s = %lf\n",tabt[ii].trans_name,nth[ii]/t_med_n);
	go &= perc <= approx;
       }/* Elemento per il quale raccogliere le statistiche */
#ifdef GREATSPN
      else if(type == GREATSPN)
       fprintf(outfp,"Thru_%s = %g\n",tabt[ii].trans_name,nth[ii]/t_med_n);
#endif
     }/* Per ogni elemento */
   }/* Almeno un batch */
  return(go);
 }/* End compute_confidence_level */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
static int check_results(approx,conf,file)
 int approx;
 int conf;
 char file[MAXSTRING];
 {/* Init check_results */
   int ok_transition,ok_place,ii;
   int max;
   char buf[MAXSTRING],str[MAXSTRING],buf2[MAXSTRING];

/********************** INIZIALIZZAZIONE ***********************/
   max = MAX(ntr,npl);
/********************** INIZIALIZZAZIONE ***********************/
   n_batch++;
/************* media campionaria del tempo al passo i *****************/
/************* e scrittura sul file dei campioni **********************/
   t_med_n = ((n_batch - 1)*t_med_n + t_med_i)/n_batch;
   fprintf(timefp,"%lf\n",t_med_i);
/************* media campionaria del tempo al passo i *****************/
/************* e scrittura sul file dei campioni **********************/
/********** AGGIORNAMENTO VALOR MEDIO PER IL NUMERO DI TOKEN **********/
   for(ii=0;ii<npl;ii++)
    if(tabp[ii].tagged)
     {/* Posto per il quale raccogliere le statistiche */
      tmn[ii] = ((n_batch - 1)*tmn[ii] + tok_i[ii])/n_batch;
      fprintf(statfp,"%lf\n",tok_i[ii]);
     }/* Posto per il quale raccogliere le statistiche */
/********** AGGIORNAMENTO VALOR MEDIO PER IL NUMERO DI TOKEN **********/

/**********    AGGIORNAMENTO THROUGHPUT DELLE TRANSIZIONI    **********/
/************* e scrittura sul file dei campioni **********************/
   for(ii=0;ii<ntr;ii++)
    if(tabt[ii].tagged)
     {/* Transizione per la quale raccogliere le statistiche */
      fire_n[ii] = ((n_batch - 1)*fire_n[ii] + fire_i[ii])/n_batch;
      fprintf(thptfp,"%lf\n",fire_i[ii]);
     }/* Transizione per la quale raccogliere le statistiche */
/**********    AGGIORNAMENTO THROUGHPUT DELLE TRANSIZIONI    **********/


   fprintf(stdout,"\n---------------------------------------------\n");
   fprintf(stdout,"|                BATCH NUMBER %d             |\n",n_batch);
   fprintf(stdout,"---------------------------------------------\n\n");
   fprintf(stdout,"Current time %lf\n\n",cur_time);
   if(n_batch > 1)
    {
     rewind(thptfp);
     rewind(timefp);
     for(ii=0;ii<max;ii++)
      tsq_f[ii] = ttsq_f[ii] = 0.0;
     ok_transition = compute_confidence_level(conf,approx,TRANSITION,stdout,NULL);
     rewind(statfp);
     rewind(timefp);
     fprintf(stdout,"---------------------------------------------\n\n");
     for(ii=0;ii<max;ii++)
      tsq_f[ii] = ttsq_f[ii] = 0.0;
     ok_place = compute_confidence_level(conf,approx,PLACE,stdout,NULL);
    }
   if(ok_transition && ok_place	&& n_batch > 10)
    {/* Fine simulazione */
     time(&newt);
     fprintf(stdout,"\n");
     if(newt!=oldt)
      fprintf(stdout,"Efficiency ---> %zu transition firings per second\n",
	       events_made/(newt-oldt));
     else
      fprintf(stdout,"Efficiency ---> %d transition firings per second\n",
	       events_made);
     fprintf(stdout,"Time required for %d events -------> %zu\n",events_made,newt-oldt);
#ifdef GREATSPN
     sprintf(buf,"%s.simres",file);
     sprintf(buf2,"%s.sta",file);
#else
     sprintf(buf,"nets/%s.simres",file);
     sprintf(buf2,"nets/%s.sta",file);
#endif
#ifdef SWN
     for(ii=0;ii<ncl;ii++)
      {
       sprintf(str,"%s%d",tabc[ii].col_name,tabc[ii].card);
       strcat(buf,str);
      }
     resfp=efopen(buf,"w");
     fprintf(resfp,"\n");
#ifdef COLOURED
     fprintf(resfp," ******* Coloured Simulation *******\n");
#endif
#ifdef SYMBOLIC
     fprintf(resfp," ******* Symbolic Simulation *******\n");
#endif
#endif
#ifdef GSPN
     resfp=efopen(buf,"w");
     fprintf(resfp," ******* GSPN Simulation *******\n");
#endif
     stafp=efopen(buf2,"w");
     fprintf(resfp,"\n");
#ifdef DEBUG_malloc
#ifdef SIMULATION
     fprintf(resfp,"MEAN NUMBER OF EVENTS : %lf\n",
		   (float)tot_event/events_made);
     fprintf(resfp,"MAX NUMBER OF EVENTS : %d\n",max_ev);
     fprintf(resfp,"MIN NUMBER OF EVENTS : %d\n",min_ev);
     fprintf(resfp,"\n");
#if STATISTICFEL
     fprintf(resfp,"NUMBER OF SYMBOLIC EVENTS: %lf VS NUMBER OF ORDINARY EVENTS: %lf\n",  (float)numEvFEL/events_made, (float)numEvOrdFEL/events_made );
     fprintf(resfp,"NUMBER OF ORDINARY EVENTS/NUMBER OF SYMBOLIC EVENTS: %lf\n",  (float)numEvOrdFEL/numEvFEL);
#endif    
     
     fprintf(resfp," ***********************************\n");
     fprintf(resfp,"\n");
#endif
#endif
     fprintf(resfp,"Results :         \n");

     rewind(thptfp);
     rewind(timefp);
     for(ii=0;ii<max;ii++)
      tsq_f[ii] = ttsq_f[ii] = 0.0;
     ok_transition = compute_confidence_level(conf,approx,TRANSITION,resfp,stafp);
     rewind(statfp);
     rewind(timefp);
     for(ii=0;ii<max;ii++)
      tsq_f[ii] = ttsq_f[ii] = 0.0;
     ok_place = compute_confidence_level(conf,approx,PLACE,resfp,stafp);

     fprintf(resfp,"\n");
     fprintf(resfp,"Efficiency ---> %zu transition firings per second\n",
	       events_made/(newt-oldt));
     fprintf(resfp,"Time required for %d events -------> %zu\n"
		      ,events_made,newt-oldt);
     fprintf(resfp,"Simulated time --------> %lf\n",cur_time);
     fprintf(resfp,"Numero di campioni usati  --------> %d\n",n_batch);
     fprintf(resfp,"Grado di approssimazione --------> %d\n",approx);
     fprintf(resfp,"Livello di confidenza  --------> %d\n",conf);
     fprintf(resfp,"\n");
     fprintf(resfp," ***********************************\n");
     fprintf(resfp,"\n");
     fclose(resfp);
     fclose(stafp);
#ifdef GREATSPN
     sprintf(buf,"%s.sta",file);
     resfp = efopen(buf,"w");
     for(ii=0;ii<max;ii++)
      tsq_f[ii] = ttsq_f[ii] = 0.0;
     ok_transition = compute_confidence_level(conf,approx,GREATSPN,resfp);
     fclose(resfp);
   /*  sprintf(buf,"%s.mpd",file);
     resfp = efopen(buf,"aw");
     fclose(resfp);
     sprintf(buf,"%s.epd",file);
     resfp = efopen(buf,"aw");
     fclose(resfp);
     sprintf(buf,"%s.tpd",file);
     resfp = efopen(buf,"aw");
     fclose(resfp); */
#endif
     return(FALSE);
    }/* Fine simulazione */
  return(TRUE);
 }/* End check_results */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
void init_stat()
 {/* Init init_stat */
  int ii;

  tok_i=(double *)ecalloc(npl,sizeof(double));
  tmn=(double *)ecalloc(npl,sizeof(double));
  for(ii=0;ii<npl;ii++)
   tmn[ii]=0;

  fire_i=(double *)ecalloc(ntr,sizeof(double));
  fire_n=(double *)ecalloc(ntr,sizeof(double));
  for(ii=0;ii<ntr;ii++)
   fire_n[ii]=0;

  tsq_f=(double *)ecalloc(MAX(ntr,npl),sizeof(double));
  ttsq_f=(double *)ecalloc(MAX(ntr,npl),sizeof(double));
 }/* End init_stat */
/**************************************************************/
/* NAME : */
/* DESCRIPTION : */
/* PARAMETERS : */
/* RETURN VALUE : */
/**************************************************************/
int compute_batch_statistics(ev_type,approx,conf,file)
 int ev_type;
 int approx;
 int conf;
 char file[MAXSTRING];
 {/* Init compute_batch_statistics */
  int again_flag = TRUE;
  int ii;

  if((cur_time - old_time) > EPSILON)
   {/* Transizione temporizzata */
    t_med_i+=cur_time-old_time;
    for(ii=0;ii<npl;ii++)
     {/* Raccolta statistiche */
      if(tabp[ii].tagged)
       {/* Statistiche specializzate */
	tok_i[ii] += net_mark[ii].total * (cur_time-old_time);
       }/* Statistiche specializzate */
     }/* Raccolta statistiche */
   }/* Transizione temporizzata */
  if(tabt[ev_type].tagged)
   fire_i[ev_type]+=1.0;
  if(end_batch())
   again_flag=check_results(approx,conf,file);
  return(again_flag);
 }/* End compute_batch_statistics */
#endif
