# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../../INCLUDE/const.h"
# include "../../INCLUDE/struct.h"
# include "../../INCLUDE/var_ext.h"

static FILE *def_fp = NULL;
static FILE *parse_fp = NULL;

extern int parser() ;
extern FILE* efopen() ;
extern FILE *jjin,*jjout,*mfp,*nfp2 ;


void read_DEF_file()
 {/* Init read_DEF_file */
  char tmp[MAXSTRING];
  char prs[MAXSTRING];
  char trash[4];
  char *name_p = NULL;
  char type;
  int start_parse = FALSE;
  int tr;
  float xcoord,ycoord;

  
  sprintf(tmp,"%sdef",net_name);
  sprintf(prs,"%sparse",net_name);
  def_fp = efopen(tmp,"r");
  while( TRUE )
   {/* Scanning .def file */
    if( fgets( tmp, MAXSTRING - 1, def_fp ) == NULL )
     if( feof( def_fp ) )
      break;
    if(tmp[0]=='|' )
     {/* Rate MD o delimitatore */
      if(tmp[1]=='2' && tmp[2]=='5' && tmp[3]=='6' && tmp[4]=='\n')
       {/* Delimitatore |256 */
	do
	 {
          fgets( tmp, MAXSTRING - 1, def_fp );
         }
	while(tmp[0]!='|' || tmp[1]!='\n');
        start_parse = TRUE;
       }/* Delimitatore |256 */
      else
       {/* Definizioni di rate MD */
	if(parse_DEF == MDRATE) 
	 {
	  name_p = tmp;
	  sscanf(tmp + 1,"%d",&tr);
	  nmd = tr - 1;
	  /*tabmd[nmd].trans_ind = tr;*/
          fgets( tmp, MAXSTRING - 1, def_fp );
	  parse_fp = efopen(prs,"w");
	  fprintf(parse_fp,"~z %s",tmp);
	  fclose(parse_fp);
	  jjin = efopen(prs,"r");
#ifdef BASTA_CON_LINUX
#ifdef LINUX
	  jjout = stderr;
#else
	  jjout = efopen("/dev/null","w");
#endif
#endif
	  parser();
	  fclose(jjin);
#ifdef BASTA_CON_LINUX
	  fclose(jjout);
#endif
	 }
	else if(parse_DEF == FALSE)
	 nmd++;
       }/* Definizioni di rate MD */
     }/* Rate MD o delimitatore */
    else if(start_parse)
     {/* Superato l'inizio file */
      if(parse_DEF != MDRATE)
       {/* Non e' la sola lettura degli MD terza passata */
       /* Lettura del nome della definizione (classe di colore....) */
        if(tmp[0]=='(')
         {/* Definizioni di colori, marcature o funzioni */
	  name_p = tmp + 1;
	  sscanf(name_p,"%s %c %f %f %c",read_name,&type,&xcoord,&ycoord,trash);
	  if(parse_DEF == INITIAL_MARKING)
	   cnt++;
	  if(parse_DEF != FALSE)
	   strcpy(bufname,read_name);
	  strcpy(error_name,read_name);

	  /* Lettura della definizione */
	  fgets( tmp, MAXSTRING - 1, def_fp );

	  /* Tipo di definizione e in tmp c'e' la definizione */
	  switch(type)
	   {
#ifdef SWN
	    case 'c' : if(parse_DEF == FALSE || parse_DEF == COLOR_CLASS)
                        {
                         parse_fp = efopen(prs,"w");
	  	         fprintf(parse_fp,"~c %s",tmp);
	  	         fclose(parse_fp);
	  	         jjin = efopen(prs,"r");
#ifdef BASTA_CON_LINUX
#ifdef LINUX
		         jjout = stderr;
#else
	  	         jjout = efopen("/dev/null","w");
#endif
#endif
		         parser();
		         fclose(jjin);
#ifdef BASTA_CON_LINUX
		         fclose(jjout);
#endif
                        }
		       break;
#endif
	    case 'm' : if(tmp[0]=='(')
		        {/* Definizione di sottoclasse dinamica */
		         if(parse_DEF == DYNAMIC_SUBCLASS)
			  {
			   parse_fp = efopen(prs,"w");
			   fprintf(parse_fp,"~j %s",tmp);
			   fclose(parse_fp);
			   jjin = efopen(prs,"r");
#ifdef BASTA_CON_LINUX
#ifdef LINUX
		           jjout = stderr;
#else
			   jjout = efopen("/dev/null","w");
#endif
#endif
			   parser();
			   fclose(jjin);
#ifdef BASTA_CON_LINUX
			   fclose(jjout);
#endif
			  }
		        }/* Definizione di sottoclasse dinamica */
		       else
		        {/* Definizione di marcatura */
		         if(parse_DEF == INITIAL_MARKING)
		          {
			   tabm[nmr].position = cnt;
			   tabm[nmr].file_pos = ftell(mfp);
                           nmr++;
			   fprintf(mfp,"~m %s",tmp);
			  }
		         else if(parse_DEF == FALSE)
		 	  nmr++;
		        }/* Definizione di marcatura */
		       break;
	    case 'f' : if(parse_DEF == FUNCTION)
		        fprintf(nfp2,"# define %s %s",bufname,tmp);
		       break;
	   }
	  fgets( tmp, MAXSTRING - 1, def_fp );
         }/* Definizioni di colori, marcature o funzioni */
       }/* Non e' la sola lettura degli MD terza passata */
      else 
	goto finish;
     }/* Superato l'inizio file */
   }/* Scanning .def file */
finish:
  fclose(def_fp);
  sprintf(prs,"%sparse",net_name);
  if((parse_fp = fopen(prs,"r")) != NULL)
   {
    fclose(parse_fp);
    sprintf(tmp,"rm %s",prs);
    system(tmp);
   }
 }/* End read_DEF_file */
