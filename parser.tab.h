/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tVOID = 258,                   /* tVOID  */
    tINT = 259,                    /* tINT  */
    tELSE = 260,                   /* tELSE  */
    tWHILE = 261,                  /* tWHILE  */
    tPRINT = 262,                  /* tPRINT  */
    tRETURN = 263,                 /* tRETURN  */
    tADD = 264,                    /* tADD  */
    tSUB = 265,                    /* tSUB  */
    tMUL = 266,                    /* tMUL  */
    tDIV = 267,                    /* tDIV  */
    tLT = 268,                     /* tLT  */
    tGT = 269,                     /* tGT  */
    tNE = 270,                     /* tNE  */
    tEQ = 271,                     /* tEQ  */
    tGE = 272,                     /* tGE  */
    tLE = 273,                     /* tLE  */
    tASSIGN = 274,                 /* tASSIGN  */
    tAND = 275,                    /* tAND  */
    tOR = 276,                     /* tOR  */
    tNOT = 277,                    /* tNOT  */
    tSEMI = 278,                   /* tSEMI  */
    tCOMMA = 279,                  /* tCOMMA  */
    tLPAR = 280,                   /* tLPAR  */
    tRPAR = 281,                   /* tRPAR  */
    tLBRACE = 282,                 /* tLBRACE  */
    tRBRACE = 283,                 /* tRBRACE  */
    tERROR = 284,                  /* tERROR  */
    tID = 285,                     /* tID  */
    tNB = 286,                     /* tNB  */
    tIF = 287                      /* tIF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"
int nb; char s [40];

#line 99 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);

/* "%code provides" blocks.  */
#line 12 "parser.y"

  int yylex (void);
  void yyerror (const char *);
  

#line 120 "parser.tab.h"

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
