/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_SHUFANG_PROJECTS_SERVER_EXP_IJCAI2021_UPLOAD_TOOL_GFSYNTH_BUILD_SRC_LTLF2FOL_LTLPARSER_H_INCLUDED
# define YY_YY_HOME_SHUFANG_PROJECTS_SERVER_EXP_IJCAI2021_UPLOAD_TOOL_GFSYNTH_BUILD_SRC_LTLF2FOL_LTLPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 23 "ltlparser.y"

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

#line 56 "/home/shufang/Projects/Server/EXP/IJCAI2021/upload/tool/Gfsynth/build/src/ltlf2fol/ltlparser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_EQUIV = 258,             /* TOKEN_EQUIV  */
    TOKEN_IMPLIES = 259,           /* TOKEN_IMPLIES  */
    TOKEN_OR = 260,                /* TOKEN_OR  */
    TOKEN_AND = 261,               /* TOKEN_AND  */
    TOKEN_RELEASE = 262,           /* TOKEN_RELEASE  */
    TOKEN_UNTIL = 263,             /* TOKEN_UNTIL  */
    TOKEN_WEAK_UNTIL = 264,        /* TOKEN_WEAK_UNTIL  */
    TOKEN_FUTURE = 265,            /* TOKEN_FUTURE  */
    TOKEN_GLOBALLY = 266,          /* TOKEN_GLOBALLY  */
    TOKEN_NEXT = 267,              /* TOKEN_NEXT  */
    TOKEN_WEAK_NEXT = 268,         /* TOKEN_WEAK_NEXT  */
    TOKEN_NOT = 269,               /* TOKEN_NOT  */
    TOKEN_TRUE = 270,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 271,             /* TOKEN_FALSE  */
    TOKEN_LPAREN = 272,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 273,            /* TOKEN_RPAREN  */
    TOKEN_VARIABLE = 274           /* TOKEN_VARIABLE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "ltlparser.y"

	char* var_name;
	ltl_formula *formula;

#line 97 "/home/shufang/Projects/Server/EXP/IJCAI2021/upload/tool/Gfsynth/build/src/ltlf2fol/ltlparser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (ltl_formula **formula, yyscan_t scanner);

#endif /* !YY_YY_HOME_SHUFANG_PROJECTS_SERVER_EXP_IJCAI2021_UPLOAD_TOOL_GFSYNTH_BUILD_SRC_LTLF2FOL_LTLPARSER_H_INCLUDED  */
