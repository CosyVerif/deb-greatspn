/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     VAR = 259,
     PLUS = 260,
     MINUS = 261,
     TIMES = 262,
     DIV = 263,
     MINOR = 264,
     MAJOR = 265,
     MINOREQ = 266,
     MAJOREQ = 267,
     EQ = 268,
     NEQ = 269,
     OR = 270,
     AND = 271,
     NOT = 272,
     LPARENT = 273,
     RPARENT = 274,
     TRUEv = 275,
     FALSEv = 276,
     LQPARENT = 277,
     RQPARENT = 278,
     DEADLOCK = 279,
     NDEADLOCK = 280,
     ENABLED = 281,
     U = 282,
     F = 283,
     X = 284,
     G = 285,
     A = 286,
     E = 287,
     IMPL = 288
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define VAR 259
#define PLUS 260
#define MINUS 261
#define TIMES 262
#define DIV 263
#define MINOR 264
#define MAJOR 265
#define MINOREQ 266
#define MAJOREQ 267
#define EQ 268
#define NEQ 269
#define OR 270
#define AND 271
#define NOT 272
#define LPARENT 273
#define RPARENT 274
#define TRUEv 275
#define FALSEv 276
#define LQPARENT 277
#define RQPARENT 278
#define DEADLOCK 279
#define NDEADLOCK 280
#define ENABLED 281
#define U 282
#define F 283
#define X 284
#define G 285
#define A 286
#define E 287
#define IMPL 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 44 "SOURCE/CTL/CTLParser.y"

double num;
char var[255];
class Term *term;
class Expression *expr;
class Inequality *ineq;
class AtomicProposition *AP;
class CTLFormula *formula;



/* Line 2068 of yacc.c  */
#line 128 "SOURCE/CTL/CTLParser.hh"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE mmlval;


