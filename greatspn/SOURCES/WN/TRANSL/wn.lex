
%option nostdinit

%%
\n                    { ungetc((char)0,jjin);
                        /*return(NEWLINE);*/ }
\_		      { return(UNDERSCORE);  }
\#		      { return(DIESIS);      }
\:		      { return(COLON);       }
\;		      { return(SEMICOLON);   }
\+		      { return(PLUS);        }
\-		      { return(MINUS);       }
\*		      { return(MOLT);        }
\/		      { return(DIV);         }
\%		      { return(DISTANCE);    }
\^		      { return(CARET);       }
\{		      { return(OBRCS);       }
\}		      { return(CBRCS);       }
\!		      { return(ESCL);        }
\.		      { return(POINT);       }
\,		      { return(COMMA);       }
\<\>                  { return(NE);          }
\<\=                  { return(LE);          }
\<		      { return(LT);      }
\>\=                  { return(GE);          }
\>		      { return(GT);     }
\(		      { /*fprintf(stdout,"(\n");*/return(OPAR);        }
\)		      { /*fprintf(stdout,")\n");*/return(CPAR);        }
\[		      { /*fprintf(stdout,"[\n");*/return(OBRCK);       }
\]		      { /*fprintf(stdout,"]\n");*/return(CBRCK);       }
=		      { /*fprintf(stdout,"=\n");*/return(EQ);       }
\~z/[' ']	      { 
			parsing_flag = MDRATE;
			return(MD);	     
		      }
\~w/[' ']	      { 
			parsing_flag = PLACE;
			return(PD);	     
		      }
\~k/[' ']	      {
			/*fprintf(stdout,"~k\n");*/parsing_flag = TRANSITION;
			return(TD);	     
		      }
\~f/[' ']	      {
			parsing_flag = FUNCTION;
			return(FU);	     
		      }
\~j/[' ']	      { 
			parsing_flag = DYNAMIC_SUBCLASS;
			return(DSC);	     
	              }
\~m/[' ']             { 
			parsing_flag = INITIAL_MARKING;
			return(MA);	     
	              }
\~c/[' ']	      { 
			parsing_flag = COLOR_CLASS;
			return(CO);	     
		      }
S                     { return(S);           }
\|		      { return(VBAR);        }
o/[' ']		      { 
			str_val = ORDERED ;
			return(O) ;
		      }
u/[' ']		      { 
			str_val = UNORDERED;
			return(US);
		      }
d/[(]		      { /*fprintf(stdout,"d\n");*/return(D);           }
ID/\n                 { return(ID);          }
id/\n                 { return(ID);          }
fact                  { return(FACT);        }
comb                  { return(COMB);        }
sqrt	              { return(SQRT);        }
pow	              { return(POW);         }
inv	              { return(INV);         }
max	              { return(MAXT);         }
min	              { return(MINT);         }
when	              { return(WHEN);        }
ever	              { return(EVER);        }
or		      { return(OR);          }
and		      { /*fprintf(stdout,"and\n");*/return(AND);	     }
FLUSH		      { return(FLUSH);	     }
[0-9]+		      { 
			str_val = atoi(jjtext) ;
			return(NUM);
		      }
[0-9]+\.[0-9]+	      { 
			real_val = strtod(jjtext,(char **)NULL) ;
			return(REALNUM);
		      }
[a-zA-Z][a-zA-Z_0-9]* { 
			strcpy(str_in,jjtext) ;
			 /*fprintf(stdout,"STRING\n");*/return(STRING);
		      }
[' ']|[\0]            {
                        /* Do NOTHING !! DO NOT ECHO ON STDOUT !!! */
                      }
%%
