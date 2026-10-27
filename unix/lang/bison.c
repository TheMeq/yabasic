/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2025
    more info at www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#ifdef WINDOWS
#include <malloc.h>
#else
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#endif

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct library *current_library; /* defined in main.c: name of currently parsed library */
extern int yylineno; /* defined in flex */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int loop_nesting=0;
int switch_nesting=0;

static char *ps2_string_arrayref_name(char *name) {
  char *compat_name;

  compat_name = my_malloc(strlen(name) + 2);
  strcpy(compat_name, name);
  strcat(compat_name, "$");
  return compat_name;
}

void report_if_missing(char *text,int eof) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    if (eof) {
       error_without_position(sERROR,text);
    } else {
       error(sERROR,text);
    }
    collect_missing_clauses(string,-1);
    if (string[0]) {
      error_without_position(sERROR,string);
    }
  }
}

void report_conflicting_close(char *text,int missing) {
  error(sERROR,text);
  collect_missing_clauses(string,missing);
  error(sERROR,string);
}

void collect_missing_clauses(char *string, char exclude) {
  char buff[INBUFFLEN];
  
  string[0]='\0';
  if (missing_endif && exclude!='e') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    strcat(string, buff);
  }

  if (missing_next && exclude!='n') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    strcat(string, buff);
  }
}


# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tFNUM = 3,                      /* tFNUM  */
  YYSYMBOL_tSYMBOL = 4,                    /* tSYMBOL  */
  YYSYMBOL_tSTRSYM = 5,                    /* tSTRSYM  */
  YYSYMBOL_tDOCU = 6,                      /* tDOCU  */
  YYSYMBOL_tDIGITS = 7,                    /* tDIGITS  */
  YYSYMBOL_tHEXDIGITS = 8,                 /* tHEXDIGITS  */
  YYSYMBOL_tBINDIGITS = 9,                 /* tBINDIGITS  */
  YYSYMBOL_tSTRING = 10,                   /* tSTRING  */
  YYSYMBOL_tFOR = 11,                      /* tFOR  */
  YYSYMBOL_tTO = 12,                       /* tTO  */
  YYSYMBOL_tSTEP = 13,                     /* tSTEP  */
  YYSYMBOL_tNEXT = 14,                     /* tNEXT  */
  YYSYMBOL_tWHILE = 15,                    /* tWHILE  */
  YYSYMBOL_tWEND = 16,                     /* tWEND  */
  YYSYMBOL_tREPEAT = 17,                   /* tREPEAT  */
  YYSYMBOL_tUNTIL = 18,                    /* tUNTIL  */
  YYSYMBOL_tIMPORT = 19,                   /* tIMPORT  */
  YYSYMBOL_tGOTO = 20,                     /* tGOTO  */
  YYSYMBOL_tGOSUB = 21,                    /* tGOSUB  */
  YYSYMBOL_tLABEL = 22,                    /* tLABEL  */
  YYSYMBOL_tON = 23,                       /* tON  */
  YYSYMBOL_tSUB = 24,                      /* tSUB  */
  YYSYMBOL_tENDSUB = 25,                   /* tENDSUB  */
  YYSYMBOL_tLOCAL = 26,                    /* tLOCAL  */
  YYSYMBOL_tSTATIC = 27,                   /* tSTATIC  */
  YYSYMBOL_tEXPORT = 28,                   /* tEXPORT  */
  YYSYMBOL_tERROR = 29,                    /* tERROR  */
  YYSYMBOL_tEXECUTE = 30,                  /* tEXECUTE  */
  YYSYMBOL_tEXECUTE2 = 31,                 /* tEXECUTE2  */
  YYSYMBOL_tCOMPILE = 32,                  /* tCOMPILE  */
  YYSYMBOL_tRUNTIME_CREATED_SUB = 33,      /* tRUNTIME_CREATED_SUB  */
  YYSYMBOL_tINTERRUPT = 34,                /* tINTERRUPT  */
  YYSYMBOL_tBREAK = 35,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 36,                 /* tCONTINUE  */
  YYSYMBOL_tSWITCH = 37,                   /* tSWITCH  */
  YYSYMBOL_tSEND = 38,                     /* tSEND  */
  YYSYMBOL_tCASE = 39,                     /* tCASE  */
  YYSYMBOL_tDEFAULT = 40,                  /* tDEFAULT  */
  YYSYMBOL_tLOOP = 41,                     /* tLOOP  */
  YYSYMBOL_tDO = 42,                       /* tDO  */
  YYSYMBOL_tSEP = 43,                      /* tSEP  */
  YYSYMBOL_tEOPROG = 44,                   /* tEOPROG  */
  YYSYMBOL_tIF = 45,                       /* tIF  */
  YYSYMBOL_tTHEN = 46,                     /* tTHEN  */
  YYSYMBOL_tELSE = 47,                     /* tELSE  */
  YYSYMBOL_tELSIF = 48,                    /* tELSIF  */
  YYSYMBOL_tENDIF = 49,                    /* tENDIF  */
  YYSYMBOL_tIMPLICITENDIF = 50,            /* tIMPLICITENDIF  */
  YYSYMBOL_tUSING = 51,                    /* tUSING  */
  YYSYMBOL_tPRINT = 52,                    /* tPRINT  */
  YYSYMBOL_tINPUT = 53,                    /* tINPUT  */
  YYSYMBOL_tRETURN = 54,                   /* tRETURN  */
  YYSYMBOL_tDIM = 55,                      /* tDIM  */
  YYSYMBOL_tEND = 56,                      /* tEND  */
  YYSYMBOL_tEXIT = 57,                     /* tEXIT  */
  YYSYMBOL_tAT = 58,                       /* tAT  */
  YYSYMBOL_tSCREEN = 59,                   /* tSCREEN  */
  YYSYMBOL_tREVERSE = 60,                  /* tREVERSE  */
  YYSYMBOL_tCOLOUR = 61,                   /* tCOLOUR  */
  YYSYMBOL_tBACKCOLOUR = 62,               /* tBACKCOLOUR  */
  YYSYMBOL_tAND = 63,                      /* tAND  */
  YYSYMBOL_tOR = 64,                       /* tOR  */
  YYSYMBOL_tNOT = 65,                      /* tNOT  */
  YYSYMBOL_tBITNOT = 66,                   /* tBITNOT  */
  YYSYMBOL_tEOR = 67,                      /* tEOR  */
  YYSYMBOL_tSHL = 68,                      /* tSHL  */
  YYSYMBOL_tSHR = 69,                      /* tSHR  */
  YYSYMBOL_tNEQ = 70,                      /* tNEQ  */
  YYSYMBOL_tLEQ = 71,                      /* tLEQ  */
  YYSYMBOL_tGEQ = 72,                      /* tGEQ  */
  YYSYMBOL_tLTN = 73,                      /* tLTN  */
  YYSYMBOL_tGTN = 74,                      /* tGTN  */
  YYSYMBOL_tEQU = 75,                      /* tEQU  */
  YYSYMBOL_tEQU2 = 76,                     /* tEQU2  */
  YYSYMBOL_tPOW = 77,                      /* tPOW  */
  YYSYMBOL_tREAD = 78,                     /* tREAD  */
  YYSYMBOL_tDATA = 79,                     /* tDATA  */
  YYSYMBOL_tRESTORE = 80,                  /* tRESTORE  */
  YYSYMBOL_tOPEN = 81,                     /* tOPEN  */
  YYSYMBOL_tCLOSE = 82,                    /* tCLOSE  */
  YYSYMBOL_tSEEK = 83,                     /* tSEEK  */
  YYSYMBOL_tTELL = 84,                     /* tTELL  */
  YYSYMBOL_tAS = 85,                       /* tAS  */
  YYSYMBOL_tREADING = 86,                  /* tREADING  */
  YYSYMBOL_tWRITING = 87,                  /* tWRITING  */
  YYSYMBOL_tORIGIN = 88,                   /* tORIGIN  */
  YYSYMBOL_tWINDOW = 89,                   /* tWINDOW  */
  YYSYMBOL_tDOT = 90,                      /* tDOT  */
  YYSYMBOL_tLINE = 91,                     /* tLINE  */
  YYSYMBOL_tCIRCLE = 92,                   /* tCIRCLE  */
  YYSYMBOL_tTRIANGLE = 93,                 /* tTRIANGLE  */
  YYSYMBOL_tTEXT = 94,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 95,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 96,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 97,                  /* tPRINTER  */
  YYSYMBOL_tWAIT = 98,                     /* tWAIT  */
  YYSYMBOL_tBELL = 99,                     /* tBELL  */
  YYSYMBOL_tLET = 100,                     /* tLET  */
  YYSYMBOL_tARDIM = 101,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 102,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 103,                    /* tBIND  */
  YYSYMBOL_tRECT = 104,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 105,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 106,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 107,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 108,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 109,                     /* tNEW  */
  YYSYMBOL_tCURVE = 110,                   /* tCURVE  */
  YYSYMBOL_tSIN = 111,                     /* tSIN  */
  YYSYMBOL_tASIN = 112,                    /* tASIN  */
  YYSYMBOL_tCOS = 113,                     /* tCOS  */
  YYSYMBOL_tACOS = 114,                    /* tACOS  */
  YYSYMBOL_tTAN = 115,                     /* tTAN  */
  YYSYMBOL_tATAN = 116,                    /* tATAN  */
  YYSYMBOL_tEXP = 117,                     /* tEXP  */
  YYSYMBOL_tLOG = 118,                     /* tLOG  */
  YYSYMBOL_tSQRT = 119,                    /* tSQRT  */
  YYSYMBOL_tSQR = 120,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 121,                   /* tMYEOF  */
  YYSYMBOL_tABS = 122,                     /* tABS  */
  YYSYMBOL_tSIG = 123,                     /* tSIG  */
  YYSYMBOL_tINT = 124,                     /* tINT  */
  YYSYMBOL_tCEIL = 125,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 126,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 127,                    /* tFRAC  */
  YYSYMBOL_tROUND = 128,                   /* tROUND  */
  YYSYMBOL_tMOD = 129,                     /* tMOD  */
  YYSYMBOL_tRAN = 130,                     /* tRAN  */
  YYSYMBOL_tVAL = 131,                     /* tVAL  */
  YYSYMBOL_tLEFT = 132,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 133,                   /* tRIGHT  */
  YYSYMBOL_tMID = 134,                     /* tMID  */
  YYSYMBOL_tLEN = 135,                     /* tLEN  */
  YYSYMBOL_tMIN = 136,                     /* tMIN  */
  YYSYMBOL_tMAX = 137,                     /* tMAX  */
  YYSYMBOL_tSTR = 138,                     /* tSTR  */
  YYSYMBOL_tINKEY = 139,                   /* tINKEY  */
  YYSYMBOL_tCHR = 140,                     /* tCHR  */
  YYSYMBOL_tASC = 141,                     /* tASC  */
  YYSYMBOL_tHEX = 142,                     /* tHEX  */
  YYSYMBOL_tDEC = 143,                     /* tDEC  */
  YYSYMBOL_tBIN = 144,                     /* tBIN  */
  YYSYMBOL_tUPPER = 145,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 146,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 147,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 148,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 149,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 150,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 151,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 152,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 153,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 154,                 /* tSTRING2  */
  YYSYMBOL_tINSTR = 155,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 156,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 157,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 158,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 159,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 160,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 161,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 162,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 163,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 164,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 165,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 166,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 167,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 168,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 169,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 170,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 171,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 172,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 173,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 174,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 175,                    /* tDATE  */
  YYSYMBOL_tTIME = 176,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 177,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 178,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 179,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 180,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 181,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 182,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 183,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 184, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 185,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 186, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 187,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 188,                   /* tEVAL2  */
  YYSYMBOL_189_ = 189,                     /* '-'  */
  YYSYMBOL_190_ = 190,                     /* '+'  */
  YYSYMBOL_191_ = 191,                     /* '*'  */
  YYSYMBOL_192_ = 192,                     /* '/'  */
  YYSYMBOL_UMINUS = 193,                   /* UMINUS  */
  YYSYMBOL_194_ = 194,                     /* ';'  */
  YYSYMBOL_195_ = 195,                     /* ','  */
  YYSYMBOL_196_ = 196,                     /* '('  */
  YYSYMBOL_197_ = 197,                     /* ')'  */
  YYSYMBOL_198_ = 198,                     /* '#'  */
  YYSYMBOL_tGTRIANGLE = 199,               /* tGTRIANGLE  */
  YYSYMBOL_tSETRGB = 200,                  /* tSETRGB  */
  YYSYMBOL_tSETDRAWBUF = 201,              /* tSETDRAWBUF  */
  YYSYMBOL_tSETDISPBUF = 202,              /* tSETDISPBUF  */
  YYSYMBOL_YYACCEPT = 203,                 /* $accept  */
  YYSYMBOL_program_or_expression = 204,    /* program_or_expression  */
  YYSYMBOL_program = 205,                  /* program  */
  YYSYMBOL_statement_list = 206,           /* statement_list  */
  YYSYMBOL_207_1 = 207,                    /* $@1  */
  YYSYMBOL_208_2 = 208,                    /* $@2  */
  YYSYMBOL_assignment = 209,               /* assignment  */
  YYSYMBOL_statement = 210,                /* statement  */
  YYSYMBOL_211_3 = 211,                    /* $@3  */
  YYSYMBOL_212_4 = 212,                    /* $@4  */
  YYSYMBOL_213_5 = 213,                    /* $@5  */
  YYSYMBOL_214_6 = 214,                    /* $@6  */
  YYSYMBOL_215_7 = 215,                    /* $@7  */
  YYSYMBOL_216_8 = 216,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 217,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 218,        /* string_assignment  */
  YYSYMBOL_to = 219,                       /* to  */
  YYSYMBOL_open_clause = 220,              /* open_clause  */
  YYSYMBOL_seek_clause = 221,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 222,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 223,        /* string_expression  */
  YYSYMBOL_string_function = 224,          /* string_function  */
  YYSYMBOL_number_assignment = 225,        /* number_assignment  */
  YYSYMBOL_expression = 226,               /* expression  */
  YYSYMBOL_227_9 = 227,                    /* $@9  */
  YYSYMBOL_228_10 = 228,                   /* $@10  */
  YYSYMBOL_arrayref = 229,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 230,          /* string_arrayref  */
  YYSYMBOL_coordinates = 231,              /* coordinates  */
  YYSYMBOL_function = 232,                 /* function  */
  YYSYMBOL_const = 233,                    /* const  */
  YYSYMBOL_number = 234,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 235,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 236,                  /* dimlist  */
  YYSYMBOL_function_or_array = 237,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 238,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 239,                /* call_list  */
  YYSYMBOL_240_11 = 240,                   /* $@11  */
  YYSYMBOL_calls = 241,                    /* calls  */
  YYSYMBOL_call_item = 242,                /* call_item  */
  YYSYMBOL_function_definition = 243,      /* function_definition  */
  YYSYMBOL_244_12 = 244,                   /* $@12  */
  YYSYMBOL_245_13 = 245,                   /* $@13  */
  YYSYMBOL_246_14 = 246,                   /* $@14  */
  YYSYMBOL_endsub = 247,                   /* endsub  */
  YYSYMBOL_function_name = 248,            /* function_name  */
  YYSYMBOL_export = 249,                   /* export  */
  YYSYMBOL_local_list = 250,               /* local_list  */
  YYSYMBOL_local_item = 251,               /* local_item  */
  YYSYMBOL_static_list = 252,              /* static_list  */
  YYSYMBOL_static_item = 253,              /* static_item  */
  YYSYMBOL_paramlist = 254,                /* paramlist  */
  YYSYMBOL_paramitem = 255,                /* paramitem  */
  YYSYMBOL_for_loop = 256,                 /* for_loop  */
  YYSYMBOL_257_15 = 257,                   /* $@15  */
  YYSYMBOL_258_16 = 258,                   /* $@16  */
  YYSYMBOL_259_17 = 259,                   /* $@17  */
  YYSYMBOL_260_18 = 260,                   /* $@18  */
  YYSYMBOL_next = 261,                     /* next  */
  YYSYMBOL_step_part = 262,                /* step_part  */
  YYSYMBOL_next_symbol = 263,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 264,  /* switch_number_or_string  */
  YYSYMBOL_265_19 = 265,                   /* $@19  */
  YYSYMBOL_sep_list = 266,                 /* sep_list  */
  YYSYMBOL_number_or_string = 267,         /* number_or_string  */
  YYSYMBOL_case_list = 268,                /* case_list  */
  YYSYMBOL_269_20 = 269,                   /* $@20  */
  YYSYMBOL_default = 270,                  /* default  */
  YYSYMBOL_271_21 = 271,                   /* $@21  */
  YYSYMBOL_do_loop = 272,                  /* do_loop  */
  YYSYMBOL_273_22 = 273,                   /* $@22  */
  YYSYMBOL_loop = 274,                     /* loop  */
  YYSYMBOL_while_loop = 275,               /* while_loop  */
  YYSYMBOL_276_23 = 276,                   /* $@23  */
  YYSYMBOL_277_24 = 277,                   /* $@24  */
  YYSYMBOL_wend = 278,                     /* wend  */
  YYSYMBOL_repeat_loop = 279,              /* repeat_loop  */
  YYSYMBOL_280_25 = 280,                   /* $@25  */
  YYSYMBOL_until = 281,                    /* until  */
  YYSYMBOL_if_clause = 282,                /* if_clause  */
  YYSYMBOL_283_26 = 283,                   /* $@26  */
  YYSYMBOL_284_27 = 284,                   /* $@27  */
  YYSYMBOL_285_28 = 285,                   /* $@28  */
  YYSYMBOL_286_29 = 286,                   /* $@29  */
  YYSYMBOL_endif = 287,                    /* endif  */
  YYSYMBOL_short_if = 288,                 /* short_if  */
  YYSYMBOL_289_30 = 289,                   /* $@30  */
  YYSYMBOL_end_of_if = 290,                /* end_of_if  */
  YYSYMBOL_else_part = 291,                /* else_part  */
  YYSYMBOL_elsif_part = 292,               /* elsif_part  */
  YYSYMBOL_293_31 = 293,                   /* $@31  */
  YYSYMBOL_294_32 = 294,                   /* $@32  */
  YYSYMBOL_maybe_then = 295,               /* maybe_then  */
  YYSYMBOL_inputlist = 296,                /* inputlist  */
  YYSYMBOL_297_33 = 297,                   /* $@33  */
  YYSYMBOL_input = 298,                    /* input  */
  YYSYMBOL_readlist = 299,                 /* readlist  */
  YYSYMBOL_readitem = 300,                 /* readitem  */
  YYSYMBOL_datalist = 301,                 /* datalist  */
  YYSYMBOL_printlist = 302,                /* printlist  */
  YYSYMBOL_using = 303,                    /* using  */
  YYSYMBOL_inputbody = 304,                /* inputbody  */
  YYSYMBOL_305_34 = 305,                   /* $@34  */
  YYSYMBOL_306_35 = 306,                   /* $@35  */
  YYSYMBOL_307_36 = 307,                   /* $@36  */
  YYSYMBOL_308_37 = 308,                   /* $@37  */
  YYSYMBOL_309_38 = 309,                   /* $@38  */
  YYSYMBOL_310_39 = 310,                   /* $@39  */
  YYSYMBOL_311_40 = 311,                   /* $@40  */
  YYSYMBOL_312_41 = 312,                   /* $@41  */
  YYSYMBOL_313_42 = 313,                   /* $@42  */
  YYSYMBOL_314_43 = 314,                   /* $@43  */
  YYSYMBOL_315_44 = 315,                   /* $@44  */
  YYSYMBOL_316_45 = 316,                   /* $@45  */
  YYSYMBOL_317_46 = 317,                   /* $@46  */
  YYSYMBOL_prompt = 318,                   /* prompt  */
  YYSYMBOL_printintro = 319,               /* printintro  */
  YYSYMBOL_hashed_number = 320,            /* hashed_number  */
  YYSYMBOL_goto_list = 321,                /* goto_list  */
  YYSYMBOL_gosub_list = 322                /* gosub_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */

void
yyerror(char *message) {
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
  error(severity,message);
}


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  197
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6911

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  203
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  501
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   448


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   198,     2,     2,     2,     2,
     196,   197,   191,   190,   195,   189,     2,   192,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   194,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   193,   199,   200,   201,   202
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   207,   208,   209,   210,   213,   216,   217,
     217,   217,   220,   221,   222,   223,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   241,   242,   242,   243,   244,   245,   246,   247,
     248,   249,   249,   251,   251,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   263,   264,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   281,   282,
     283,   284,   285,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   336,   337,
     338,   339,   340,   344,   345,   346,   347,   348,   349,   352,
     353,   356,   357,   358,   359,   360,   363,   364,   367,   368,
     371,   372,   373,   374,   375,   376,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   423,   424,
     427,   427,   428,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   463,   466,   469,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     545,   546,   547,   550,   551,   552,   553,   556,   557,   560,
     561,   562,   563,   566,   569,   572,   572,   575,   576,   577,
     580,   581,   584,   585,   588,   584,   593,   594,   597,   598,
     601,   602,   603,   604,   607,   608,   611,   612,   613,   614,
     617,   618,   621,   622,   623,   624,   627,   628,   629,   632,
     633,   634,   635,   638,   639,   644,   659,   638,   664,   665,
     666,   667,   668,   669,   672,   673,   676,   677,   682,   682,
     686,   687,   690,   691,   695,   697,   696,   701,   702,   702,
     706,   706,   712,   713,   714,   715,   716,   717,   721,   722,
     721,   728,   729,   733,   733,   738,   739,   740,   741,   742,
     743,   746,   747,   747,   749,   746,   753,   754,   755,   756,
     757,   758,   761,   761,   766,   767,   770,   771,   774,   776,
     778,   775,   782,   783,   786,   787,   787,   790,   791,   793,
     794,   798,   799,   802,   803,   805,   806,   810,   811,   812,
     813,   816,   817,   818,   819,   820,   823,   824,   825,   828,
     828,   829,   829,   830,   830,   831,   831,   832,   832,   833,
     833,   834,   834,   835,   835,   836,   836,   837,   837,   838,
     838,   839,   839,   840,   840,   843,   844,   847,   848,   849,
     850,   851,   852,   853,   854,   855,   856,   857,   858,   859,
     860,   863,   864,   866,   867,   870,   871,   876,   877,   878,
     879,   883
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tFNUM", "tSYMBOL",
  "tSTRSYM", "tDOCU", "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING",
  "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL",
  "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB",
  "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2",
  "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE",
  "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP",
  "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF",
  "tUSING", "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT",
  "tSCREEN", "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT",
  "tBITNOT", "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN",
  "tGTN", "tEQU", "tEQU2", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN",
  "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN",
  "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR",
  "tFILL", "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE",
  "tBIND", "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW",
  "tCURVE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL",
  "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT",
  "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX",
  "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB",
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tINSTR",
  "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE",
  "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
  "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET",
  "tFRNBF_GET2", "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE",
  "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "tSTART_PROGRAM", "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION",
  "tSTART_ASSIGNMENT", "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'",
  "tGTRIANGLE", "tSETRGB", "tSETDRAWBUF", "tSETDISPBUF", "$accept",
  "program_or_expression", "program", "statement_list", "$@1", "$@2",
  "assignment", "statement", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@9", "$@10",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@11", "calls", "call_item",
  "function_definition", "$@12", "$@13", "$@14", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@15", "$@16", "$@17", "$@18",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@19",
  "sep_list", "number_or_string", "case_list", "$@20", "default", "$@21",
  "do_loop", "$@22", "loop", "while_loop", "$@23", "$@24", "wend",
  "repeat_loop", "$@25", "until", "if_clause", "$@26", "$@27", "$@28",
  "$@29", "endif", "short_if", "$@30", "end_of_if", "else_part",
  "elsif_part", "$@31", "$@32", "maybe_then", "inputlist", "$@33", "input",
  "readlist", "readitem", "datalist", "printlist", "using", "inputbody",
  "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42",
  "$@43", "$@44", "$@45", "$@46", "prompt", "printintro", "hashed_number",
  "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-787)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-402)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     726,  1532,  3974,  2701,    97,    52,     8,   -54,   -19,  -787,
    -787,  -787,  -787,  -787,    40,    40,    40,  3594,  -787,  -787,
    -787,  2701,  -787,  -787,  2701,    22,    31,  -787,  -787,  -787,
    3974,   -31,  -787,  3974,    58,  -787,  3974,  3974,  3974,   293,
      45,    40,  2231,  2035,  2623,     6,  3974,  3404,  3974,   117,
      11,  3974,  -787,    18,  2701,  2701,  2701,   -28,   -30,    -1,
       4,    36,    74,  2623,  2701,  2701,  2701,  3974,  3974,  3974,
    3974,  -787,   100,  -787,  -787,   -33,  -787,  -787,  -787,  -787,
      39,   110,  -787,   223,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,   145,   155,  -787,  -787,  -787,  -787,   202,   251,
     261,   263,  3974,   289,   291,   311,   315,   335,   347,   360,
     385,   391,   401,   404,   412,   416,   425,   431,   449,   457,
     469,   492,   513,   515,   517,   527,   538,   552,   556,   584,
     601,   609,   613,   627,   635,   637,   647,   649,   657,   668,
     670,   675,   681,   686,   687,   689,   690,   698,   699,   700,
     703,   704,   705,   707,   717,   721,   724,   731,   732,   734,
     735,   740,   744,   747,   748,   749,   753,   754,   756,   757,
     762,   763,   767,   772,   773,   777,   778,   779,   781,   790,
     792,   793,  3974,  3974,   684,  -787,   442,  -787,  -787,  -787,
    -787,  2701,   -26,   168,    39,   110,   235,  -787,  3974,  -787,
    2701,  -787,   310,  3974,  1296,  -787,  -787,  -787,  -787,  -787,
     329,    63,   372,   504,    77,  -787,  3974,  -787,    77,  -787,
    -787,  3974,  1296,   488,   794,   361,   795,     3,  3974,   -15,
     684,  6719,   796,   797,   288,  6719,   684,  5589,   684,  5604,
     798,   799,   440,  -787,  -787,   195,   195,  -787,  -787,   505,
    -787,  3974,  2701,  3974,    46,  6719,   664,  -787,  -787,  -787,
    -787,   685,  2701,  5619,  -787,  3974,  -787,    -9,   727,  -787,
    -787,  3974,  3784,  -787,  -787,  6719,  -787,  -787,    77,    -8,
      -8,  -787,   924,   924,   924,  2819,  2701,   420,   802,    77,
    -109,   -67,    -9,  5634,  6719,  6719,  -787,   944,  3974,  3974,
    3974,  3974,  2701,  -787,  -787,  -787,  3974,  3974,  1191,  3974,
    3974,  3974,  3974,  2427,  2623,   516,   516,  3974,  3974,  3974,
    3974,  3974,  3974,  3974,  3974,  3974,  3974,  3974,  3974,  2623,
    3974,  3974,  3974,  3974,  3974,  3974,  3974,  3974,  3014,  2701,
    2701,  2701,  2701,  2701,  3974,  3974,  3974,  3209,  3974,  2701,
    3974,  2701,  3974,  2701,  2701,   450,  1638,  2309,  2505,  2701,
    2701,  2701,  3974,  2701,  2701,  2701,  2701,  2701,  2623,  2701,
    -787,  -787,  2701,  3974,  2701,  2701,  2701,  2701,  2701,   803,
     804,  2701,   924,  2701,   924,  2701,  2701,  2701,   921,   452,
    1528,  2701,  2701,  2701,  2701,  2701,  2701,  2701,  2701,  -787,
    -787,  -787,  3974,  3974,  3974,  3974,  3974,  3974,  3974,  3974,
    3974,  3974,  3974,  3974,  -158,  -787,  -787,  -787,  6719,   806,
      77,   811,   934,  6719,   658,  -787,  -787,  -787,  -787,   818,
     819,   821,  -787,   822,   823,   825,  -787,   684,  6719,   826,
    -787,   684,  6719,   956,   696,   965,  1296,  3974,   827,  2701,
    -787,  -787,  3974,   684,   743,   359,   828,   955,   829,     9,
    -787,  1012,  -787,  -787,   564,  3974,  3974,  -787,  -787,   293,
    -787,  -787,    67,  5764,    77,  6719,   485,  2896,  3974,    77,
    3974,  -787,   -15,  -787,  -787,  3974,  2701,  -787,  3974,    -9,
    3974,  3974,   830,   833,   834,   837,  -787,  1799,   -85,  3974,
    3974,  3974,  3974,  3974,  3974,  -787,   838,    -9,    -9,  6719,
      77,   663,   839,   841,  5779,  5794,  1816,  5809,  5824,  5839,
     842,   396,   840,   844,   846,   848,   849,   850,   853,   854,
      -9,  5854,  3420,  3609,  3799,  3989,  4119,   765,  4134,   908,
    4149,  4164,   855,  4179,  4194,  4209,  4224,  4354,  4369,  4384,
    5869,  -787,  4399,   -66,    -6,    38,    55,   -65,  5999,  6014,
     474,   998,  -787,  4414,  4429,   -49,  4444,   -99,  4459,    68,
      71,  -787,    95,  -787,   159,  -787,   162,  -787,   165,   171,
     199,   241,  6029,    86,   105,   242,   256,   268,   586,   856,
     -98,   857,   858,   283,  4589,   285,   -86,   239,   253,   266,
    -787,  -787,   284,   -52,   340,   -32,   453,   287,   313,  -787,
    -787,    77,    77,    77,    77,    77,    77,    77,  -787,  3974,
    3974,   610,   815,   775,   148,   226,     2,    26,  -787,   -13,
     -13,   921,   921,  -787,  -787,  -787,  1296,  -787,  -787,  3974,
    -787,  -787,  -787,  -787,    40,    40,  -787,  -787,   372,  -787,
    -787,   504,  3974,  -787,   991,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,   714,  6044,  3974,   -82,  4604,  3286,  -787,
    -787,  3974,  3974,   863,  2701,  -787,  -787,  3974,  -787,   791,
     859,   866,   868,   869,  6059,  6074,   870,   880,  -787,  -787,
    -787,  3974,   960,   994,  -787,   543,  6089,  6719,  -787,  -787,
     572,  -787,  3974,  6104,  6234,  -787,  3974,  3974,  3974,  -787,
    -787,   684,  6719,   684,  6719,  6249,  6264,    -9,  6279,  1296,
    3974,  3974,  3974,  -787,  -787,  -787,  -787,  -787,  3974,  3974,
    -787,  3974,  3974,  3974,  -787,  2701,  -787,  3091,  -787,   883,
     885,  -787,  -787,  3974,  3974,  3974,  3974,  -787,  -787,  -787,
    -787,  -787,  3974,  -787,  -787,  3974,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  3974,  -787,  -787,
    3974,  3974,  3974,  -787,  3974,  3974,  -787,  2701,  -787,  -787,
    -787,  -787,  -787,  3974,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  2701,  2701,  2701,  -787,  -787,
    -787,  -787,  -787,  2701,  -787,  -787,  -787,  -787,  -787,  -787,
    3974,  -787,  3974,  3974,  3974,   817,  2701,  -787,   817,  2701,
    -787,  2701,  -787,  -787,  1191,   503,  3974,    21,  6719,  -787,
     890,  -787,   891,   893,   894,  -787,   895,   896,  -787,  -787,
    -787,   786,  1296,  -787,  -787,  -787,  3974,  6294,  2701,   992,
    -787,  2701,    77,   684,   743,  6309,  3974,    47,   791,   791,
    4619,   900,   905,  -787,   892,  -787,  -787,  -787,  -787,  3974,
    3974,  -787,  -787,  6324,  2623,  2623,  2701,  2701,  2701,  -787,
    3974,  3974,   907,  4634,  4649,  1217,  2701,  2701,  3974,  3974,
    -787,  6719,    -9,  -787,   906,  4664,  4679,  4694,  4824,  4839,
     339,   909,    51,  -787,  -787,  4854,  4869,   910,    83,  4884,
    4899,  4914,  4929,  5059,  1291,  5074,  5089,    69,  5104,   408,
      87,    96,   409,  5119,  6339,  6469,  5134,   913,    99,   423,
     118,   439,   454,    98,  -787,  -787,  -787,    40,    40,  -787,
    -787,  -787,  -787,  3974,  1067,  1073,  1070,  5149,  3974,   476,
     918,   188,  -787,  3974,  6484,  2701,  1057,  -787,  -787,  -787,
    -787,  -787,  -787,   919,   922,  6719,  6719,  2701,  -787,  -787,
      77,    77,   576,  6499,  6719,  -787,  1043,  1045,  3974,  1046,
     603,    77,  -787,  6514,  3974,   851,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  2701,  -787,  -787,  -787,  -787,  3974,  -787,
    -787,  -787,  -787,  -787,  3974,  -787,  -787,  -787,  2701,  -787,
    -787,  -787,  3974,  -787,  3974,  -787,  -787,  -787,  2701,  3974,
    -787,   926,  2701,  -787,  -787,  2701,  -787,  -787,  -787,  3974,
    -787,  -787,  -787,  -787,  -787,  1076,   801,  5164,  1069,  3974,
    2701,  5294,  3974,   500,   932,  1012,   791,   933,   935,   791,
    -787,  -787,    77,  2701,  2701,  2701,  2701,  5309,  2701,  3974,
    3974,  -787,   937,   938,   200,  -787,   501,  6529,  5324,   506,
    5339,  5354,   511,  5369,  -787,   525,   531,   350,  1296,  1921,
    3974,  1084,  -787,   939,  -787,   940,  6544,   535,   809,  5384,
    1079,  3974,   791,  -787,  -787,  -787,  -787,    77,    77,    77,
      77,  1063,    77,  6719,  6719,   942,   945,   851,  -787,  -787,
    3974,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  3974,
    -787,  1070,  1103,   715,  1296,  -787,  2701,  3974,  3974,  -787,
    -787,   947,  1012,  -787,   948,  1012,  6559,  -787,  2701,  -787,
    -787,  -787,  1296,  5399,  6719,  1296,  -787,  -787,  1070,   733,
     189,  6574,  5529,  1012,  2701,   791,  1012,  3974,   791,  3974,
      77,   -11,  -787,  1070,  1296,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  2701,  -787,  3974,  -787,   791,   197,  -787,   791,
    6704,  -787,  5544,  -787,  -787,  -787,   816,  1070,   546,  5559,
    -787,  2701,  -787,  -787,  3974,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  1141,  1076,  -787,  -787,   549,  1012,  5574,  1012,
    -787,  -787,  -787,  -787,   791,  -787,   791,  1012,  -787,  1012,
    -787,   791,   791,  -787,  -787
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   118,     0,     0,     0,   330,     0,     0,     0,   112,
     353,   388,   393,    18,     0,     0,     0,     0,    31,    33,
     331,     0,   315,   315,     0,   332,    25,    27,   368,   380,
       0,   477,    55,    67,     0,   109,   110,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   119,
     120,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     9,    17,     8,     0,    12,    46,    48,    14,
      29,    30,    28,     0,    20,    21,    24,    23,    22,    35,
      36,   303,   210,   140,   304,   305,   306,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,   270,
     273,   276,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,   224,   204,   209,
     142,     0,     0,     0,     0,     0,     0,     1,     0,   315,
       0,   315,     0,     0,    16,   308,   307,    37,    38,    45,
       0,     0,     0,     0,    19,    50,   317,    51,    49,   333,
      26,     0,    16,   412,     0,   481,     0,     0,   441,   473,
      69,    68,     0,     0,    70,   111,    60,     0,    62,     0,
     433,   435,    63,   431,   437,     0,     0,   438,   300,    64,
      66,     0,    96,     0,     0,   492,     0,    93,    98,    86,
      47,     0,     0,     0,    74,     0,    57,    79,     0,    95,
      94,     0,     0,   121,   122,    99,    13,    15,   113,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,   498,   499,     7,     0,     0,     0,
       0,     0,     0,   322,   315,   315,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,   315,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
     192,   190,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,   188,     0,
     123,     0,     0,   389,     9,    39,    40,    41,    43,   336,
     337,    32,   334,   342,   343,    34,   340,   320,   321,   316,
     318,   373,   372,     0,     9,     0,    16,     0,     0,     0,
     478,   479,     0,   444,   446,    52,     0,     0,     0,     0,
      56,   475,   315,   315,     0,     0,     0,   315,   315,     0,
     302,   301,     0,     0,    97,   491,     0,     0,     0,    73,
       0,    78,   473,   130,   129,     0,     0,    75,     0,    81,
       0,     0,   138,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,   189,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,   271,     0,   274,     0,   277,     0,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     171,   173,     0,     0,     0,     0,     0,     0,     0,   145,
     225,   219,   221,   223,   220,   222,   217,   218,   144,     0,
       0,   197,   199,   201,   198,   200,   195,   196,   215,   212,
     211,   213,   214,   313,   314,   354,    16,   400,   398,     0,
     399,   395,   397,   394,     0,     0,   315,   315,     0,   315,
     315,     0,     0,   370,   374,   387,   385,   386,   383,   382,
     384,   381,   402,     9,     0,     0,     0,     0,     0,   442,
      53,    54,     0,     0,     0,   449,   451,     0,   476,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   432,   439,
     440,     0,     0,     0,   133,   132,   136,   228,    58,    76,
      89,    80,     0,     0,     0,   315,     0,     0,     0,   103,
     104,   105,   106,   107,   108,     0,     0,     0,     0,    16,
       0,     0,     0,   328,   329,   323,   292,   184,     0,     0,
     283,     0,     0,     0,   293,     0,   294,     0,   287,     0,
       0,   205,   206,     0,     0,     0,     0,   229,   230,   231,
     232,   233,     0,   234,   236,     0,   237,   239,   240,   202,
     246,   247,   241,   243,   244,   245,   242,     0,   249,   254,
       0,     0,     0,   253,     0,     0,   153,     0,   150,   156,
     157,   255,   182,     0,   256,   183,   158,   159,   269,   272,
     275,   278,   162,   160,   161,     0,     0,     0,   164,   262,
     165,   268,   267,     0,   174,   263,   166,   264,   167,   266,
       0,   168,     0,     0,     0,     0,     0,   177,     0,     0,
     179,     0,   299,   187,   193,   191,     0,     9,   396,   493,
      42,   495,    44,     0,     0,   335,     0,     0,   341,   319,
     371,   377,    16,   414,   415,   413,     0,     0,     0,   482,
     480,     0,   447,   445,   446,     0,     0,     0,     0,     0,
       0,   427,   429,   474,   424,   309,   311,   315,   315,     0,
       0,   434,   436,    71,     0,     0,     0,     0,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    87,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   392,   391,   390,     0,     0,   338,
     339,   344,   345,     0,     0,     0,   403,     0,     0,     0,
       0,     0,   443,     0,     0,     0,   463,   450,   452,   453,
     315,   315,   425,     0,     0,    59,    61,     0,   134,   135,
     131,   137,    90,    83,    84,   139,     0,     0,     0,     0,
     116,   117,   500,     0,     0,   346,   281,   282,   284,   285,
     286,   295,   296,     0,   297,   207,   208,   180,     0,   235,
     238,   248,   146,   147,     0,   149,   251,   252,     0,   151,
     257,   163,     0,   258,     0,   260,   175,   169,     0,     0,
     186,     0,     0,   289,   176,     0,   291,   178,   203,     0,
     494,   496,   375,   378,   369,   418,   484,     0,   483,     0,
       0,     0,     0,     0,     0,   475,     0,     0,     0,     0,
     310,   312,    72,     0,     0,     0,     0,     0,     0,     0,
       0,    88,   349,   350,     0,   347,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,   364,    16,   118,
       0,   416,   488,     0,   485,     0,     0,     0,   455,     0,
     465,     0,     0,   454,   428,   430,   426,    91,    82,   126,
     127,     0,   125,   115,   497,     0,     0,     0,   324,   298,
       0,   148,   152,   259,   261,   265,   185,   288,   290,     0,
     355,   376,     9,   422,    16,   404,     0,     0,     0,   448,
     467,     0,   475,   457,     0,   475,     0,   464,     0,   351,
     352,   348,    16,     0,   365,    16,   423,   419,   417,     0,
       0,     0,     0,   475,     0,     0,   475,     0,     0,     0,
     124,     9,   181,   356,    16,   411,   408,   409,   410,   406,
     407,   405,     0,   489,     0,   486,     0,     0,   456,     0,
       0,   466,     0,   327,   326,   325,     0,   420,     0,     0,
     468,     0,   469,   458,     0,   459,   359,   361,   362,   363,
     358,   360,   366,   418,   490,   487,     0,   475,     0,   475,
     367,   357,   421,   471,     0,   461,     0,   475,   470,   475,
     460,     0,     0,   472,   462
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -787,  -787,  -787,  -203,  -787,  -787,  1144,   430,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  1098,  -268,  -787,  -787,  -194,
     860,  -787,  1099,    -2,  -787,  -787,   843,  -314,    82,  -787,
     682,   -35,    10,  -787,     5,    16,    70,  -787,  -787,   508,
    1148,  -787,  -787,  -787,  -787,  -787,  -787,  -787,   518,  -787,
     512,  -787,    49,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,   221,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,   -38,
    -787,  -787,  -787,  -786,  -787,  -787,  -787,   701,  -787,  -787,
     314,   692,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -765,  -787,    44,  -787,  -787
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    71,    72,   297,   719,    73,    74,   212,   213,
     644,   645,   229,   482,    75,    76,   485,    77,    78,   493,
     184,   185,    79,   263,   620,   619,   526,   527,   264,   187,
     247,   188,   207,   234,   189,   190,   215,   216,   439,   440,
      82,   511,   894,  1142,  1185,   725,    83,   431,   432,   435,
     436,  1064,  1065,    84,   202,   826,  1145,  1186,  1202,  1120,
    1211,    85,   221,   654,   443,   841,  1078,   945,  1079,    86,
     222,   661,    87,   203,   636,   936,    88,   204,   643,    89,
     445,   842,  1035,  1149,  1171,    90,   446,   845,  1125,  1081,
    1164,  1203,  1147,   863,  1049,   864,   242,   243,   249,   455,
     669,   460,   858,   859,  1046,  1132,  1156,  1209,  1219,  1045,
    1135,  1153,  1207,  1217,   461,   679,   228,   256,   830,   832
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     186,   424,   529,   483,   483,   248,    80,   450,   197,   194,
     451,   490,   491,   675,  1183,   211,   676,    81,   415,   444,
     195,   198,     7,     8,   503,   208,   209,   224,   223,   225,
     226,   231,   398,  1184,   235,   237,   239,   934,   220,   609,
     255,   255,   255,   456,   205,   457,   458,   206,    91,   275,
     219,   250,    94,    95,    96,   244,   200,   476,   194,   298,
     299,   255,   232,   233,   409,   935,   293,   294,   295,   195,
      91,   300,   957,   958,    94,    95,    96,   689,   408,   409,
      20,   398,   281,   427,   428,    25,   501,   260,   261,   494,
     495,   398,   398,   217,   262,   483,   783,   803,   784,   804,
     308,     7,     8,   409,   398,   398,   274,   288,   398,   810,
    1029,   811,   710,   848,   301,   849,   391,   392,   393,   394,
     395,   396,   397,   398,   398,   398,   400,   401,   502,   267,
     268,   769,   773,   402,   403,   404,   405,   406,   407,   408,
     409,   398,   199,   816,   296,   817,   400,   401,   781,   292,
      58,    59,    60,   402,   403,   404,   405,   406,   407,   408,
     409,   400,   401,   819,   398,   820,   282,   227,   402,   403,
     404,   405,   406,   407,   408,   409,   269,   201,   412,   413,
     388,   390,   398,   459,   398,   302,   484,   484,   603,   770,
     605,   410,   411,   412,   413,   283,   418,    53,    91,   452,
     284,   423,    94,    95,    96,   677,   270,   271,   272,    80,
     470,   471,   416,   273,   438,   410,   411,   412,   413,   442,
      81,   702,   406,   407,   408,   409,   454,    80,   398,    58,
      59,    60,   285,   771,   245,   246,   398,   398,    81,   721,
     722,   398,   955,   663,   956,   398,   993,   303,   994,   473,
     772,   475,   410,   411,   412,   413,   245,   246,   398,   398,
    1093,   398,   745,  1096,  1008,   786,  1009,   398,   787,   419,
     286,   421,   410,   411,   412,   413,   398,   398,   484,   417,
    1092,   796,  1012,   497,  1013,   398,   398,   410,   411,   412,
     413,  1014,   788,  1015,  1022,   398,  1023,   240,   241,   509,
     797,   407,   408,   409,   514,   515,  1137,   516,   517,   518,
     519,   255,   255,  1025,   422,  1026,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   255,   543,   544,
     545,   546,   547,   548,   549,   550,   552,   410,   411,   412,
     413,   199,   558,   559,   561,   563,   564,   481,   566,   398,
     568,   201,   398,   487,   489,   398,   789,   522,   523,   790,
     582,   398,   791,  1119,   425,   426,   255,  1155,   792,  1178,
    1158,   594,  1181,   542,   512,   513,   429,   430,   398,   398,
     506,   507,   508,  1040,  1172,   609,  1173,   398,  1176,   398,
    1190,  1179,  1191,  1193,  1192,  1107,   793,  1108,   304,   530,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   589,   400,   401,   410,   411,   412,   413,   448,
     402,   403,   404,   405,   406,   407,   408,   409,  1218,   398,
    1220,   398,   398,   827,   812,  1223,  1224,   248,   794,   798,
     591,   592,  1214,   398,  1216,   664,   398,   305,   813,   888,
     667,    80,  1221,   799,  1222,    93,   398,   306,   398,   307,
      97,   814,    81,   684,   685,   800,   391,   392,   393,   394,
     395,   396,   397,   398,   398,   398,   696,   398,   697,   815,
     807,    99,   809,   464,   822,   309,   399,   310,   703,   704,
     391,   392,   393,   394,   395,   396,   397,   712,   714,   715,
     716,   928,   718,   398,   930,   400,   401,   311,   433,   434,
     823,   312,   402,   403,   404,   405,   406,   407,   408,   409,
     524,   525,   391,   392,   393,   394,   395,   396,   397,   398,
     398,   313,   680,   681,  -401,   818,   991,   686,   687,   410,
     411,   412,   413,   314,   391,   392,   393,   394,   395,   396,
     397,   400,   401,   670,   671,   111,   315,   112,   402,   403,
     404,   405,   406,   407,   408,   409,   400,   699,   682,   683,
     701,   692,   693,   402,   403,   404,   405,   406,   407,   408,
     409,   316,   134,   135,   136,   717,   398,   317,   140,   141,
     142,   735,   144,   736,   146,   147,   148,   318,   398,   398,
     319,   153,   154,   155,   156,  1011,  1016,   159,   320,   161,
     398,   163,   321,   398,   165,   499,   167,   824,   825,   169,
    1024,   322,   171,   172,   984,   173,   174,   323,   176,   398,
     178,   410,   411,   412,   413,   469,  1027,   828,   181,   946,
     998,    80,   398,   398,   398,   324,   191,   571,   821,   609,
     438,  1028,    81,   325,   829,   831,   391,   392,   393,   394,
     395,   396,   397,   847,   398,   326,   398,   723,   724,   854,
     855,   776,   637,  1038,   638,   860,   639,   410,   411,   412,
     413,   403,   404,   405,   406,   407,   408,   409,   327,   873,
     398,   398,   410,   411,   412,   413,   398,  1090,  1109,   640,
     472,   398,   641,  1112,   883,   884,   885,   642,  1115,   328,
     655,   329,   656,   330,   657,   398,   833,   834,   891,   836,
     837,   398,  1117,   331,    80,   398,   895,   896,  1118,   897,
     898,   899,  1129,   398,   332,    81,   398,   658,   876,   398,
     659,   905,   906,  1204,   908,   660,  1213,  1165,   333,  1166,
     909,  1167,   334,   910,   391,   392,   393,   394,   395,   396,
     397,  1146,   398,   843,   844,   911,   398,   878,   912,   913,
     914,  1053,   915,   916,  1168,   882,   398,  1169,   400,   401,
     335,   918,  1170,   801,   879,   402,   403,   404,   405,   406,
     407,   408,   409,   398,   668,   861,   862,   336,  1059,   410,
     411,   412,   413,   892,   893,   337,   400,   401,   923,   338,
     924,   925,   926,   402,   403,   404,   405,   406,   407,   408,
     409,   927,   525,   339,   933,   943,   944,   907,   400,   401,
    1196,   340,  1197,   341,  1198,   402,   403,   404,   405,   406,
     407,   408,   409,   342,   947,   343,   403,    80,   405,   406,
     407,   408,   409,   344,   954,  1062,  1063,  1199,    81,   477,
    1200,  1082,  1083,   192,   345,  1201,   346,   965,   966,  1130,
    1131,   347,   255,   255,   398,  1121,  1122,   348,   973,   974,
     478,   214,   349,   350,   218,   351,   352,   983,   405,   406,
     407,   408,   409,   230,   353,   354,   355,   236,   238,   356,
     357,   358,   254,   359,   410,   411,   412,   413,     1,     2,
       3,     4,     5,   360,   278,   279,   280,   361,   968,   969,
     362,  1148,   486,   287,   289,   290,   291,   363,   364,   492,
     365,   366,   410,   411,   412,   413,   367,   963,   964,  1161,
     368,   442,  1163,   369,   370,   371,  1037,  1030,  1031,   372,
     373,  1041,   374,   375,   410,   411,   412,   413,   376,   377,
     752,  1187,   753,   378,   410,   411,   412,   413,   379,   380,
     982,   400,   401,   381,   382,   383,  1057,   384,   402,   403,
     404,   405,   406,   407,   408,   409,   385,   505,   386,   387,
     447,   449,   462,   463,   467,   468,  1067,   500,   409,   653,
     600,   601,  1068,   633,   410,   411,   412,   413,   634,   635,
    1070,   662,  1071,   673,   646,   647,   648,  1073,   649,   650,
     651,   652,   678,   665,   672,   674,   705,  1077,   706,   707,
    1047,  1048,   708,   720,   840,   737,   726,  1086,   727,   734,
    1089,   738,   739,   389,   740,   874,   741,   742,   743,   744,
     950,   414,   759,   802,   805,   806,   865,  1103,  1104,   856,
     420,   400,   401,   866,   867,   868,  1061,   871,   402,   403,
     404,   405,   406,   407,   408,   409,   437,   872,  1123,   875,
     903,   441,   904,    80,    80,   937,   938,   962,   453,  1136,
     939,   940,   941,   942,    81,    81,   960,   410,   411,   412,
     413,   961,   985,   755,   975,   756,   992,   997,  1143,  1021,
    1033,  1034,   474,    -9,  1039,  1044,  1050,  1144,  1055,  1051,
    1056,  1058,   479,  1074,  1080,  1151,  1152,  1085,  1091,    80,
    1094,  1124,  1095,  1105,  1106,  1126,  1127,  1134,  1138,  1139,
      81,  -379,  1140,  1154,  1157,  1210,   498,    80,   193,   890,
      80,   276,   277,   196,   690,  1180,  1141,  1182,    81,   528,
     839,    81,   510,   838,  1032,  1212,   835,     0,   952,    80,
     688,     0,  1189,   521,   698,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,   410,   411,   412,
     413,     0,  1208,   777,     0,   778,     0,     0,     0,   553,
     554,   555,   556,   557,     0,     0,   560,     0,     0,   565,
       0,   567,     0,   569,   570,   572,   574,   576,   578,   579,
     580,   581,     0,   583,   584,   585,   586,   587,   588,   590,
       0,     0,   593,     0,   595,   596,   597,   598,   599,     0,
       0,   602,     0,   604,     0,   606,   607,   608,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,     0,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,     0,
       7,     8,     9,     0,     0,     0,     0,    10,     0,   666,
       0,    11,     0,    12,     0,    13,    14,    15,    16,    17,
    -330,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,   695,    29,     0,
       0,    30,     0,     0,     0,     0,   700,     0,    31,    32,
      33,    34,    35,    36,   400,   401,     0,    37,    38,   711,
     713,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
     410,   411,   412,   413,     0,    45,    46,    47,  -118,  -118,
      48,    49,    50,     0,    51,    52,    53,     0,     0,    54,
    -118,     0,    55,     0,    56,    57,   410,   411,   412,   413,
       0,     0,   978,     0,   979,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,     0,     0,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,    63,     0,
       0,     0,     0,    64,     0,     0,    65,     0,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   413,     0,     0,  1004,     0,  1005,     0,
       0,     0,     0,     0,     0,    67,    68,    69,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   437,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   852,     0,
       0,   853,     0,     0,   857,     0,     7,     8,     9,     0,
       0,     0,     0,    10,     0,     0,     0,    11,     0,    12,
       0,    13,    14,    15,    16,    17,  -330,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
       0,     0,     0,     0,    29,   -16,   -16,    30,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
       0,   400,   401,    37,    38,   900,     0,   902,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,    48,    49,    50,     0,
      51,    52,    53,     0,     0,    54,     0,   917,    55,     0,
      56,    57,     0,    93,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,   919,   920,   921,     0,     0,
       0,     0,     0,   922,    58,    59,    60,     0,     0,    99,
       0,    61,     0,     0,     0,     0,   929,     0,     0,   931,
       0,   932,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,    63,     0,     0,     0,     0,    64,
       0,     0,    65,     0,     0,     0,    66,     0,   949,     0,
       0,   951,     0,     0,     0,     0,     0,   410,   411,   412,
     413,     0,     0,     0,     0,   610,     0,     0,     0,     0,
       0,    67,    68,    69,    70,     0,   970,   971,   972,     0,
       0,     0,     0,   111,     0,   112,   980,   981,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,     0,     0,     0,   140,   141,   142,     0,
     144,     0,   146,   147,   148,     0,     0,     0,     0,   153,
     154,   155,   156,     0,     0,   159,     0,   161,     0,   163,
       0,     0,   165,   441,   167,     0,     0,   169,     0,     0,
     171,   172,     0,   173,   174,  1043,   176,     0,   178,     0,
       0,     0,     0,     0,     0,     0,   181,  1052,     0,     0,
       0,     0,     0,     0,   191,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1066,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,     0,     0,     0,  1069,   402,
     403,   404,   405,   406,   407,   408,   409,     0,  1072,   400,
     401,     0,  1075,     0,     0,  1076,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,     0,     0,
    1087,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1097,  1098,  1099,  1100,     0,  1102,     0,
       0,     0,     0,     0,     0,     7,     8,     9,     0,     0,
       0,     0,    10,     0,     0,     0,    11,     0,    12,     0,
      13,    14,    15,    16,    17,  -330,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,   -16,
       0,     0,     0,    29,   -16,     0,    30,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    37,    38,     0,     0,  1150,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   709,     0,  1160,    39,
      40,    41,    42,    43,    44,   410,   411,   412,   413,     0,
      45,    46,    47,   730,  1177,    48,    49,    50,     0,    51,
      52,    53,     0,     0,    54,     0,     0,    55,     0,    56,
      57,     0,  1188,     0,     0,     0,     0,     0,    91,    92,
      93,     0,    94,    95,    96,    97,     0,     0,     0,     0,
       0,  1206,     0,    58,    59,    60,     0,     0,     0,     0,
      61,     0,     0,     0,     0,    98,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,    63,     0,     0,     0,     0,    64,     0,
       0,    65,     0,     0,     0,    66,     0,     0,   100,   101,
     102,   103,   104,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   107,     0,     0,   108,
      67,    68,    69,    70,   257,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,     0,   109,   110,     0,     0,
     111,     0,   112,     0,     0,   259,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,     0,   168,   169,     0,   170,   171,   172,     0,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,   180,   181,   182,     0,     0,     0,     0,     0,
       0,   183,     0,   253,    91,    92,    93,     0,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,    93,   108,     0,     0,     0,    97,
     251,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,   109,   110,     0,     0,   111,     0,   112,     0,
      99,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,     0,   168,
     169,     0,   170,   171,   172,     0,   173,   174,   175,   176,
     177,   178,   179,     0,   111,     0,   112,     0,   180,   181,
     182,     0,     0,     0,     0,     0,     0,   183,     0,   253,
      91,    92,    93,     0,    94,    95,    96,    97,     0,     0,
       0,   134,   135,   136,     0,     0,     0,   140,   141,   142,
       0,   144,     0,   146,   147,   148,     0,    98,    99,     0,
     153,   154,   155,   156,     0,     0,   159,     0,   161,     0,
     163,     0,     0,   165,     0,   167,     0,     0,   169,     0,
       0,   171,   172,     0,   173,   174,     0,   176,     0,   178,
     100,   101,   102,   103,   104,   105,   106,   181,     0,     0,
       0,     0,     0,     0,     0,   191,   575,     0,   107,     0,
      93,   108,     0,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,   520,     0,     0,     0,   109,   110,
       0,     0,   111,     0,   112,     0,    99,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,     0,   168,   169,     0,   170,   171,
     172,     0,   173,   174,   175,   176,   177,   178,   179,     0,
     111,     0,   112,     0,   180,   181,   182,     0,     0,     0,
       0,     0,     0,   183,     0,   253,    91,    92,    93,     0,
      94,    95,    96,    97,     0,     0,     0,   134,   135,   136,
       0,     0,     0,   140,   141,   142,     0,   144,     0,   146,
     147,   148,     0,    98,    99,     0,   153,   154,   155,   156,
       0,     0,   159,     0,   161,     0,   163,     0,     0,   165,
       0,   167,     0,     0,   169,     0,     0,   171,   172,     0,
     173,   174,     0,   176,     0,   178,   100,   101,   102,   103,
     104,   105,   106,   181,     0,     0,     0,     0,     0,     0,
       0,   191,   577,     0,   107,     0,    93,   108,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,   111,     0,
     112,     0,    99,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,   165,   166,   167,
       0,   168,   169,     0,   170,   171,   172,     0,   173,   174,
     175,   176,   177,   178,   179,     0,   111,     0,   112,     0,
     180,   181,   182,     0,     0,     0,     0,     0,     0,   183,
       0,   253,    91,    92,    93,     0,    94,    95,    96,    97,
       0,     0,     0,   134,   135,   136,     0,     0,     0,   140,
     141,   142,     0,   144,     0,   146,   147,   148,     0,    98,
      99,     0,   153,   154,   155,   156,     0,     0,   159,     0,
     161,     0,   163,     0,     0,   165,     0,   167,     0,     0,
     169,     0,     0,   171,   172,     0,   173,   174,     0,   176,
       0,   178,   100,   101,   102,   103,   104,   105,   106,   181,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
     107,    93,     0,   108,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,   111,     0,   112,    99,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,   164,   165,   166,   167,     0,   168,   169,     0,
     170,   171,   172,   694,   173,   174,   175,   176,   177,   178,
     179,   111,     0,   112,     0,     0,   180,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   496,    91,    92,    93,
       0,    94,    95,    96,    97,     0,     0,     0,   134,   135,
     136,     0,     0,     0,   140,   141,   142,     0,   144,     0,
     146,   147,   148,     0,    98,    99,     0,   153,   154,   155,
     156,     0,     0,   159,     0,   161,     0,   163,     0,     0,
     165,     0,   167,     0,     0,   169,     0,     0,   171,   172,
       0,   173,   174,     0,   176,     0,   178,   100,   101,   102,
     103,   104,   105,   106,   181,     0,     0,     0,     0,     0,
       0,     0,   191,     0,     0,   107,    93,     0,   108,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,   111,
       0,   112,    99,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,   901,   173,
     174,   175,   176,   177,   178,   179,   111,     0,   112,     0,
       0,   180,   181,   182,     0,     0,     0,     0,     0,     0,
     183,   551,    91,    92,    93,     0,    94,    95,    96,    97,
       0,     0,     0,   134,   135,   136,     0,     0,     0,   140,
     141,   142,     0,   144,     0,   146,   147,   148,     0,    98,
      99,     0,   153,   154,   155,   156,     0,     0,   159,     0,
     161,     0,   163,     0,     0,   165,     0,   167,     0,     0,
     169,     0,     0,   171,   172,     0,   173,   174,     0,   176,
       0,   178,   100,   101,   102,   103,   104,   105,   106,   181,
       0,     0,     0,     0,     0,     0,     0,   191,     0,     0,
     107,    93,     0,   108,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,     0,   111,     0,   112,    99,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,     0,   164,   165,   166,   167,     0,   168,   169,     0,
     170,   171,   172,     0,   173,   174,   175,   176,   177,   178,
     179,   111,     0,   112,     0,     0,   180,   181,   182,     0,
       0,     0,     0,     0,     0,   183,   562,    91,    92,    93,
       0,    94,    95,    96,    97,     0,   265,     0,   134,   135,
     136,     0,     0,     0,   140,   141,   142,     0,   144,     0,
     146,   147,   148,     0,    98,    99,     0,   153,   154,   155,
     156,     0,     0,   159,     0,   161,     0,   163,     0,     0,
     165,     0,   167,     0,     0,   169,     0,   266,   171,   172,
       0,   173,   174,     0,   176,     0,   178,   100,   101,   102,
     103,   104,   105,   106,   181,     0,     0,     0,     0,     0,
       0,     0,   851,   400,   401,   107,     0,     0,   108,     0,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,   111,
       0,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,   180,   181,   182,     0,     0,     0,    91,    92,    93,
     183,    94,    95,    96,    97,     0,     0,     0,     0,   410,
     411,   412,   413,     0,     0,     0,     0,   747,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,   210,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,   107,     0,     0,   108,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,   111,
       0,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,   180,   181,   182,     0,     0,     0,    91,    92,    93,
     183,    94,    95,    96,    97,     0,   488,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   748,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,   107,     0,     0,   108,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,   111,
       0,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,   180,   181,   182,     0,     0,     0,    91,    92,    93,
     183,    94,    95,    96,    97,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   749,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,     0,   107,     0,     0,   108,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,   111,
       0,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,   180,   181,   182,     0,     0,     0,     0,     0,     0,
     183,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,     0,     0,   750,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   751,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   754,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   757,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   758,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   760,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   761,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   762,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,     0,
       0,   763,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   764,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   765,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   766,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   768,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   779,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   780,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   782,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,     0,     0,   785,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   808,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   850,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   959,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   976,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   977,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   986,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   987,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,     0,
       0,   988,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   989,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   990,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   995,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   996,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   999,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1000,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1001,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,     0,     0,  1002,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1003,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1006,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1007,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1010,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1017,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1020,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1036,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,     0,
       0,  1084,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1088,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1101,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1113,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1114,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1116,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1133,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,     0,     0,  1162,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1175,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1195,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1205,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1215,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   465,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   466,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   480,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,   504,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   691,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   728,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   729,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   731,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   732,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   733,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   746,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,   767,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   774,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   775,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   795,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   846,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   869,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   870,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   877,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,   880,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   881,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   886,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   887,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   889,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   948,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,   953,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   967,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,  1018,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,   400,   401,     0,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,  1019,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,  1042,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,  1054,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,  1060,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,  1110,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,  1128,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,  1159,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,  1174,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,  1194,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413
};

static const yytype_int16 yycheck[] =
{
       2,   204,   316,    12,    12,    40,     1,     4,     0,     4,
       7,   279,   280,     4,    25,    17,     7,     1,    44,   222,
       4,    75,     4,     5,   292,    15,    16,    58,    30,    60,
      61,    33,   190,    44,    36,    37,    38,    16,     7,   197,
      42,    43,    44,    58,     4,    60,    61,     7,     3,    51,
      28,    41,     7,     8,     9,    10,    75,    11,    53,    92,
      93,    63,     4,     5,    77,    44,    68,    69,    70,    53,
       3,   104,   858,   859,     7,     8,     9,    10,    76,    77,
      28,   190,   110,    20,    21,    33,   195,    43,    44,   283,
     284,   190,   190,    23,    88,    12,   195,   195,   197,   197,
     102,     4,     5,    77,   190,   190,    95,    63,   190,   195,
      12,   197,   197,   195,    75,   197,    70,    71,    72,    73,
      74,    75,    76,   190,   190,   190,    63,    64,   195,    47,
      48,   197,   197,    70,    71,    72,    73,    74,    75,    76,
      77,   190,   196,   195,    44,   197,    63,    64,   197,    67,
     132,   133,   134,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,   195,   190,   197,   196,   198,    70,    71,
      72,    73,    74,    75,    76,    77,    59,   196,   191,   192,
     182,   183,   190,   198,   190,    75,   195,   195,   382,   195,
     384,   189,   190,   191,   192,   196,   198,   100,     3,   196,
     196,   203,     7,     8,     9,   196,    89,    90,    91,   204,
     245,   246,    44,    96,   216,   189,   190,   191,   192,   221,
     204,   489,    74,    75,    76,    77,   228,   222,   190,   132,
     133,   134,   196,   195,   189,   190,   190,   190,   222,   507,
     508,   190,   195,   446,   197,   190,   195,    24,   197,   251,
     195,   253,   189,   190,   191,   192,   189,   190,   190,   190,
    1046,   190,   530,  1049,   195,   197,   197,   190,   197,   199,
     196,   201,   189,   190,   191,   192,   190,   190,   195,    44,
    1045,   195,   195,   285,   197,   190,   190,   189,   190,   191,
     192,   195,   197,   197,   195,   190,   197,     4,     5,   301,
     195,    75,    76,    77,   306,   307,  1092,   309,   310,   311,
     312,   313,   314,   195,     4,   197,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   189,   190,   191,
     192,   196,   344,   345,   346,   347,   348,   265,   350,   190,
     352,   196,   190,   271,   272,   190,   197,   313,   314,   197,
     362,   190,   197,    13,    35,    36,   368,  1132,   197,  1155,
    1135,   373,  1158,   329,   304,   305,     4,     5,   190,   190,
     298,   299,   300,   195,   195,   197,   197,   190,  1153,   190,
    1176,  1156,   195,  1179,   197,   195,   197,   197,   196,   317,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   368,    63,    64,   189,   190,   191,   192,    58,
      70,    71,    72,    73,    74,    75,    76,    77,  1214,   190,
    1216,   190,   190,   636,   195,  1221,  1222,   472,   197,   197,
     370,   371,  1207,   190,  1209,   447,   190,   196,   195,   717,
     452,   446,  1217,   197,  1219,     5,   190,   196,   190,   196,
      10,   195,   446,   465,   466,   197,    70,    71,    72,    73,
      74,    75,    76,   190,   190,   190,   478,   190,   480,   195,
     197,    31,   197,   195,   197,   196,    44,   196,   490,   491,
      70,    71,    72,    73,    74,    75,    76,   499,   500,   501,
     502,   815,   504,   190,   818,    63,    64,   196,     4,     5,
     197,   196,    70,    71,    72,    73,    74,    75,    76,    77,
       4,     5,    70,    71,    72,    73,    74,    75,    76,   190,
     190,   196,   462,   463,    46,   195,   197,   467,   468,   189,
     190,   191,   192,   196,    70,    71,    72,    73,    74,    75,
      76,    63,    64,   194,   195,   105,   196,   107,    70,    71,
      72,    73,    74,    75,    76,    77,    63,   485,     4,     5,
     488,    86,    87,    70,    71,    72,    73,    74,    75,    76,
      77,   196,   132,   133,   134,   503,   190,   196,   138,   139,
     140,   195,   142,   197,   144,   145,   146,   196,   190,   190,
     196,   151,   152,   153,   154,   197,   197,   157,   196,   159,
     190,   161,   196,   190,   164,   195,   166,   619,   620,   169,
     197,   196,   172,   173,   892,   175,   176,   196,   178,   190,
     180,   189,   190,   191,   192,   195,   197,   639,   188,   842,
     908,   636,   190,   190,   190,   196,   196,   197,   195,   197,
     652,   197,   636,   196,   644,   645,    70,    71,    72,    73,
      74,    75,    76,   665,   190,   196,   190,     4,     5,   671,
     672,   197,    14,   197,    16,   677,    18,   189,   190,   191,
     192,    71,    72,    73,    74,    75,    76,    77,   196,   691,
     190,   190,   189,   190,   191,   192,   190,   197,   197,    41,
     195,   190,    44,   197,   706,   707,   708,    49,   197,   196,
      14,   196,    16,   196,    18,   190,   646,   647,   720,   649,
     650,   190,   197,   196,   719,   190,   728,   729,   197,   731,
     732,   733,   197,   190,   196,   719,   190,    41,   195,   190,
      44,   743,   744,   197,   746,    49,   197,    14,   196,    16,
     752,    18,   196,   755,    70,    71,    72,    73,    74,    75,
      76,    46,   190,    49,    50,   767,   190,   195,   770,   771,
     772,   195,   774,   775,    41,   705,   190,    44,    63,    64,
     196,   783,    49,   197,   702,    70,    71,    72,    73,    74,
      75,    76,    77,   190,    51,     4,     5,   196,   195,   189,
     190,   191,   192,   721,   722,   196,    63,    64,   810,   196,
     812,   813,   814,    70,    71,    72,    73,    74,    75,    76,
      77,     4,     5,   196,   826,    39,    40,   745,    63,    64,
      14,   196,    16,   196,    18,    70,    71,    72,    73,    74,
      75,    76,    77,   196,   846,   196,    71,   842,    73,    74,
      75,    76,    77,   196,   856,     4,     5,    41,   842,   195,
      44,    60,    61,     3,   196,    49,   196,   869,   870,    60,
      61,   196,   874,   875,   190,  1078,  1079,   196,   880,   881,
     195,    21,   196,   196,    24,   196,   196,   889,    73,    74,
      75,    76,    77,    33,   196,   196,   196,    37,    38,   196,
     196,   196,    42,   196,   189,   190,   191,   192,   182,   183,
     184,   185,   186,   196,    54,    55,    56,   196,   874,   875,
     196,  1124,   195,    63,    64,    65,    66,   196,   196,     5,
     196,   196,   189,   190,   191,   192,   196,   867,   868,  1142,
     196,   943,  1145,   196,   196,   196,   948,   937,   938,   196,
     196,   953,   196,   196,   189,   190,   191,   192,   196,   196,
     195,  1164,   197,   196,   189,   190,   191,   192,   196,   196,
     888,    63,    64,   196,   196,   196,   978,   196,    70,    71,
      72,    73,    74,    75,    76,    77,   196,    43,   196,   196,
     196,   196,   196,   196,   196,   196,   998,   195,    77,    43,
     197,   197,  1004,   197,   189,   190,   191,   192,   197,    75,
    1012,    46,  1014,    58,   196,   196,   195,  1019,   196,   196,
     195,   195,    10,   196,   196,   196,   196,  1029,   195,   195,
     960,   961,   195,   195,    43,   195,   197,  1039,   197,   197,
    1042,   197,   196,   183,   196,    85,   197,   197,   195,   195,
      58,   191,   197,   197,   197,   197,   197,  1059,  1060,   196,
     200,    63,    64,   197,   196,   196,   984,   197,    70,    71,
      72,    73,    74,    75,    76,    77,   216,   197,  1080,    85,
     197,   221,   197,  1078,  1079,   195,   195,   195,   228,  1091,
     197,   197,   197,   197,  1078,  1079,   196,   189,   190,   191,
     192,   196,   196,   195,   197,   197,   197,   197,  1110,   196,
      43,    38,   252,    43,   196,    58,   197,  1119,    75,   197,
      75,    75,   262,   197,    48,  1127,  1128,    58,   196,  1124,
     197,    47,   197,   196,   196,   196,   196,    58,    75,   197,
    1124,    38,   197,   196,   196,     4,   286,  1142,     4,   719,
    1145,    53,    53,     5,   472,  1157,  1107,  1159,  1142,   316,
     652,  1145,   302,   651,   943,  1203,   648,    -1,   854,  1164,
     469,    -1,  1174,   313,   482,    -1,    -1,    -1,    -1,    -1,
    1164,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,  1194,   195,    -1,   197,    -1,    -1,    -1,   339,
     340,   341,   342,   343,    -1,    -1,   346,    -1,    -1,   349,
      -1,   351,    -1,   353,   354,   355,   356,   357,   358,   359,
     360,   361,    -1,   363,   364,   365,   366,   367,   368,   369,
      -1,    -1,   372,    -1,   374,   375,   376,   377,   378,    -1,
      -1,   381,    -1,   383,    -1,   385,   386,   387,    -1,    -1,
      -1,   391,   392,   393,   394,   395,   396,   397,   398,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,    -1,    -1,    -1,    11,    -1,   449,
      -1,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,   477,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,   486,    -1,    52,    53,
      54,    55,    56,    57,    63,    64,    -1,    61,    62,   499,
     500,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
     189,   190,   191,   192,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,   106,    -1,   108,   109,   189,   190,   191,   192,
      -1,    -1,   195,    -1,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,   162,    -1,
      -1,    -1,    -1,   167,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,    -1,   195,    -1,   197,    -1,
      -1,    -1,    -1,    -1,    -1,   199,   200,   201,   202,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   652,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   668,    -1,
      -1,   671,    -1,    -1,   674,    -1,     4,     5,     6,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    63,    64,    61,    62,   735,    -1,   737,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,    -1,   777,   106,    -1,
     108,   109,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,   795,   796,   797,    -1,    -1,
      -1,    -1,    -1,   803,   132,   133,   134,    -1,    -1,    31,
      -1,   139,    -1,    -1,    -1,    -1,   816,    -1,    -1,   819,
      -1,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,
      -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   848,    -1,
      -1,   851,    -1,    -1,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,    -1,
      -1,   199,   200,   201,   202,    -1,   876,   877,   878,    -1,
      -1,    -1,    -1,   105,    -1,   107,   886,   887,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,   138,   139,   140,    -1,
     142,    -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,
     152,   153,   154,    -1,    -1,   157,    -1,   159,    -1,   161,
      -1,    -1,   164,   943,   166,    -1,    -1,   169,    -1,    -1,
     172,   173,    -1,   175,   176,   955,   178,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   188,   967,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   993,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1008,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,  1018,    63,
      64,    -1,  1022,    -1,    -1,  1025,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
    1040,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1053,  1054,  1055,  1056,    -1,  1058,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    -1,    -1,  1126,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,  1138,    78,
      79,    80,    81,    82,    83,   189,   190,   191,   192,    -1,
      89,    90,    91,   197,  1154,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,   108,
     109,    -1,  1172,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,  1191,    -1,   132,   133,   134,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,    -1,
      -1,   170,    -1,    -1,    -1,   174,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
     199,   200,   201,   202,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,    -1,   163,   164,
     165,   166,    -1,   168,   169,    -1,   171,   172,   173,    -1,
     175,   176,   177,   178,   179,   180,   181,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,     5,    84,    -1,    -1,    -1,    10,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      31,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,    -1,   163,   164,   165,   166,    -1,   168,
     169,    -1,   171,   172,   173,    -1,   175,   176,   177,   178,
     179,   180,   181,    -1,   105,    -1,   107,    -1,   187,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,   132,   133,   134,    -1,    -1,    -1,   138,   139,   140,
      -1,   142,    -1,   144,   145,   146,    -1,    30,    31,    -1,
     151,   152,   153,   154,    -1,    -1,   157,    -1,   159,    -1,
     161,    -1,    -1,   164,    -1,   166,    -1,    -1,   169,    -1,
      -1,   172,   173,    -1,   175,   176,    -1,   178,    -1,   180,
      63,    64,    65,    66,    67,    68,    69,   188,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,    -1,    81,    -1,
       5,    84,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    31,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,    -1,
     163,   164,   165,   166,    -1,   168,   169,    -1,   171,   172,
     173,    -1,   175,   176,   177,   178,   179,   180,   181,    -1,
     105,    -1,   107,    -1,   187,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,   144,
     145,   146,    -1,    30,    31,    -1,   151,   152,   153,   154,
      -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,   164,
      -1,   166,    -1,    -1,   169,    -1,    -1,   172,   173,    -1,
     175,   176,    -1,   178,    -1,   180,    63,    64,    65,    66,
      67,    68,    69,   188,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   196,   197,    -1,    81,    -1,     5,    84,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    31,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,    -1,   163,   164,   165,   166,
      -1,   168,   169,    -1,   171,   172,   173,    -1,   175,   176,
     177,   178,   179,   180,   181,    -1,   105,    -1,   107,    -1,
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,    -1,   144,   145,   146,    -1,    30,
      31,    -1,   151,   152,   153,   154,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,    -1,
     169,    -1,    -1,   172,   173,    -1,   175,   176,    -1,   178,
      -1,   180,    63,    64,    65,    66,    67,    68,    69,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      81,     5,    -1,    84,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    31,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,   163,   164,   165,   166,    -1,   168,   169,    -1,
     171,   172,   173,    97,   175,   176,   177,   178,   179,   180,
     181,   105,    -1,   107,    -1,    -1,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    30,    31,    -1,   151,   152,   153,
     154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
     164,    -1,   166,    -1,    -1,   169,    -1,    -1,   172,   173,
      -1,   175,   176,    -1,   178,    -1,   180,    63,    64,    65,
      66,    67,    68,    69,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,    -1,    81,     5,    -1,    84,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    31,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,    -1,   168,   169,    -1,   171,   172,   173,    97,   175,
     176,   177,   178,   179,   180,   181,   105,    -1,   107,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,   138,
     139,   140,    -1,   142,    -1,   144,   145,   146,    -1,    30,
      31,    -1,   151,   152,   153,   154,    -1,    -1,   157,    -1,
     159,    -1,   161,    -1,    -1,   164,    -1,   166,    -1,    -1,
     169,    -1,    -1,   172,   173,    -1,   175,   176,    -1,   178,
      -1,   180,    63,    64,    65,    66,    67,    68,    69,   188,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,    -1,
      81,     5,    -1,    84,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    31,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,    -1,   163,   164,   165,   166,    -1,   168,   169,    -1,
     171,   172,   173,    -1,   175,   176,   177,   178,   179,   180,
     181,   105,    -1,   107,    -1,    -1,   187,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,   197,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,   132,   133,
     134,    -1,    -1,    -1,   138,   139,   140,    -1,   142,    -1,
     144,   145,   146,    -1,    30,    31,    -1,   151,   152,   153,
     154,    -1,    -1,   157,    -1,   159,    -1,   161,    -1,    -1,
     164,    -1,   166,    -1,    -1,   169,    -1,    53,   172,   173,
      -1,   175,   176,    -1,   178,    -1,   180,    63,    64,    65,
      66,    67,    68,    69,   188,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    63,    64,    81,    -1,    -1,    84,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,    -1,   168,   169,    -1,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,     3,     4,     5,
     196,     7,     8,     9,    10,    -1,    -1,    -1,    -1,   189,
     190,   191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,    -1,   168,   169,    -1,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,     3,     4,     5,
     196,     7,     8,     9,    10,    -1,    12,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,    -1,   168,   169,    -1,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,     3,     4,     5,
     196,     7,     8,     9,    10,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,    -1,   163,   164,   165,
     166,    -1,   168,   169,    -1,   171,   172,   173,    -1,   175,
     176,   177,   178,   179,   180,   181,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    63,    64,    -1,
      -1,   197,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    63,    64,    -1,
      -1,   197,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    63,    64,    -1,
      -1,   197,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    63,    64,   195,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    63,    64,   195,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    63,    64,   195,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    63,    64,   195,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    63,    64,   195,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,   190,
     191,   192
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   182,   183,   184,   185,   186,   204,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   132,   133,
     134,   139,   158,   162,   167,   170,   174,   199,   200,   201,
     202,   205,   206,   209,   210,   217,   218,   220,   221,   225,
     237,   238,   243,   249,   256,   264,   272,   275,   279,   282,
     288,     3,     4,     5,     7,     8,     9,    10,    30,    31,
      63,    64,    65,    66,    67,    68,    69,    81,    84,   101,
     102,   105,   107,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   163,   164,   165,   166,   168,   169,
     171,   172,   173,   175,   176,   177,   178,   179,   180,   181,
     187,   188,   189,   196,   223,   224,   226,   232,   234,   237,
     238,   196,   223,   209,   237,   238,   243,     0,    75,   196,
      75,   196,   257,   276,   280,     4,     7,   235,   235,   235,
      34,   226,   211,   212,   223,   239,   240,   239,   223,    28,
       7,   265,   273,   226,    58,    60,    61,   198,   319,   215,
     223,   226,     4,     5,   236,   226,   223,   226,   223,   226,
       4,     5,   299,   300,    10,   189,   190,   233,   234,   301,
     235,    89,    97,   198,   223,   226,   320,    89,    97,   110,
     320,   320,    88,   226,   231,    12,    53,   231,   231,    59,
      89,    90,    91,    96,    95,   226,   218,   225,   223,   223,
     223,   110,   196,   196,   196,   196,   196,   223,   320,   223,
     223,   223,   231,   226,   226,   226,    44,   207,    92,    93,
     104,    75,    75,    24,   196,   196,   196,   196,   226,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   226,   223,
     226,    70,    71,    72,    73,    74,    75,    76,   190,    44,
      63,    64,    70,    71,    72,    73,    74,    75,    76,    77,
     189,   190,   191,   192,   223,    44,    44,    44,   226,   239,
     223,   239,     4,   226,   206,    35,    36,    20,    21,     4,
       5,   250,   251,     4,     5,   252,   253,   223,   226,   241,
     242,   223,   226,   267,   206,   283,   289,   196,    58,   196,
       4,     7,   196,   223,   226,   302,    58,    60,    61,   198,
     304,   317,   196,   196,   195,   195,   195,   196,   196,   195,
     234,   234,   195,   226,   223,   226,    11,   195,   195,   223,
     195,   231,   216,    12,   195,   219,   195,   231,    12,   231,
     219,   219,     5,   222,   222,   222,   197,   226,   223,   195,
     195,   195,   195,   219,   195,    43,   231,   231,   231,   226,
     223,   244,   239,   239,   226,   226,   226,   226,   226,   226,
      97,   223,   320,   320,     4,     5,   229,   230,   229,   230,
     231,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   320,   226,   226,   226,   226,   226,   226,   226,
     226,   197,   226,   223,   223,   223,   223,   223,   226,   226,
     223,   226,   197,   226,   226,   223,   226,   223,   226,   223,
     223,   197,   223,   197,   223,   197,   223,   197,   223,   223,
     223,   223,   226,   223,   223,   223,   223,   223,   223,   320,
     223,   239,   239,   223,   226,   223,   223,   223,   223,   223,
     197,   197,   223,   222,   223,   222,   223,   223,   223,   197,
     197,   223,   223,   223,   223,   223,   223,   223,   223,   228,
     227,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   197,   197,    75,   277,    14,    16,    18,
      41,    44,    49,   281,   213,   214,   196,   196,   195,   196,
     196,   195,   195,    43,   266,    14,    16,    18,    41,    44,
      49,   274,    46,   206,   226,   196,   223,   226,    51,   303,
     194,   195,   196,    58,   196,     4,     7,   196,    10,   318,
     239,   239,     4,     5,   226,   226,   239,   239,   300,    10,
     233,   195,    86,    87,    97,   223,   226,   226,   304,   231,
     223,   231,   219,   226,   226,   196,   195,   195,   195,   197,
     197,   223,   226,   223,   226,   226,   226,   231,   226,   208,
     195,   219,   219,     4,     5,   248,   197,   197,   195,   195,
     197,   195,   195,   195,   197,   195,   197,   195,   197,   196,
     196,   197,   197,   195,   195,   219,   195,   197,   197,   197,
     197,   197,   195,   197,   197,   195,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,   197,   195,   197,   197,
     195,   195,   195,   197,   195,   195,   197,   195,   197,   197,
     197,   197,   197,   195,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   195,   195,   195,   197,   197,
     197,   197,   197,   195,   197,   197,   197,   197,   197,   197,
     195,   197,   195,   195,   195,   195,   195,   197,   195,   195,
     197,   195,   197,   197,   226,   226,   258,   206,   226,   235,
     321,   235,   322,   239,   239,   251,   239,   239,   253,   242,
      43,   268,   284,    49,    50,   290,   195,   226,   195,   197,
     197,   196,   223,   223,   226,   226,   196,   223,   305,   306,
     226,     4,     5,   296,   298,   197,   197,   196,   196,   195,
     195,   197,   197,   226,    85,    85,   195,   195,   195,   231,
     195,   195,   239,   226,   226,   226,   195,   195,   219,   195,
     210,   226,   231,   231,   245,   226,   226,   226,   226,   226,
     223,    97,   223,   197,   197,   226,   226,   231,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   223,   226,   223,
     223,   223,   223,   226,   226,   226,   226,     4,   230,   223,
     230,   223,   223,   226,    16,    44,   278,   195,   195,   197,
     197,   197,   197,    39,    40,   270,   206,   226,   195,   223,
      58,   223,   303,   195,   226,   195,   197,   296,   296,   197,
     196,   196,   195,   239,   239,   226,   226,   195,   320,   320,
     223,   223,   223,   226,   226,   197,   197,   197,   195,   197,
     223,   223,   231,   226,   219,   196,   197,   197,   197,   197,
     197,   197,   197,   195,   197,   197,   197,   197,   219,   197,
     197,   197,   197,   197,   195,   197,   197,   197,   195,   197,
     197,   197,   195,   197,   195,   197,   197,   197,   195,   195,
     197,   196,   195,   197,   197,   195,   197,   197,   197,    12,
     235,   235,   267,    43,    38,   285,   197,   226,   197,   196,
     195,   226,   195,   223,    58,   312,   307,   239,   239,   297,
     197,   197,   223,   195,   195,    75,    75,   226,    75,   195,
     195,   231,     4,     5,   254,   255,   223,   226,   226,   223,
     226,   226,   223,   226,   197,   223,   223,   226,   269,   271,
      48,   292,    60,    61,   197,    58,   226,   223,   197,   226,
     197,   196,   318,   296,   197,   197,   296,   223,   223,   223,
     223,   197,   223,   226,   226,   196,   196,   195,   197,   197,
     195,   197,   197,   197,   197,   197,   197,   197,   197,    13,
     262,   206,   206,   226,    47,   291,   196,   196,   195,   197,
      60,    61,   308,   197,    58,   313,   226,   296,    75,   197,
     197,   255,   246,   226,   226,   259,    46,   295,   206,   286,
     223,   226,   226,   314,   196,   318,   309,   196,   318,   195,
     223,   206,   197,   206,   293,    14,    16,    18,    41,    44,
      49,   287,   195,   197,   195,   197,   318,   223,   296,   318,
     226,   296,   226,    25,    44,   247,   260,   206,   223,   226,
     296,   195,   197,   296,   195,   197,    14,    16,    18,    41,
      44,    49,   261,   294,   197,   197,   223,   315,   226,   310,
       4,   263,   292,   197,   318,   197,   318,   316,   296,   311,
     296,   318,   318,   296,   296
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   203,   204,   204,   204,   204,   204,   205,   206,   207,
     208,   206,   209,   209,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   211,   210,   212,   210,   210,   210,   210,   210,   210,
     210,   213,   210,   214,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   215,   210,   216,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   217,   217,
     217,   217,   217,   218,   218,   218,   218,   218,   218,   219,
     219,   220,   220,   220,   220,   220,   221,   221,   222,   222,
     223,   223,   223,   223,   223,   223,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   225,   225,
     227,   226,   228,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   229,   230,   231,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     233,   233,   233,   234,   234,   234,   234,   235,   235,   236,
     236,   236,   236,   237,   238,   240,   239,   241,   241,   241,
     242,   242,   244,   245,   246,   243,   247,   247,   248,   248,
     249,   249,   249,   249,   250,   250,   251,   251,   251,   251,
     252,   252,   253,   253,   253,   253,   254,   254,   254,   255,
     255,   255,   255,   257,   258,   259,   260,   256,   261,   261,
     261,   261,   261,   261,   262,   262,   263,   263,   265,   264,
     266,   266,   267,   267,   268,   269,   268,   270,   271,   270,
     273,   272,   274,   274,   274,   274,   274,   274,   276,   277,
     275,   278,   278,   280,   279,   281,   281,   281,   281,   281,
     281,   283,   284,   285,   286,   282,   287,   287,   287,   287,
     287,   287,   289,   288,   290,   290,   291,   291,   292,   293,
     294,   292,   295,   295,   296,   297,   296,   298,   298,   298,
     298,   299,   299,   300,   300,   300,   300,   301,   301,   301,
     301,   302,   302,   302,   302,   302,   303,   303,   303,   305,
     304,   306,   304,   307,   304,   308,   304,   309,   304,   310,
     304,   311,   304,   312,   304,   313,   304,   314,   304,   315,
     304,   316,   304,   317,   304,   318,   318,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   320,   320,   321,   321,   322,   322,   210,   210,   210,
     210,   230
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       0,     5,     1,     2,     1,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     1,     2,     2,     3,
       3,     0,     5,     0,     5,     2,     1,     2,     1,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     8,     5,     2,     2,     2,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     4,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     4,     6,
       1,     3,     1,     3,     4,     6,     6,     4,     6,     4,
       6,    10,     4,     4,     4,     8,     6,     4,     3,     3,
       0,     4,     0,     4,     2,     3,     3,     3,     3,     3,
       3,     3,     4,     6,     1,     4,     4,     6,     6,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       3,     6,     6,     4,     4,     4,     4,     6,     6,     8,
       6,     8,     4,     4,     4,     8,     4,     4,     4,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     6,     6,     4,     6,     6,     6,     4,     8,     6,
       8,     6,     4,     4,     4,     6,     6,     6,     8,     4,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     4,
       6,     4,     6,     4,     4,     0,     2,     0,     1,     3,
       1,     1,     0,     0,     0,    11,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     3,     1,     1,     4,     4,
       1,     3,     1,     1,     4,     4,     0,     1,     3,     1,
       1,     3,     3,     0,     0,     0,     0,    14,     1,     1,
       1,     1,     1,     1,     0,     2,     0,     1,     0,     7,
       1,     2,     1,     1,     0,     0,     5,     0,     0,     4,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     0,
       6,     1,     1,     0,     4,     1,     2,     1,     1,     1,
       1,     0,     0,     0,     0,    11,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     1,     0,     2,     0,     0,
       0,     7,     0,     1,     1,     0,     4,     1,     4,     1,
       4,     1,     3,     1,     4,     1,     4,     1,     1,     3,
       3,     0,     2,     4,     1,     3,     0,     2,     6,     0,
       4,     0,     4,     0,     6,     0,     9,     0,    10,     0,
      13,     0,    15,     0,     7,     0,     9,     0,    10,     0,
      13,     0,    15,     0,     3,     0,     1,     0,     2,     2,
       4,     1,     4,     6,     6,     7,    10,    12,     7,    10,
      12,     2,     1,     1,     3,     1,     3,     8,     2,     2,
       6,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program_or_expression: tSTART_EXPRESSION expression tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 4: /* program_or_expression: tSTART_STRING_EXPRESSION string_expression tEOPROG  */
                                                       {YYACCEPT;}
    break;

  case 5: /* program_or_expression: tSTART_ASSIGNMENT assignment tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 6: /* program_or_expression: tSTART_FUNCTION_DEFINITION function_definition tEOPROG  */
                                                           {YYACCEPT;}
    break;

  case 7: /* program: statement_list tEOPROG  */
                                {YYACCEPT;}
    break;

  case 9: /* $@1: %empty  */
                   {if (severity_so_far >= sERROR) {YYABORT;}}
    break;

  case 10: /* $@2: %empty  */
                                                                    {if (in_short_if > 0 && (yyvsp[0].nnl) > 0) lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");}
    break;

  case 18: /* statement: tIMPORT  */
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
    break;

  case 19: /* statement: tERROR string_expression  */
                             {add_command(cERROR);}
    break;

  case 25: /* statement: tBREAK  */
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 26: /* statement: tBREAK tDIGITS  */
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 27: /* statement: tCONTINUE  */
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
    break;

  case 29: /* statement: function_or_array  */
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 30: /* statement: stringfunction_or_array  */
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 31: /* $@3: %empty  */
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
    break;

  case 33: /* $@4: %empty  */
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
    break;

  case 37: /* statement: tGOTO symbol_or_lineno  */
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 38: /* statement: tGOSUB symbol_or_lineno  */
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 39: /* statement: tON tINTERRUPT tBREAK  */
                          {create_exception(TRUE);}
    break;

  case 40: /* statement: tON tINTERRUPT tCONTINUE  */
                             {create_exception(FALSE);}
    break;

  case 41: /* $@5: %empty  */
                         {add_command(cSKIPPER);}
    break;

  case 42: /* statement: tON expression tGOTO $@5 goto_list  */
              {add_command(cNOP);}
    break;

  case 43: /* $@6: %empty  */
                          {add_command(cSKIPPER);}
    break;

  case 44: /* statement: tON expression tGOSUB $@6 gosub_list  */
               {add_command(cNOP);}
    break;

  case 45: /* statement: tLABEL symbol_or_lineno  */
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
    break;

  case 46: /* statement: open_clause  */
                {add_command(cCHECKOPEN);}
    break;

  case 47: /* statement: tCLOSE hashed_number  */
                         {add_command(cCLOSE);}
    break;

  case 48: /* statement: seek_clause  */
                {add_command(cCHECKSEEK);}
    break;

  case 49: /* statement: tCOMPILE string_expression  */
                               {add_command(cCOMPILE);}
    break;

  case 50: /* statement: tEXECUTE call_list  */
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
    break;

  case 51: /* statement: tEXECUTE2 call_list  */
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
    break;

  case 52: /* statement: tPRINT printintro printlist  */
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
    break;

  case 53: /* statement: tPRINT printintro printlist ';'  */
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 54: /* statement: tPRINT printintro printlist ','  */
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
    break;

  case 55: /* $@7: %empty  */
           {tileol=FALSE;}
    break;

  case 57: /* $@8: %empty  */
                 {tileol=TRUE;}
    break;

  case 59: /* statement: tCOLOUR expression ',' expression ',' expression  */
                                                     {add_command(cGCOLOUR);}
    break;

  case 60: /* statement: tCOLOUR string_expression  */
                              {add_command(cGCOLOUR2);}
    break;

  case 61: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
                                                         {add_command(cGBACKCOLOUR);}
    break;

  case 62: /* statement: tBACKCOLOUR string_expression  */
                                  {add_command(cGBACKCOLOUR2);}
    break;

  case 65: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 66: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 67: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 68: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 69: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 72: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 73: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 74: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 75: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 76: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 77: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 78: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 79: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 80: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 83: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 84: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 85: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 86: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 87: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 88: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 91: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 92: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 93: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 94: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 95: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 96: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 97: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 98: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 99: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 100: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 101: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 102: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 103: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 104: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 105: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 106: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 107: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 108: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 109: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 110: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 111: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 112: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 113: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 114: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 115: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 116: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 117: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 118: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 119: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 120: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 121: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 122: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 123: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 124: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 125: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 126: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 127: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 128: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 131: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 132: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 133: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 134: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 135: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 136: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 137: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 138: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 139: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 140: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 142: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 143: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 144: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 146: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 147: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 148: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 149: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 150: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 151: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 152: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 153: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 154: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 155: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 156: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 157: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 158: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 159: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 160: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 161: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 162: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 163: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 164: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 165: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 166: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 167: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 168: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 169: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 170: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 171: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 172: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 173: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 174: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 175: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 176: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 177: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 178: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 179: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 180: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 181: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 182: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 183: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 184: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 185: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 186: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 187: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 188: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 189: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 190: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 191: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 192: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 193: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 194: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 195: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 196: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 197: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 198: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 199: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 200: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 201: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 202: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 203: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 204: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 205: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 206: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 207: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 208: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 209: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 210: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 211: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 212: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 213: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 214: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 215: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 216: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 217: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 218: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 219: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 220: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 221: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 222: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 223: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 226: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 227: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 229: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 230: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 231: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 232: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 233: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 234: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 235: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 236: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 237: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 238: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 239: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 240: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 241: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 242: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 243: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 244: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 245: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 246: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 247: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 248: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 249: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 250: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 251: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 252: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 253: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 254: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 255: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 256: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 257: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 258: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 259: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 260: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 261: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 262: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 263: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 264: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 265: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 266: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 267: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 268: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 269: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 270: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 271: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 272: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 273: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 274: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 275: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 276: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 277: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 278: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 279: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 280: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 281: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 282: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 283: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 284: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 285: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 286: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 287: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 288: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 289: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 290: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 291: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 292: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 293: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 294: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 295: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 296: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 297: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 298: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 299: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 300: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 301: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 302: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 303: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 304: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 305: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 306: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 307: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 308: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 309: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 310: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 311: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 312: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 313: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 314: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 315: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 322: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 323: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 324: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 325: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 326: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 327: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 328: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 329: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 330: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 331: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 332: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 333: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 336: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 337: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 338: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 339: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 342: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 343: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 344: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 345: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 349: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 350: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 351: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 352: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 353: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 354: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 355: /* $@17: %empty  */
                    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}
    break;

  case 356: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 357: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 358: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 359: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 360: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 361: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 362: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 363: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 364: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 366: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 367: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 368: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 369: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 375: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 376: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 378: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 380: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 382: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 383: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 384: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 385: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 386: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 387: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 388: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 389: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 391: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 392: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 393: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 395: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 396: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 397: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 398: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 399: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 400: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 401: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 402: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 403: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 404: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 406: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 407: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 408: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 409: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 410: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 411: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 412: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 414: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 415: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 419: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 420: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 425: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 427: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 428: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 429: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 430: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 433: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 434: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 435: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 436: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 437: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 438: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 439: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 440: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 444: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 445: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 446: /* using: %empty  */
       {create_print('d');}
    break;

  case 447: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 448: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 449: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 450: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 451: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 452: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 453: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 454: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 455: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 456: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 457: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 458: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 459: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 460: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 461: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 462: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 463: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 464: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 465: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 466: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 467: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 468: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 469: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 470: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 471: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 472: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 473: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 474: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 475: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 476: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 477: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 478: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 479: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 480: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 481: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 482: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 483: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 484: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 485: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 486: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 487: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 488: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 489: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 490: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 493: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 494: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 495: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 496: /* gosub_list: gosub_list ',' symbol_or_lineno  */
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 497: /* statement: tSETRGB expression ',' expression ',' expression ',' expression  */
                                                                  {add_command(cSETRGB);}
    break;

  case 498: /* statement: tSETDRAWBUF expression  */
                           {add_command(cSETDRAWBUF);}
    break;

  case 499: /* statement: tSETDISPBUF expression  */
                           {add_command(cSETDISPBUF);}
    break;

  case 500: /* statement: tGTRIANGLE coordinates to coordinates to coordinates  */
                                                         {add_command(cGTRIANGLE);}
    break;

  case 501: /* string_arrayref: tSYMBOL '(' ')'  */
                  {char *ps2_name=ps2_string_arrayref_name((yyvsp[-2].symbol)); create_pusharrayref(dotify(ps2_name,FALSE),stSTRINGARRAYREF); my_free(ps2_name);}
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

