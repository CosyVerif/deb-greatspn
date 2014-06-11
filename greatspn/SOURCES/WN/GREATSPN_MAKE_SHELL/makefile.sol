#directories
CSOU = SOLVE
SFK = SUPPORT
OBJ = OBJ
INC = INCLUDE
BCK = BACKUP
TRS = SOLVE
BINDIR = SOLVE

#commands
COMP = /usr/local/bin/sparc-sun-sunos4.1.3-gcc -c -O3 -w -o
LINK = /usr/local/bin/sparc-sun-sunos4.1.3-gcc -O3 -w -o

#files groups

#general rules
sol : ${OBJ}/compact.o ${BINDIR}/swn_ggsc ${BINDIR}/swn_stndrd ${BINDIR}/swn_gst_stndrd $(BINDIR)/swn_gst_prep 

${OBJ}/compact.o : ${CSOU}/compact.c 
	${COMP} compact.o ${CSOU}/compact.c
	mv compact.o ${OBJ}
	cp ${CSOU}/compact.c ${BCK}

${BINDIR}/swn_ggsc : ${CSOU}/swn_ggsc.c ${OBJ}/compact.o
	${LINK} ${BINDIR}/swn_ggsc ${CSOU}/swn_ggsc.c ${OBJ}/compact.o
	cp ${CSOU}/swn_ggsc.c ${BCK}

${BINDIR}/swn_stndrd : ${CSOU}/swn_stndrd.c ${OBJ}/compact.o
	${LINK} ${BINDIR}/swn_stndrd ${CSOU}/swn_stndrd.c ${OBJ}/compact.o
	cp ${CSOU}/swn_stndrd.c ${BCK}

${BINDIR}/swn_gst_stndrd : ${CSOU}/swn_gst_stndrd.c ${OBJ}/compact.o
	${LINK} ${BINDIR}/swn_gst_stndrd ${CSOU}/swn_gst_stndrd.c ${OBJ}/compact.o
	cp ${CSOU}/swn_gst_stndrd.c ${BCK}

$(BINDIR)/swn_gst_prep : ${CSOU}/gre_stndrd.c ${CSOU}/res_stndrd.lex ${CSOU}/res_stndrd.yacc
	lex ${CSOU}/res_stndrd.lex
	/bin/mv lex.yy.c ${CSOU}/.
	yacc ${CSOU}/res_stndrd.yacc
	${COMP} y.tab.c.o y.tab.c
	$(LINK) $(BINDIR)/swn_gst_prep y.tab.c.o -ll
	/bin/rm -f $CSOU}/lex.yy.c y.tab.c *.o
	cp ${CSOU}/gre_stndrd.c ${BCK}
	cp ${CSOU}/res_stndrd.lex ${BCK}
	cp ${CSOU}/res_stndrd.yacc ${BCK}
