

char *name_p = NULL;

void read_gard (FILE* gards_file ) {

  char tmp [MAXSTRING] ;
  char read_name[MAXSTRING];
  char gard_read[MAXSTRING];
  int i;
  
  while( fgets( tmp, MAXSTRING - 1, gards_file ))
    {
      sscanf(tmp,"%s %s", read_name, gard_read);

      for(i=0;i<ntr && strcmp(read_name,tabt[i].trans_name) ; i++);
     
      parse_DEF = TRANSITION;
 
      parse_fp = efopen(prs,"w");
      fprintf(parse_fp,"~k %s",gard_read);
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
      tabt[i].dyn_gard=tabt[i].guard ;
      tabt[i].guard = NULL;
    }
}
 


 
