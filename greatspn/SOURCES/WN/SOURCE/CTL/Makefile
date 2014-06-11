#LEX = flex -I
#YACC = byacc

OPTION = -Imeddley -O3 -g3 -Wall -c -fmessage-length=0
CC = cc
CPP = g++

all: CTLParser.cc CTLLexer.cc CTLLexer.o CTLParser
clean: 
	rm CTLLexer.o CTLLexer.cc CTLParser.output CTLLexer.h CTLParser CTLParser.cc

CTLParser: CTLLexer.o CTLParser.cc CTL.h CTL.cpp
	$(CPP) -lmeddly -o CTLParser CTLParser.cc CTLLexer.o CTL.h CTL.cpp

CTLLexer.o: CTLLexer.cc
	$(CPP) -c CTLLexer.cc

CTLParser.cc CTLParser.h: CTLParser.y
	$(YACC) -v -d -o CTLParser.cc CTLParser.y
CTLLexer.cc: CTLLexer.l 
	$(LEX) -+ -o CTLLexer.cc --header-file=CTLLexer.h  CTLLexer.l

