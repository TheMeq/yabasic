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
  YYSYMBOL_tGTRIANGLE = 94,                /* tGTRIANGLE  */
  YYSYMBOL_tTEXT = 95,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 96,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 97,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 98,                  /* tPRINTER  */
  YYSYMBOL_tSETRGB = 99,                   /* tSETRGB  */
  YYSYMBOL_tSETDRAWBUF = 100,              /* tSETDRAWBUF  */
  YYSYMBOL_tSETDISPBUF = 101,              /* tSETDISPBUF  */
  YYSYMBOL_tWAIT = 102,                    /* tWAIT  */
  YYSYMBOL_tBELL = 103,                    /* tBELL  */
  YYSYMBOL_tLET = 104,                     /* tLET  */
  YYSYMBOL_tARDIM = 105,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 106,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 107,                    /* tBIND  */
  YYSYMBOL_tRECT = 108,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 109,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 110,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 111,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 112,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 113,                     /* tNEW  */
  YYSYMBOL_tCURVE = 114,                   /* tCURVE  */
  YYSYMBOL_tSIN = 115,                     /* tSIN  */
  YYSYMBOL_tASIN = 116,                    /* tASIN  */
  YYSYMBOL_tCOS = 117,                     /* tCOS  */
  YYSYMBOL_tACOS = 118,                    /* tACOS  */
  YYSYMBOL_tTAN = 119,                     /* tTAN  */
  YYSYMBOL_tATAN = 120,                    /* tATAN  */
  YYSYMBOL_tEXP = 121,                     /* tEXP  */
  YYSYMBOL_tLOG = 122,                     /* tLOG  */
  YYSYMBOL_tSQRT = 123,                    /* tSQRT  */
  YYSYMBOL_tSQR = 124,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 125,                   /* tMYEOF  */
  YYSYMBOL_tABS = 126,                     /* tABS  */
  YYSYMBOL_tSIG = 127,                     /* tSIG  */
  YYSYMBOL_tINT = 128,                     /* tINT  */
  YYSYMBOL_tCEIL = 129,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 130,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 131,                    /* tFRAC  */
  YYSYMBOL_tROUND = 132,                   /* tROUND  */
  YYSYMBOL_tMOD = 133,                     /* tMOD  */
  YYSYMBOL_tRAN = 134,                     /* tRAN  */
  YYSYMBOL_tVAL = 135,                     /* tVAL  */
  YYSYMBOL_tLEFT = 136,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 137,                   /* tRIGHT  */
  YYSYMBOL_tMID = 138,                     /* tMID  */
  YYSYMBOL_tLEN = 139,                     /* tLEN  */
  YYSYMBOL_tMIN = 140,                     /* tMIN  */
  YYSYMBOL_tMAX = 141,                     /* tMAX  */
  YYSYMBOL_tSTR = 142,                     /* tSTR  */
  YYSYMBOL_tINKEY = 143,                   /* tINKEY  */
  YYSYMBOL_tCHR = 144,                     /* tCHR  */
  YYSYMBOL_tASC = 145,                     /* tASC  */
  YYSYMBOL_tHEX = 146,                     /* tHEX  */
  YYSYMBOL_tDEC = 147,                     /* tDEC  */
  YYSYMBOL_tBIN = 148,                     /* tBIN  */
  YYSYMBOL_tUPPER = 149,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 150,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 151,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 152,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 153,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 154,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 155,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 156,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 157,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 158,                 /* tSTRING2  */
  YYSYMBOL_tINSTR = 159,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 160,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 161,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 162,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 163,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 164,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 165,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 166,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 167,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 168,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 169,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 170,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 171,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 172,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 173,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 174,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 175,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 176,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 177,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 178,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 179,                    /* tDATE  */
  YYSYMBOL_tTIME = 180,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 181,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 182,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 183,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 184,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 185,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 186,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 187,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 188, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 189,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 190, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 191,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 192,                   /* tEVAL2  */
  YYSYMBOL_193_ = 193,                     /* '-'  */
  YYSYMBOL_194_ = 194,                     /* '+'  */
  YYSYMBOL_195_ = 195,                     /* '*'  */
  YYSYMBOL_196_ = 196,                     /* '/'  */
  YYSYMBOL_UMINUS = 197,                   /* UMINUS  */
  YYSYMBOL_198_ = 198,                     /* ';'  */
  YYSYMBOL_199_ = 199,                     /* ','  */
  YYSYMBOL_200_ = 200,                     /* '('  */
  YYSYMBOL_201_ = 201,                     /* ')'  */
  YYSYMBOL_202_ = 202,                     /* '#'  */
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
#define YYLAST   6724

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
       2,     2,     2,     2,     2,   202,     2,     2,     2,     2,
     200,   201,   195,   194,   199,   193,     2,   196,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   198,
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
     185,   186,   187,   188,   189,   190,   191,   192,   197
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   201,   201,   202,   203,   204,   205,   208,   211,   212,
     212,   212,   215,   216,   217,   218,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   236,   237,   237,   238,   239,   240,   241,   242,
     243,   244,   244,   246,   246,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   258,   259,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   279,   280,   281,   282,   283,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   335,   336,   337,   338,   339,   343,   344,   345,
     346,   347,   348,   351,   352,   355,   356,   357,   358,   359,
     362,   363,   366,   367,   370,   371,   372,   373,   374,   375,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   422,   423,   426,   426,   427,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     462,   465,   466,   469,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   545,   546,   547,   550,   551,
     552,   553,   556,   557,   560,   561,   562,   563,   566,   569,
     572,   572,   575,   576,   577,   580,   581,   584,   585,   588,
     584,   593,   594,   597,   598,   601,   602,   603,   604,   607,
     608,   611,   612,   613,   614,   617,   618,   621,   622,   623,
     624,   627,   628,   629,   632,   633,   634,   635,   638,   639,
     644,   659,   638,   664,   665,   666,   667,   668,   669,   672,
     673,   676,   677,   682,   682,   686,   687,   690,   691,   695,
     697,   696,   701,   702,   702,   706,   706,   712,   713,   714,
     715,   716,   717,   721,   722,   721,   728,   729,   733,   733,
     738,   739,   740,   741,   742,   743,   746,   747,   747,   749,
     746,   753,   754,   755,   756,   757,   758,   761,   761,   766,
     767,   770,   771,   774,   776,   778,   775,   782,   783,   786,
     787,   787,   790,   791,   793,   794,   798,   799,   802,   803,
     805,   806,   810,   811,   812,   813,   816,   817,   818,   819,
     820,   823,   824,   825,   828,   828,   829,   829,   830,   830,
     831,   831,   832,   832,   833,   833,   834,   834,   835,   835,
     836,   836,   837,   837,   838,   838,   839,   839,   840,   840,
     843,   844,   847,   848,   849,   850,   851,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   863,   864,   866,   867,
     870,   871
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
  "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tGTRIANGLE",
  "tTEXT", "tCLEAR", "tFILL", "tPRINTER", "tSETRGB", "tSETDRAWBUF",
  "tSETDISPBUF", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE", "tBIND",
  "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE",
  "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG",
  "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR",
  "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID",
  "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC",
  "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tINSTR", "tRINSTR", "tCHOMP",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL",
  "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE",
  "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'", "$accept",
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

#define YYPACT_NINF (-1032)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-407)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     835,  4284,  3701,  2798,    79,    44,    29,   -50,   -21, -1032,
   -1032, -1032, -1032, -1032,   193,   193,   193,  3313, -1032, -1032,
   -1032,  2798, -1032, -1032,  2798,    45,    30, -1032, -1032, -1032,
    3701,   -34, -1032,  3701,   147, -1032,  3701,  3701,  3701,   167,
      36,   193,  1922,  1244,  2322,   -41,  3701,  3119,  3701,  3701,
      -3,   -35,  3701,  3701,  3701,  3701, -1032,    54,  2798,  2798,
    2798,    18,  -107,   -79,   -27,   -15,    12,  2322,  2798,  2798,
    2798, -1032,   154, -1032, -1032,   -23, -1032, -1032, -1032, -1032,
     128,   131, -1032,   197, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,    73,    95, -1032, -1032, -1032, -1032,   151,   164,
     182,   185,  3701,   216,   228,   231,   256,   265,   271,   275,
     292,   343,   358,   394,   424,   434,   438,   446,   462,   482,
     501,   535,   537,   555,   564,   574,   582,   609,   615,   619,
     620,   621,   625,   626,   627,   628,   637,   638,   639,   640,
     642,   643,   646,   647,   652,   653,   664,   665,   670,   671,
     674,   675,   684,   685,   686,   688,   689,   690,   700,   701,
     702,   707,   717,   718,   719,   727,   728,   739,   742,   747,
     748,   749,   750,   756,   757,   768,   769,   770,   776,   777,
     783,   784,  3701,  3701,   821, -1032,   409, -1032, -1032, -1032,
   -1032,  2798,   -25,   217,   128,   131,   239, -1032,  3701, -1032,
    2798, -1032,   351,  3701,  4120, -1032, -1032, -1032, -1032, -1032,
     262,   366,   310,   523,    49, -1032,  3701, -1032,    49, -1032,
   -1032,  3701,  4120,   460,   797,   341,   799,     2,  3701,   -28,
     821,  6528,   800,   804,   168,  6528,   821,  5545,   821,  5560,
     808,   809,   326, -1032, -1032,   740,   740, -1032, -1032,   385,
   -1032,  3701,  2798,  3701,    91,  6528,   499, -1032, -1032, -1032,
   -1032,   524,  2798,  5575, -1032,  3701, -1032,     6,     6,   617,
   -1032, -1032,  3701,  3507, -1032, -1032,  5595,  6528,  6528,  6528,
   -1032, -1032,    49,     0,     0, -1032,   850,   850,   850,  2522,
    2798,   525,   731,    49,   199,   233, -1032,   863,  3701,  3701,
    3701,  3701,  2798, -1032, -1032, -1032,  3701,  3701,   918,  3701,
    3701,  3701,  3701,  2122,  2322,   552,   552,  3701,  3701,  3701,
    3701,  3701,  3701,  3701,  3701,  3701,  3701,  3701,  3701,  2322,
    3701,  3701,  3701,  3701,  3701,  3701,  3701,  3701,  2721,  2798,
    2798,  2798,  2798,  2798,  3701,  3701,  3701,  2920,  3701,  2798,
    3701,  2798,  3701,  2798,  2798,  1428,  1601,  1800,  2599,  2798,
    2798,  2798,  3701,  2798,  2798,  2798,  2798,  2798,  2322,  2798,
   -1032, -1032,  2798,  3701,  2798,  2798,  2798,  2798,  2798,   758,
     771,  2798,   850,  2798,   850,  2798,  2798,  2798,   909,   196,
     715,  2798,  2798,  2798,  2798,  2798,  2798,  2798,  2798, -1032,
   -1032, -1032,  3701,  3701,  3701,  3701,  3701,  3701,  3701,  3701,
    3701,  3701,  3701,  3701,  -130, -1032, -1032, -1032,  6528,   810,
      49,   818,   951,  6528,   722, -1032, -1032, -1032, -1032,   829,
     831,   833, -1032,   834,   839,   836, -1032,   821,  6528,   842,
   -1032,   821,  6528,   999,   957,   998,  4120,  3701,   847,  2798,
   -1032, -1032,  3701,   821,   478,   408,   848,   991,   853,     4,
   -1032,  1040, -1032, -1032,   616,  3701,  3701, -1032, -1032,   167,
   -1032, -1032,    71,  5626,    49,  6528,   561,  3885,  3701,    49,
    3701, -1032,   -28, -1032, -1032,  3701,  3701,  2798, -1032,  3701,
       6,  3701,  3701,  3701,   859,   864,   865,   866, -1032,  1089,
    -112,  3701,  3701,  3701,  3701, -1032,   868,     6,     6,  6528,
      49,   676,   867,   869,  5659,  5709,  1105,  5729,  5760,  5793,
     870,   218,   873,   874,   860,   862,   875,   876,   880,   891,
       6,  5808,  1430,  1451,  1477,  1613,  1628,   516,  1655,   730,
    1801,  1820,   892,  2141,  2341,  3135,  3328,  3522,  3716,  4175,
    5823, -1032,  4339,   -89,   294,   314,   315,   -71,  5843,  5863,
     538,   759, -1032,  4443,  4493,   -70,  4524,  -104,  4557,   -53,
     -52, -1032,    80, -1032,   112, -1032,   155, -1032,   169,   187,
     220,   221,  5894,   323,   345,   250,   268,   273,   557,   893,
     -91,   894,   895,   276,  4577,   293,   -24,   384,   450,   498,
   -1032, -1032,   522,   -90,   526,    19,   558,   309,   311, -1032,
   -1032,    49,    49,    49,    49,    49,    49,    49, -1032,  3701,
    3701,   861,   492,   890,   602,   264,    52,   107, -1032,    15,
      15,   909,   909, -1032, -1032, -1032,  4120, -1032, -1032,  3701,
   -1032, -1032, -1032, -1032,   193,   193, -1032, -1032,   310, -1032,
   -1032,   523,  3701, -1032,  1026, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,   655,  5957,  3701,   -12,  4592,  2997, -1032,
   -1032,  3701,  3701,   898,  2798, -1032, -1032,  3701, -1032,   709,
     899,   900,   902,   903,  5977,  5997,   904,   905, -1032, -1032,
   -1032,  3701,  1006,  1007, -1032,   560,  6028,  6528, -1032, -1032,
       6,   562, -1032,  3701,  6043,  6058,  6091, -1032,  3701,  3701,
    3701, -1032, -1032,   821,  6528,   821,  6528,  6111,  6131,  4120,
    3701,  3701,  3701, -1032, -1032, -1032, -1032, -1032,  3701,  3701,
   -1032,  3701,  3701,  3701, -1032,  2798, -1032,  3938, -1032,   908,
     914, -1032, -1032,  3701,  3701,  3701,  3701, -1032, -1032, -1032,
   -1032, -1032,  3701, -1032, -1032,  3701, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032,  3701, -1032, -1032,
    3701,  3701,  3701, -1032,  3701,  3701, -1032,  2798, -1032, -1032,
   -1032, -1032, -1032,  3701, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,  2798,  2798,  2798, -1032, -1032,
   -1032, -1032, -1032,  2798, -1032, -1032, -1032, -1032, -1032, -1032,
    3701, -1032,  3701,  3701,  3701,   729,  2798, -1032,   729,  2798,
   -1032,  2798, -1032, -1032,   918,   302,  3701,     5,  6528, -1032,
     911, -1032,   917,   919,   920, -1032,   921,   922, -1032, -1032,
   -1032,   706,  4120, -1032, -1032, -1032,  3701,  6192,  2798,  1016,
   -1032,  2798,    49,   821,   478,  6225,  3701,    33,   709,   709,
    4607,   924,   928, -1032,   932, -1032, -1032, -1032, -1032,  3701,
    3701, -1032, -1032,  6245,  2322,  2322,  2798,  2798,  3701,  2798,
   -1032,  3701,  3701,  3701,   931,  4627,  4658,   786,  2798,  2798,
   -1032,  6528,     6, -1032,   934,  4691,  4741,  4761,  4792,  4825,
     317,   943,    34, -1032, -1032,  4840,  4855,   945,    43,  4875,
    4895,  4926,  4989,  5009,  1066,  5029,  5060,    61,  5075,   325,
      81,   153,   344,  5090,  6265,  6280,  5123,   949,    23,   346,
      85,   421,   422,    63, -1032, -1032, -1032,   193,   193, -1032,
   -1032, -1032, -1032,  3701,  1056,  1080,  1061,  5143,  3701,   425,
     950,   190, -1032,  3701,  6295,  2798,  1098, -1032, -1032, -1032,
   -1032, -1032, -1032,   969,   970,  6528,  6528,  2798, -1032, -1032,
      49,    49, -1032,   568,  6326,  6359,  6528, -1032,  1044,  1099,
    3701,  1108,   581,    49,  3701,   772, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032,  2798, -1032, -1032, -1032, -1032,  3701, -1032,
   -1032, -1032, -1032, -1032,  3701, -1032, -1032, -1032,  2798, -1032,
   -1032, -1032,  3701, -1032,  3701, -1032, -1032, -1032,  2798,  3701,
   -1032,   988,  2798, -1032, -1032,  2798, -1032, -1032, -1032,  3701,
   -1032, -1032, -1032, -1032, -1032,  1142,   723,  5163,  1135,  3701,
    2798,  5224,  3701,   441,   995,  1040,   709,   996,  1014,   709,
   -1032, -1032,    49,  2798,  3701,  2798,  2798,  2798,  5257,  2798,
    3701, -1032,  1018,  1024,   247, -1032,   442,  6379,  5277,   463,
    5297,  5312,   464,  5327, -1032,   465,   466,    83,  4120,  4448,
    3701,  1160, -1032,  1025, -1032,  1027,  6429,   467,   753,  5358,
    1158,  3701,   709, -1032, -1032, -1032, -1032,    49,  6528,    49,
      49,    49,  1154,    49,  6528,  1032,  1033,   772, -1032, -1032,
    3701, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,  3701,
   -1032,  1061,  1197,   500,  4120, -1032,  2798,  3701,  3701, -1032,
   -1032,  1045,  1040, -1032,  1046,  1040,  6460, -1032,  2798, -1032,
   -1032, -1032,  4120,  5391,  6528,  4120, -1032, -1032,  1061,   989,
     253,  6493,  5411,  1040,  2798,   709,  1040,  3701,   709,  3701,
      49,    13, -1032,  1061,  4120, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,  2798, -1032,  3701, -1032,   709,   267, -1032,   709,
    6513, -1032,  5461, -1032, -1032, -1032,  1002,  1061,   489,  5492,
   -1032,  2798, -1032, -1032,  3701, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032,  1240,  1142, -1032, -1032,   490,  1040,  5525,  1040,
   -1032, -1032, -1032, -1032,   709, -1032,   709,  1040, -1032,  1040,
   -1032,   709,   709, -1032, -1032
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   122,     0,     0,     0,   335,     0,     0,     0,   116,
     358,   393,   398,    18,     0,     0,     0,     0,    31,    33,
     336,     0,   320,   320,     0,   337,    25,    27,   373,   385,
       0,   482,    55,    70,     0,   113,   114,     0,     0,     0,
       0,    68,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,     0,     0,     0,   104,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     2,     9,    17,     8,     0,    12,    46,    48,    14,
      29,    30,    28,     0,    20,    21,    24,    23,    22,    35,
      36,   308,   214,   144,   309,   310,   311,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,     0,   275,
     278,   281,   284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,     0,   228,   208,   213,
     146,     0,     0,     0,     0,     0,     0,     1,     0,   320,
       0,   320,     0,     0,    16,   313,   312,    37,    38,    45,
       0,     0,     0,     0,    19,    50,   322,    51,    49,   338,
      26,     0,    16,   417,     0,   486,     0,     0,   446,   478,
      72,    71,     0,     0,    73,   115,    60,     0,    62,     0,
     438,   440,    66,   436,   442,     0,     0,   443,   305,    67,
      69,     0,   100,     0,     0,   497,     0,    97,   102,    89,
      47,     0,     0,     0,    77,     0,    57,    82,     0,     0,
      99,    98,     0,     0,   125,   126,     0,    64,    65,   103,
      13,    15,   117,     0,     0,    88,     0,     0,     0,     0,
       0,     0,     0,   118,     0,     0,     7,     0,     0,     0,
       0,     0,     0,   327,   320,   320,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     320,   320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
     196,   194,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,   192,     0,
     127,     0,     0,   394,     9,    39,    40,    41,    43,   341,
     342,    32,   339,   347,   348,    34,   345,   325,   326,   321,
     323,   378,   377,     0,     9,     0,    16,     0,     0,     0,
     483,   484,     0,   449,   451,    52,     0,     0,     0,     0,
      56,   480,   320,   320,     0,     0,     0,   320,   320,     0,
     307,   306,     0,     0,   101,   496,     0,     0,     0,    76,
       0,    81,   478,   134,   133,     0,     0,     0,    78,     0,
      84,     0,     0,     0,   142,     0,     0,     0,   106,     0,
       0,     0,     0,     0,     0,    10,     0,     0,     0,   193,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,   276,     0,   279,     0,   282,     0,   285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     175,   177,     0,     0,     0,     0,     0,     0,     0,   149,
     229,   223,   225,   227,   224,   226,   221,   222,   148,     0,
       0,   201,   203,   205,   202,   204,   199,   200,   219,   216,
     215,   217,   218,   318,   319,   359,    16,   405,   403,     0,
     404,   400,   402,   399,     0,     0,   320,   320,     0,   320,
     320,     0,     0,   375,   379,   392,   390,   391,   388,   387,
     389,   386,   407,     9,     0,     0,     0,     0,     0,   447,
      53,    54,     0,     0,     0,   454,   456,     0,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   437,   444,
     445,     0,     0,     0,   137,   136,   140,   233,    58,    79,
       0,    93,    83,     0,     0,     0,     0,   320,     0,     0,
       0,   107,   108,   109,   110,   111,   112,     0,     0,    16,
       0,     0,     0,   333,   334,   328,   297,   188,     0,     0,
     288,     0,     0,     0,   298,     0,   299,     0,   292,     0,
       0,   209,   210,     0,     0,     0,     0,   234,   235,   236,
     237,   238,     0,   239,   241,     0,   242,   244,   245,   206,
     251,   252,   246,   248,   249,   250,   247,     0,   254,   259,
       0,     0,     0,   258,     0,     0,   157,     0,   154,   160,
     161,   260,   186,     0,   261,   187,   162,   163,   274,   277,
     280,   283,   166,   164,   165,     0,     0,     0,   168,   267,
     169,   273,   272,     0,   178,   268,   170,   269,   171,   271,
       0,   172,     0,     0,     0,     0,     0,   181,     0,     0,
     183,     0,   304,   191,   197,   195,     0,     9,   401,   498,
      42,   500,    44,     0,     0,   340,     0,     0,   346,   324,
     376,   382,    16,   419,   420,   418,     0,     0,     0,   487,
     485,     0,   452,   450,   451,     0,     0,     0,     0,     0,
       0,   432,   434,   479,   429,   314,   316,   320,   320,     0,
       0,   439,   441,    74,     0,     0,     0,     0,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    90,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,   396,   395,     0,     0,   343,
     344,   349,   350,     0,     0,     0,   408,     0,     0,     0,
       0,     0,   448,     0,     0,     0,   468,   455,   457,   458,
     320,   320,   430,     0,     0,    59,    61,     0,   138,   139,
     135,   141,    92,    94,     0,    86,    87,   143,     0,     0,
       0,     0,   120,   121,     0,   351,   286,   287,   289,   290,
     291,   300,   301,     0,   302,   211,   212,   184,     0,   240,
     243,   253,   150,   151,     0,   153,   256,   257,     0,   155,
     262,   167,     0,   263,     0,   265,   179,   173,     0,     0,
     190,     0,     0,   294,   180,     0,   296,   182,   207,     0,
     499,   501,   380,   383,   374,   423,   489,     0,   488,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     0,
     315,   317,    75,     0,     0,     0,     0,     0,     0,     0,
       0,    91,   354,   355,     0,   352,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,   369,    16,   122,
       0,   421,   493,     0,   490,     0,     0,     0,   460,     0,
     470,     0,     0,   459,   433,   435,   431,    95,    63,    85,
     130,   131,     0,   129,   119,     0,     0,     0,   329,   303,
       0,   152,   156,   264,   266,   270,   189,   293,   295,     0,
     360,   381,     9,   427,    16,   409,     0,     0,     0,   453,
     472,     0,   480,   462,     0,   480,     0,   469,     0,   356,
     357,   353,    16,     0,   370,    16,   428,   424,   422,     0,
       0,     0,     0,   480,     0,     0,   480,     0,     0,     0,
     128,     9,   185,   361,    16,   416,   413,   414,   415,   411,
     412,   410,     0,   494,     0,   491,     0,     0,   461,     0,
       0,   471,     0,   332,   331,   330,     0,   425,     0,     0,
     473,     0,   474,   463,     0,   464,   364,   366,   367,   368,
     363,   365,   371,   423,   495,   492,     0,   480,     0,   480,
     372,   362,   426,   476,     0,   466,     0,   480,   475,   480,
     465,     0,     0,   477,   467
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1032, -1032, -1032,  -202, -1032, -1032,  1246,   536, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032,  1199,  -267, -1032, -1032,  -189,
     845, -1032,  1200,    -2, -1032, -1032,   942,  -311,    96, -1032,
     791,   -37,     7, -1032,     3,     9,    53, -1032, -1032,   612,
    1261, -1032, -1032, -1032, -1032, -1032, -1032, -1032,   622, -1032,
     618, -1032,   161, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032,   328, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,    69,
   -1032, -1032, -1032,  -796, -1032, -1032, -1032,   807, -1032, -1032,
     419,   795, -1032, -1032, -1032, -1032, -1032, -1032, -1032, -1032,
   -1032, -1032, -1032, -1032, -1032, -1031, -1032,    24, -1032, -1032
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    71,    72,   297,   719,    73,    74,   212,   213,
     644,   645,   229,   482,    75,    76,   485,    77,    78,   495,
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
     186,   486,   424,   248,    80,   529,   450,   194,   675,   451,
      81,   676,   483,   195,  1092,   211,   492,   493,   483,   415,
     444,   934,   208,   209,   224,   198,   225,   226,   223,   197,
     456,   231,   457,   458,   235,   237,   239,   220,  1183,    91,
     255,   255,   255,    94,    95,    96,   244,   262,   250,   935,
     276,   277,   278,   279,   200,   483,   270,  1184,     7,     8,
     194,   275,   957,   958,   398,   255,   195,   260,   261,   298,
     299,   609,    20,   219,    91,  1029,   217,    25,    94,    95,
      96,   689,   398,     7,     8,   300,   271,   272,   273,   712,
     398,   292,   409,   286,   274,   783,  1119,   784,   496,   497,
     308,  1155,   476,   398,  1158,   398,   400,   401,   803,   816,
     804,   817,   769,   402,   403,   404,   405,   406,   407,   408,
     409,   287,  1176,   398,   398,  1179,   400,   401,   408,   409,
     773,   781,   285,   402,   403,   404,   405,   406,   407,   408,
     409,   398,   398,   267,   268,   269,   400,   401,   786,   787,
     199,   232,   233,   402,   403,   404,   405,   406,   407,   408,
     409,   391,   392,   393,   394,   395,   396,   397,   227,   398,
     398,   240,   241,   288,   459,   810,  1214,   811,  1216,   201,
     388,   390,   398,    57,   409,   289,  1221,   848,  1222,   849,
      62,    63,    64,   603,   398,   605,   418,   205,   296,   484,
     206,   423,   452,   301,   677,   484,   302,    80,   470,   471,
     412,   413,   290,    81,   438,    62,    63,    64,   819,   442,
     820,   303,  1022,   703,  1023,    80,   454,   398,   398,   245,
     246,    81,   955,   993,   956,   994,   410,   411,   412,   413,
     721,   722,   484,   398,   663,   410,   411,   412,   413,   473,
    1093,   475,   419,  1096,   421,   398,   410,   411,   412,   413,
    1008,   416,  1009,   745,   245,   246,   391,   392,   393,   394,
     395,   396,   397,   199,   398,   398,   410,   411,   412,   413,
    1012,   788,  1013,   417,  1025,   398,  1026,   499,   391,   392,
     393,   394,   395,   396,   397,   201,  1137,   425,   426,   509,
     410,   411,   412,   413,   514,   515,   398,   516,   517,   518,
     519,   255,   255,   789,   429,   430,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   255,   543,   544,
     545,   546,   547,   548,   549,   550,   552,   522,   523,   407,
     408,   409,   558,   559,   561,   563,   564,   398,   566,   398,
     568,   304,  1014,   542,  1015,   422,   790,   512,   513,  1178,
     582,   481,  1181,   398,   305,   400,   255,   464,   488,   490,
     791,   594,   402,   403,   404,   405,   406,   407,   408,   409,
    1190,   398,   306,  1193,   398,   307,   427,   428,   792,  1040,
     398,   609,   589,   398,   506,   507,   508,   609,   503,   448,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   398,   530,   398,   398,   309,   735,  1218,   736,
    1220,   793,   794,   591,   592,  1223,  1224,   398,   310,   400,
     401,   311,   504,   878,   827,   248,   402,   403,   404,   405,
     406,   407,   408,   409,   398,   664,  1107,   398,  1108,    80,
     667,   798,  1172,   399,  1173,    81,   312,   410,   411,   412,
     413,   398,   398,   684,   685,   313,  1191,   398,  1192,   799,
     398,   314,   400,   401,   800,   315,   696,   807,   697,   402,
     403,   404,   405,   406,   407,   408,   409,   398,   398,   704,
     705,   706,   316,   770,   809,   410,   411,   412,   413,   714,
     716,   717,   718,   398,   928,   398,  -406,   930,   398,   398,
     822,   398,   823,   771,   772,   680,   681,   398,   991,   398,
     686,   687,   796,   400,   401,   469,  1011,   433,   434,   668,
     402,   403,   404,   405,   406,   407,   408,   409,   398,   398,
     398,   400,   401,   317,   797,  1016,  1146,  1024,   402,   403,
     404,   405,   406,   407,   408,   409,   524,   525,   318,   410,
     411,   412,   413,   400,   401,   405,   406,   407,   408,   409,
     402,   403,   404,   405,   406,   407,   408,   409,   398,   400,
     401,   699,   700,   812,   472,   702,   402,   403,   404,   405,
     406,   407,   408,   409,   319,   391,   392,   393,   394,   395,
     396,   397,   410,   411,   412,   413,   670,   671,   391,   392,
     393,   394,   395,   396,   397,   398,   398,   824,   825,   398,
     682,   683,  1027,  1028,   320,   984,  1038,   391,   392,   393,
     394,   395,   396,   397,   321,   398,   398,   828,   322,    80,
     946,   998,  1090,  1109,   398,    81,   323,   692,   693,   813,
     438,   829,   831,   410,   411,   412,   413,   398,   398,   398,
     398,   398,   324,   847,  1112,  1115,  1117,  1118,  1129,   854,
     855,   410,   411,   412,   413,   860,   406,   407,   408,   409,
     723,   724,   325,   398,   398,   410,   411,   412,   413,   873,
    1204,  1213,   398,   410,   411,   412,   413,   814,   477,   833,
     834,   326,   836,   837,   843,   844,   885,   886,   887,   410,
     411,   412,   413,   861,   862,   752,   398,   753,   891,   398,
     398,   815,    80,   478,   501,   818,   895,   896,    81,   897,
     898,   899,   398,   927,   525,   327,   637,   328,   638,   776,
     639,   905,   906,    91,   908,   943,   944,    94,    95,    96,
     909,   398,   398,   910,   398,   329,   398,   821,   801,   876,
     884,   879,   398,   640,   330,   911,   641,  1053,   912,   913,
     914,   642,   915,   916,   331,   398,  1062,  1063,   400,   401,
    1060,   918,   332,  1082,  1083,   402,   403,   404,   405,   406,
     407,   408,   409,   400,   401,   410,   411,   412,   413,   880,
     402,   403,   404,   405,   406,   407,   408,   409,   923,   333,
     924,   925,   926,  1130,  1131,   334,   487,   892,   893,   335,
     336,   337,   400,   401,   933,   338,   339,   340,   341,   402,
     403,   404,   405,   406,   407,   408,   409,   342,   343,   344,
     345,   907,   346,   347,   947,    80,   348,   349,   192,   400,
     401,    81,   350,   351,   954,   494,   402,   403,   404,   405,
     406,   407,   408,   409,   352,   353,   214,   965,   966,   218,
     354,   355,   255,   255,   356,   357,  1121,  1122,   230,   974,
     975,   976,   236,   238,   358,   359,   360,   254,   361,   362,
     363,   391,   392,   393,   394,   395,   396,   397,   968,   969,
     364,   365,   366,   282,   283,   284,   505,   367,   410,   411,
     412,   413,   291,   293,   294,   295,   610,   368,   369,   370,
     963,   964,  1148,   410,   411,   412,   413,   371,   372,   755,
     502,   756,   403,   404,   405,   406,   407,   408,   409,   373,
    1161,   442,   374,  1163,  1030,  1031,  1037,   375,   376,   377,
     378,  1041,   410,   411,   412,   413,   379,   380,   777,   600,
     778,   403,  1187,   405,   406,   407,   408,   409,   381,   382,
     383,   655,   601,   656,   972,   657,   384,   385,  1058,   410,
     411,   412,   413,   386,   387,   980,   409,   981,   402,   403,
     404,   405,   406,   407,   408,   409,  1067,   447,   658,   449,
     462,   659,  1068,  1165,   463,  1166,   660,  1167,   467,   468,
    1070,   633,  1071,  1047,  1048,   398,  1196,  1073,  1197,   634,
    1198,     1,     2,     3,     4,     5,   635,  1077,   389,   646,
    1168,   647,   648,  1169,   649,   651,   414,  1086,  1170,   650,
    1089,   652,   653,  1199,   662,   420,  1200,   665,   672,   673,
     678,  1201,  1098,   674,   410,   411,   412,   413,  1104,   707,
     739,   437,   740,   708,   709,   710,   441,   720,   726,   840,
     727,   734,   737,   453,   950,   738,   741,   742,  1123,   743,
    1061,    80,    80,   410,   411,   412,   413,    81,    81,  1136,
     744,   874,   875,   759,   802,   805,   806,   474,   856,  1033,
     865,   866,   867,   868,    -9,   871,   872,   479,  1143,   903,
     937,   410,   411,   412,   413,   904,   938,  1144,  1034,  1056,
     939,   940,   941,   942,   960,  1151,  1152,    80,   961,   400,
     401,   962,   977,    81,   985,   500,   402,   403,   404,   405,
     406,   407,   408,   409,   992,    80,   997,   510,    80,  1021,
    1039,    81,   400,   401,    81,  1180,  1044,  1182,   521,   402,
     403,   404,   405,   406,   407,   408,   409,    80,   400,   401,
    1050,  1051,  1189,    81,  1057,   402,   403,   404,   405,   406,
     407,   408,   409,  1059,   553,   554,   555,   556,   557,  1074,
    1080,   560,  1208,  1085,   565,  1091,   567,  1094,   569,   570,
     572,   574,   576,   578,   579,   580,   581,  1124,   583,   584,
     585,   586,   587,   588,   590,  1095,  1134,   593,  1105,   595,
     596,   597,   598,   599,  1106,  1126,   602,  1127,   604,  1138,
     606,   607,   608,  1139,  1140,  -384,   611,   612,   613,   614,
     615,   616,   617,   618,  1210,  1154,  1157,    91,    92,    93,
     193,    94,    95,    96,    97,   890,   280,   281,   528,   410,
     411,   412,   413,   690,   839,  1004,   196,  1005,  1141,   838,
     835,  1032,  1212,   952,    98,    99,   688,   698,     0,     0,
       0,     0,   410,   411,   412,   413,     0,     0,     0,     0,
     711,     0,     0,     0,   666,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   730,   100,   101,   102,
     103,   104,   105,   106,     0,     0,     0,     0,     0,     0,
       0,     0,   695,     0,     0,   107,     0,     0,   108,     0,
       0,     0,   701,   257,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,     0,   713,   715,     0,   109,
     110,     0,     0,   111,     0,   112,     0,     0,   259,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
       0,   164,   165,   166,   167,     0,   168,   169,     0,   170,
     171,   172,     0,   173,   174,   175,   176,   177,   178,   179,
       0,     0,     0,    93,     0,   180,   181,   182,    97,     0,
       0,     0,     0,     0,   183,     0,   253,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   400,   401,     0,     0,   437,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,     0,   852,   400,   401,   853,     0,     0,   857,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,     0,     0,     0,   111,     0,   112,
     400,   401,     0,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,     0,     0,     0,
     140,   141,   142,     0,   144,     0,   146,   147,   148,     0,
     900,     0,   902,   153,   154,   155,   156,     0,     0,   159,
       0,   161,     0,   163,     0,     0,   165,     0,   167,     0,
       0,   169,     0,     0,   171,   172,    93,   173,   174,     0,
     176,    97,   178,     0,     0,     0,     0,     0,     0,     0,
     181,     0,   917,   410,   411,   412,   413,     0,   191,   571,
       0,   747,    99,     0,     0,     0,     0,     0,     0,     0,
     919,   920,   921,     0,   410,   411,   412,   413,   922,     0,
       0,     0,   748,     0,     0,     0,     0,     0,     0,     0,
       0,   929,     0,     0,   931,     0,   932,     0,     0,     0,
     410,   411,   412,   413,     0,     0,   400,   401,   749,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,   400,   401,   949,     0,     0,   951,     0,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
     111,     0,   112,     0,     0,     0,     0,     0,   400,   401,
       0,   970,   971,     0,   973,   402,   403,   404,   405,   406,
     407,   408,   409,   982,   983,     0,     0,   134,   135,   136,
       0,     0,     0,   140,   141,   142,     0,   144,     0,   146,
     147,   148,     0,     0,     0,     0,   153,   154,   155,   156,
       0,     0,   159,     0,   161,     0,   163,     0,     0,   165,
       0,   167,     0,     0,   169,     0,     0,   171,   172,     0,
     173,   174,     0,   176,     0,   178,     0,     0,   441,     0,
       0,     0,     0,   181,     0,     0,     0,     0,     0,     0,
    1043,   191,   573,     0,     0,    93,   410,   411,   412,   413,
      97,     0,  1052,     0,   750,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413,     0,     0,     0,     0,   751,
       0,    99,     0,     0,     0,     0,     0,     0,  1066,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,  1069,     0,     0,   754,     0,     0,     0,
       0,     0,     0,  1072,   400,   401,     0,  1075,     0,     0,
    1076,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,   400,   401,  1087,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,  1097,     0,
    1099,  1100,  1101,     0,  1103,     0,     0,     0,     0,   111,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,     0,    94,
      95,    96,    97,     0,     0,     0,   134,   135,   136,     0,
       0,     0,   140,   141,   142,     0,   144,     0,   146,   147,
     148,     0,    98,    99,     0,   153,   154,   155,   156,     0,
       0,   159,     0,   161,     0,   163,     0,     0,   165,     0,
     167,  1150,     0,   169,     0,     0,   171,   172,     0,   173,
     174,     0,   176,  1160,   178,   100,   101,   102,   103,   104,
     105,   106,   181,     0,   410,   411,   412,   413,     0,  1177,
     191,   575,   757,   107,     0,     0,   108,     0,     0,     0,
       0,   251,     0,   410,   411,   412,   413,  1188,     0,     0,
     252,   758,     0,     0,     0,     0,     0,   109,   110,     0,
       0,   111,     0,   112,     0,     0,  1206,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,     0,   168,   169,     0,   170,   171,   172,
       0,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,     0,
       0,     0,   183,     0,   253,    91,    92,    93,     0,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   400,   401,   108,     0,     0,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     520,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,   111,     0,   112,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,     0,   168,   169,     0,   170,   171,   172,
       0,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,     0,
       0,     0,   183,     0,   253,    91,    92,    93,     0,    94,
      95,    96,    97,     0,   410,   411,   412,   413,     0,     0,
       0,     0,   760,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   400,   401,   108,     0,     0,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,   111,     0,   112,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,     0,   168,   169,     0,   170,   171,   172,
       0,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,     0,
       0,     0,   183,     0,   253,    91,    92,    93,     0,    94,
      95,    96,    97,     0,   410,   411,   412,   413,     0,     0,
       0,     0,   761,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,    93,     0,   108,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,     0,
      99,   111,     0,   112,     0,     0,     0,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,     0,   164,
     165,   166,   167,     0,   168,   169,     0,   170,   171,   172,
       0,   173,   174,   175,   176,   177,   178,   179,   111,     0,
     112,     0,     0,   180,   181,   182,     0,     0,     0,     0,
       0,     0,   183,   498,    91,    92,    93,     0,    94,    95,
      96,    97,     0,     0,     0,   134,   135,   136,     0,     0,
       0,   140,   141,   142,     0,   144,     0,   146,   147,   148,
       0,    98,    99,     0,   153,   154,   155,   156,     0,     0,
     159,     0,   161,     0,   163,     0,     0,   165,     0,   167,
       0,     0,   169,     0,     0,   171,   172,     0,   173,   174,
       0,   176,     0,   178,   100,   101,   102,   103,   104,   105,
     106,   181,     0,     0,     0,     0,     0,     0,     0,   191,
     577,     0,   107,    93,     0,   108,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,    99,
     111,     0,   112,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,     0,   168,   169,     0,   170,   171,   172,     0,
     173,   174,   175,   176,   177,   178,   179,   111,     0,   112,
       0,     0,   180,   181,   182,     0,     0,     0,     0,     0,
       0,   183,   551,    91,    92,    93,     0,    94,    95,    96,
      97,     0,     0,     0,   134,   135,   136,     0,     0,     0,
     140,   141,   142,     0,   144,     0,   146,   147,   148,     0,
      98,    99,     0,   153,   154,   155,   156,     0,     0,   159,
       0,   161,     0,   163,     0,     0,   165,     0,   167,     0,
       0,   169,     0,     0,   171,   172,     0,   173,   174,     0,
     176,     0,   178,   100,   101,   102,   103,   104,   105,   106,
     181,     0,     0,     0,     0,     0,     0,     0,   191,     0,
       0,   107,    93,     0,   108,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,    99,   111,
       0,   112,     0,     0,     0,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,     0,   164,   165,   166,
     167,     0,   168,   169,     0,   170,   171,   172,     0,   173,
     174,   175,   176,   177,   178,   179,   111,     0,   112,     0,
       0,   180,   181,   182,     0,     0,     0,     0,     0,     0,
     183,   562,    91,    92,    93,     0,    94,    95,    96,    97,
       0,   265,     0,   134,   135,   136,     0,     0,     0,   140,
     141,   142,     0,   144,     0,   146,   147,   148,     0,    98,
      99,     0,   153,   154,   155,   156,     0,     0,   159,     0,
     161,     0,   163,     0,     0,   165,     0,   167,     0,     0,
     169,     0,   266,   171,   172,     0,   173,   174,     0,   176,
       0,   178,   100,   101,   102,   103,   104,   105,   106,   181,
       0,     0,     0,     0,     0,     0,     0,   851,   400,   401,
     107,     0,     0,   108,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,   111,     0,
     112,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,     0,   164,   165,   166,   167,
       0,   168,   169,     0,   170,   171,   172,     0,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,     0,     0,
     180,   181,   182,     0,     0,     0,    91,    92,    93,   183,
      94,    95,    96,    97,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   762,     0,     0,     0,
       0,     0,     0,    98,    99,     0,     0,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,     0,     0,     0,     0,     0,
       0,   400,   401,     0,   107,     0,     0,   108,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
       0,     0,   111,     0,   112,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,     0,
     164,   165,   166,   167,     0,   168,   169,     0,   170,   171,
     172,     0,   173,   174,   175,   176,   177,   178,   179,     0,
       0,     0,     0,     0,   180,   181,   182,     0,     0,     0,
      91,    92,    93,   183,    94,    95,    96,    97,     0,   489,
       0,   410,   411,   412,   413,     0,     0,     0,     0,   763,
       0,     0,     0,     0,     0,     0,     0,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,   400,   401,     0,   107,     0,
       0,   108,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,     0,     0,   111,     0,   112,     0,
       0,     0,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,     0,   164,   165,   166,   167,     0,   168,
     169,     0,   170,   171,   172,     0,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,   180,   181,
     182,     0,     0,     0,    91,    92,    93,   183,    94,    95,
      96,    97,     0,     0,     0,   410,   411,   412,   413,     0,
       0,     0,     0,   764,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,   400,
     401,     0,   107,     0,     0,   108,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
     111,     0,   112,     0,     0,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,     0,   164,   165,
     166,   167,     0,   168,   169,     0,   170,   171,   172,     0,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
      93,     0,   180,   181,   182,    97,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,     0,   410,
     411,   412,   413,     0,     0,     0,    99,   765,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    93,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   694,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,     0,     0,     0,   140,   141,   142,
       0,   144,     0,   146,   147,   148,   901,     0,     0,     0,
     153,   154,   155,   156,     0,     0,   159,   111,   161,   112,
     163,     0,     0,   165,     0,   167,     0,     0,   169,     0,
       0,   171,   172,     0,   173,   174,     0,   176,     0,   178,
       0,     0,     0,     0,   134,   135,   136,   181,     0,     0,
     140,   141,   142,     0,   144,   191,   146,   147,   148,     0,
       0,     0,     0,   153,   154,   155,   156,     0,     0,   159,
       0,   161,     0,   163,     0,     0,   165,     0,   167,     0,
       0,   169,     0,     0,   171,   172,     0,   173,   174,     0,
     176,     0,   178,     0,     7,     8,     9,     0,     0,     0,
     181,    10,     0,     0,     0,    11,     0,    12,   191,    13,
      14,    15,    16,    17,  -335,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,  -122,  -122,    48,    49,    50,    51,     0,    52,
      53,    54,    55,    56,    57,     0,     0,    58,  -122,     0,
      59,     0,    60,    61,     0,     0,     0,     0,   400,   401,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,    62,    63,    64,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,    67,     0,     7,     8,
       9,    68,     0,     0,    69,    10,     0,     0,    70,    11,
       0,    12,     0,    13,    14,    15,    16,    17,  -335,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,   -16,   -16,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,   410,   411,
     412,   413,     0,    45,    46,    47,   766,     0,    48,    49,
      50,    51,     0,    52,    53,    54,    55,    56,    57,     0,
       0,    58,     0,     0,    59,     0,    60,    61,     0,     0,
       0,     0,   400,   401,     0,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
      62,    63,    64,     0,     0,     0,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,     0,     0,     0,
      67,     0,     7,     8,     9,    68,     0,     0,    69,    10,
       0,     0,    70,    11,     0,    12,     0,    13,    14,    15,
      16,    17,  -335,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,   -16,     0,     0,     0,
      29,   -16,     0,    30,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,   400,   401,     0,    37,
      38,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,   410,   411,   412,   413,     0,    45,    46,    47,
     768,     0,    48,    49,    50,    51,     0,    52,    53,    54,
      55,    56,    57,     0,     0,    58,   400,   401,    59,     0,
      60,    61,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    63,    64,   400,   401,     0,
       0,    65,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,     0,    67,     0,     0,     0,     0,    68,
     400,   401,    69,     0,     0,     0,    70,   402,   403,   404,
     405,   406,   407,   408,   409,     0,   410,   411,   412,   413,
     400,   401,     0,     0,   779,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,   400,   401,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
     400,   401,     0,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,   410,   411,   412,   413,
     400,   401,     0,     0,   780,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,   411,   412,
     413,   400,   401,     0,     0,   782,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   413,   400,   401,     0,     0,   785,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     410,   411,   412,   413,     0,     0,     0,     0,   808,     0,
       0,     0,     0,     0,     0,   410,   411,   412,   413,     0,
       0,     0,     0,   850,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   413,   400,   401,     0,     0,   959,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     410,   411,   412,   413,   400,   401,     0,     0,   978,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413,   400,   401,     0,     0,   979,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,   411,   412,   413,   400,   401,
       0,     0,   986,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   400,   401,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,   400,   401,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   400,   401,
       0,     0,   987,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   400,   401,
       0,     0,   988,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   410,   411,   412,   413,   400,
     401,     0,     0,   989,     0,     0,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,   990,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,   995,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,     0,     0,   996,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,   400,   401,     0,     0,   999,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,   400,   401,     0,     0,  1000,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
     411,   412,   413,   400,   401,     0,     0,  1001,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,   400,   401,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   400,   401,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,   411,   412,   413,   400,   401,     0,     0,
    1002,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,   410,   411,   412,   413,   400,   401,     0,     0,
    1003,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,   410,   411,   412,   413,   400,   401,     0,     0,
    1006,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,     0,
       0,  1007,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,     0,     0,     0,     0,  1010,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,     0,
       0,  1017,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,   413,
     400,   401,     0,     0,  1020,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,   410,   411,   412,   413,
     400,   401,     0,     0,  1036,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,   410,   411,   412,   413,
     400,   401,     0,     0,  1084,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,   400,   401,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
     400,   401,     0,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,   411,   412,
     413,   400,   401,     0,     0,  1088,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   413,   400,   401,     0,     0,  1102,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     410,   411,   412,   413,   400,   401,     0,     0,  1111,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     410,   411,   412,   413,     0,     0,     0,     0,  1113,     0,
       0,     0,     0,     0,     0,   410,   411,   412,   413,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   413,   400,   401,     0,     0,  1116,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413,   400,   401,     0,     0,  1133,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,   411,   412,   413,   400,   401,
       0,     0,  1162,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   400,   401,
       0,     0,  1175,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   400,   401,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,   400,   401,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   400,   401,
       0,     0,  1195,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   410,   411,   412,   413,   400,
     401,     0,     0,  1205,     0,     0,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,     0,     0,  1215,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,     0,     0,   465,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,   466,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,   480,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,   400,   401,   491,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
     411,   412,   413,   400,   401,   691,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,   411,   412,   413,   400,   401,   728,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,   400,   401,     0,     0,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   400,   401,     0,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,   410,   411,   412,   413,   400,   401,   729,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,   410,   411,   412,   413,   400,   401,   731,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,   400,   401,   732,
       0,     0,     0,     0,   402,   403,   404,   405,   406,   407,
     408,   409,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,   413,
       0,     0,   733,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413,     0,     0,   746,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,   413,
     400,   401,   767,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,   410,   411,   412,   413,
     400,   401,   774,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,   410,   411,   412,   413,
     400,   401,   775,     0,     0,     0,     0,   402,   403,   404,
     405,   406,   407,   408,   409,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   410,   411,   412,
     413,   400,   401,   795,     0,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,   400,   401,     0,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,   400,   401,     0,     0,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     410,   411,   412,   413,   400,   401,   846,     0,     0,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     410,   411,   412,   413,   400,   401,   869,     0,     0,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
     410,   411,   412,   413,   400,   401,   870,     0,     0,     0,
       0,   402,   403,   404,   405,   406,   407,   408,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413,     0,     0,   877,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,   413,
       0,     0,   881,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413,   400,   401,   882,     0,     0,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   409,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   410,   411,   412,   413,   400,   401,
     883,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   400,   401,
     888,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,   410,   411,   412,   413,   400,   401,
     889,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,   400,   401,     0,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,   400,   401,
       0,     0,     0,     0,     0,   402,   403,   404,   405,   406,
     407,   408,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   410,   411,   412,   413,   400,
     401,   948,     0,     0,     0,     0,   402,   403,   404,   405,
     406,   407,   408,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,   953,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,   400,   401,   967,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,   410,   411,
     412,   413,     0,     0,  1018,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,  1019,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     412,   413,   400,   401,  1042,     0,     0,     0,     0,   402,
     403,   404,   405,   406,   407,   408,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   410,
     411,   412,   413,   400,   401,  1054,     0,     0,     0,     0,
     402,   403,   404,   405,   406,   407,   408,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,   411,   412,   413,   400,   401,  1055,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,     0,   410,   411,   412,   413,   400,   401,  1110,     0,
       0,     0,     0,   402,   403,   404,   405,   406,   407,   408,
     409,   400,   401,     0,     0,     0,     0,     0,   402,   403,
     404,   405,   406,   407,   408,   409,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   410,   411,   412,   413,     0,     0,  1128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   410,   411,   412,   413,     0,     0,  1159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,   413,
       0,     0,  1174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   410,   411,   412,   413,
       0,     0,  1194,     0,     0,     0,     0,     0,     0,     0,
       0,   410,   411,   412,   413
};

static const yytype_int16 yycheck[] =
{
       2,   268,   204,    40,     1,   316,     4,     4,     4,     7,
       1,     7,    12,     4,  1045,    17,   283,   284,    12,    44,
     222,    16,    15,    16,    58,    75,    60,    61,    30,     0,
      58,    33,    60,    61,    36,    37,    38,     7,    25,     3,
      42,    43,    44,     7,     8,     9,    10,    88,    41,    44,
      52,    53,    54,    55,    75,    12,    59,    44,     4,     5,
      57,    96,   858,   859,   194,    67,    57,    43,    44,    92,
      93,   201,    28,    28,     3,    12,    23,    33,     7,     8,
       9,    10,   194,     4,     5,   108,    89,    90,    91,   201,
     194,    67,    77,   200,    97,   199,    13,   201,   287,   288,
     102,  1132,    11,   194,  1135,   194,    63,    64,   199,   199,
     201,   201,   201,    70,    71,    72,    73,    74,    75,    76,
      77,   200,  1153,   194,   194,  1156,    63,    64,    76,    77,
     201,   201,   114,    70,    71,    72,    73,    74,    75,    76,
      77,   194,   194,    47,    48,    49,    63,    64,   201,   201,
     200,     4,     5,    70,    71,    72,    73,    74,    75,    76,
      77,    70,    71,    72,    73,    74,    75,    76,   202,   194,
     194,     4,     5,   200,   202,   199,  1207,   201,  1209,   200,
     182,   183,   194,   104,    77,   200,  1217,   199,  1219,   201,
     136,   137,   138,   382,   194,   384,   198,     4,    44,   199,
       7,   203,   200,    75,   200,   199,    75,   204,   245,   246,
     195,   196,   200,   204,   216,   136,   137,   138,   199,   221,
     201,    24,   199,   490,   201,   222,   228,   194,   194,   193,
     194,   222,   199,   199,   201,   201,   193,   194,   195,   196,
     507,   508,   199,   194,   446,   193,   194,   195,   196,   251,
    1046,   253,   199,  1049,   201,   194,   193,   194,   195,   196,
     199,    44,   201,   530,   193,   194,    70,    71,    72,    73,
      74,    75,    76,   200,   194,   194,   193,   194,   195,   196,
     199,   201,   201,    44,   199,   194,   201,   289,    70,    71,
      72,    73,    74,    75,    76,   200,  1092,    35,    36,   301,
     193,   194,   195,   196,   306,   307,   194,   309,   310,   311,
     312,   313,   314,   201,     4,     5,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   313,   314,    75,
      76,    77,   344,   345,   346,   347,   348,   194,   350,   194,
     352,   200,   199,   329,   201,     4,   201,   304,   305,  1155,
     362,   265,  1158,   194,   200,    63,   368,   199,   272,   273,
     201,   373,    70,    71,    72,    73,    74,    75,    76,    77,
    1176,   194,   200,  1179,   194,   200,    20,    21,   201,   199,
     194,   201,   368,   194,   298,   299,   300,   201,   199,    58,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   194,   317,   194,   194,   200,   199,  1214,   201,
    1216,   201,   201,   370,   371,  1221,  1222,   194,   200,    63,
      64,   200,   199,   700,   636,   472,    70,    71,    72,    73,
      74,    75,    76,    77,   194,   447,   199,   194,   201,   446,
     452,   201,   199,    44,   201,   446,   200,   193,   194,   195,
     196,   194,   194,   465,   466,   200,   199,   194,   201,   201,
     194,   200,    63,    64,   201,   200,   478,   201,   480,    70,
      71,    72,    73,    74,    75,    76,    77,   194,   194,   491,
     492,   493,   200,   199,   201,   193,   194,   195,   196,   501,
     502,   503,   504,   194,   815,   194,    46,   818,   194,   194,
     201,   194,   201,   199,   199,   462,   463,   194,   201,   194,
     467,   468,   199,    63,    64,   199,   201,     4,     5,    51,
      70,    71,    72,    73,    74,    75,    76,    77,   194,   194,
     194,    63,    64,   200,   199,   201,    46,   201,    70,    71,
      72,    73,    74,    75,    76,    77,     4,     5,   200,   193,
     194,   195,   196,    63,    64,    73,    74,    75,    76,    77,
      70,    71,    72,    73,    74,    75,    76,    77,   194,    63,
      64,   485,   486,   199,   199,   489,    70,    71,    72,    73,
      74,    75,    76,    77,   200,    70,    71,    72,    73,    74,
      75,    76,   193,   194,   195,   196,   198,   199,    70,    71,
      72,    73,    74,    75,    76,   194,   194,   619,   620,   194,
       4,     5,   201,   201,   200,   892,   201,    70,    71,    72,
      73,    74,    75,    76,   200,   194,   194,   639,   200,   636,
     842,   908,   201,   201,   194,   636,   200,    86,    87,   199,
     652,   644,   645,   193,   194,   195,   196,   194,   194,   194,
     194,   194,   200,   665,   201,   201,   201,   201,   201,   671,
     672,   193,   194,   195,   196,   677,    74,    75,    76,    77,
       4,     5,   200,   194,   194,   193,   194,   195,   196,   691,
     201,   201,   194,   193,   194,   195,   196,   199,   199,   646,
     647,   200,   649,   650,    49,    50,   708,   709,   710,   193,
     194,   195,   196,     4,     5,   199,   194,   201,   720,   194,
     194,   199,   719,   199,   199,   199,   728,   729,   719,   731,
     732,   733,   194,     4,     5,   200,    14,   200,    16,   201,
      18,   743,   744,     3,   746,    39,    40,     7,     8,     9,
     752,   194,   194,   755,   194,   200,   194,   199,   201,   199,
     707,   199,   194,    41,   200,   767,    44,   199,   770,   771,
     772,    49,   774,   775,   200,   194,     4,     5,    63,    64,
     199,   783,   200,    60,    61,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,   193,   194,   195,   196,   703,
      70,    71,    72,    73,    74,    75,    76,    77,   810,   200,
     812,   813,   814,    60,    61,   200,   199,   721,   722,   200,
     200,   200,    63,    64,   826,   200,   200,   200,   200,    70,
      71,    72,    73,    74,    75,    76,    77,   200,   200,   200,
     200,   745,   200,   200,   846,   842,   200,   200,     3,    63,
      64,   842,   200,   200,   856,     5,    70,    71,    72,    73,
      74,    75,    76,    77,   200,   200,    21,   869,   870,    24,
     200,   200,   874,   875,   200,   200,  1078,  1079,    33,   881,
     882,   883,    37,    38,   200,   200,   200,    42,   200,   200,
     200,    70,    71,    72,    73,    74,    75,    76,   874,   875,
     200,   200,   200,    58,    59,    60,    43,   200,   193,   194,
     195,   196,    67,    68,    69,    70,   201,   200,   200,   200,
     867,   868,  1124,   193,   194,   195,   196,   200,   200,   199,
     199,   201,    71,    72,    73,    74,    75,    76,    77,   200,
    1142,   943,   200,  1145,   937,   938,   948,   200,   200,   200,
     200,   953,   193,   194,   195,   196,   200,   200,   199,   201,
     201,    71,  1164,    73,    74,    75,    76,    77,   200,   200,
     200,    14,   201,    16,   878,    18,   200,   200,   980,   193,
     194,   195,   196,   200,   200,   199,    77,   201,    70,    71,
      72,    73,    74,    75,    76,    77,   998,   200,    41,   200,
     200,    44,  1004,    14,   200,    16,    49,    18,   200,   200,
    1012,   201,  1014,   960,   961,   194,    14,  1019,    16,   201,
      18,   186,   187,   188,   189,   190,    75,  1029,   183,   200,
      41,   200,   199,    44,   200,   199,   191,  1039,    49,   200,
    1042,   199,    43,    41,    46,   200,    44,   200,   200,    58,
      10,    49,  1054,   200,   193,   194,   195,   196,  1060,   200,
     200,   216,   200,   199,   199,   199,   221,   199,   201,    43,
     201,   201,   199,   228,    58,   201,   201,   201,  1080,   199,
     984,  1078,  1079,   193,   194,   195,   196,  1078,  1079,  1091,
     199,    85,    85,   201,   201,   201,   201,   252,   200,    43,
     201,   201,   200,   200,    43,   201,   201,   262,  1110,   201,
     199,   193,   194,   195,   196,   201,   199,  1119,    38,    75,
     201,   201,   201,   201,   200,  1127,  1128,  1124,   200,    63,
      64,   199,   201,  1124,   200,   290,    70,    71,    72,    73,
      74,    75,    76,    77,   201,  1142,   201,   302,  1145,   200,
     200,  1142,    63,    64,  1145,  1157,    58,  1159,   313,    70,
      71,    72,    73,    74,    75,    76,    77,  1164,    63,    64,
     201,   201,  1174,  1164,    75,    70,    71,    72,    73,    74,
      75,    76,    77,    75,   339,   340,   341,   342,   343,   201,
      48,   346,  1194,    58,   349,   200,   351,   201,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    47,   363,   364,
     365,   366,   367,   368,   369,   201,    58,   372,   200,   374,
     375,   376,   377,   378,   200,   200,   381,   200,   383,    75,
     385,   386,   387,   201,   201,    38,   391,   392,   393,   394,
     395,   396,   397,   398,     4,   200,   200,     3,     4,     5,
       4,     7,     8,     9,    10,   719,    57,    57,   316,   193,
     194,   195,   196,   472,   652,   199,     5,   201,  1107,   651,
     648,   943,  1203,   854,    30,    31,   469,   482,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
     201,    -1,    -1,    -1,   449,    -1,    -1,    -1,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   477,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,   487,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,   501,   502,    -1,   105,
     106,    -1,    -1,   109,    -1,   111,    -1,    -1,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
      -1,   167,   168,   169,   170,    -1,   172,   173,    -1,   175,
     176,   177,    -1,   179,   180,   181,   182,   183,   184,   185,
      -1,    -1,    -1,     5,    -1,   191,   192,   193,    10,    -1,
      -1,    -1,    -1,    -1,   200,    -1,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,   652,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   668,    63,    64,   671,    -1,    -1,   674,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,    -1,
     142,   143,   144,    -1,   146,    -1,   148,   149,   150,    -1,
     735,    -1,   737,   155,   156,   157,   158,    -1,    -1,   161,
      -1,   163,    -1,   165,    -1,    -1,   168,    -1,   170,    -1,
      -1,   173,    -1,    -1,   176,   177,     5,   179,   180,    -1,
     182,    10,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     192,    -1,   777,   193,   194,   195,   196,    -1,   200,   201,
      -1,   201,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     795,   796,   797,    -1,   193,   194,   195,   196,   803,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   816,    -1,    -1,   819,    -1,   821,    -1,    -1,    -1,
     193,   194,   195,   196,    -1,    -1,    63,    64,   201,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,   848,    -1,    -1,   851,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     109,    -1,   111,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,   876,   877,    -1,   879,    70,    71,    72,    73,    74,
      75,    76,    77,   888,   889,    -1,    -1,   136,   137,   138,
      -1,    -1,    -1,   142,   143,   144,    -1,   146,    -1,   148,
     149,   150,    -1,    -1,    -1,    -1,   155,   156,   157,   158,
      -1,    -1,   161,    -1,   163,    -1,   165,    -1,    -1,   168,
      -1,   170,    -1,    -1,   173,    -1,    -1,   176,   177,    -1,
     179,   180,    -1,   182,    -1,   184,    -1,    -1,   943,    -1,
      -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     955,   200,   201,    -1,    -1,     5,   193,   194,   195,   196,
      10,    -1,   967,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,   993,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    -1,  1008,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,  1018,    63,    64,    -1,  1022,    -1,    -1,
    1025,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    63,    64,  1040,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,  1053,    -1,
    1055,  1056,  1057,    -1,  1059,    -1,    -1,    -1,    -1,   109,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,   136,   137,   138,    -1,
      -1,    -1,   142,   143,   144,    -1,   146,    -1,   148,   149,
     150,    -1,    30,    31,    -1,   155,   156,   157,   158,    -1,
      -1,   161,    -1,   163,    -1,   165,    -1,    -1,   168,    -1,
     170,  1126,    -1,   173,    -1,    -1,   176,   177,    -1,   179,
     180,    -1,   182,  1138,   184,    63,    64,    65,    66,    67,
      68,    69,   192,    -1,   193,   194,   195,   196,    -1,  1154,
     200,   201,   201,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,   193,   194,   195,   196,  1172,    -1,    -1,
      98,   201,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,  1191,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,   169,   170,    -1,   172,   173,    -1,   175,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,   202,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    63,    64,    84,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,   169,   170,    -1,   172,   173,    -1,   175,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,   202,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    63,    64,    84,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,   109,    -1,   111,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,   169,   170,    -1,   172,   173,    -1,   175,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,   202,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,   193,   194,   195,   196,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,     5,    -1,    84,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      31,   109,    -1,   111,    -1,    -1,    -1,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    -1,   167,
     168,   169,   170,    -1,   172,   173,    -1,   175,   176,   177,
      -1,   179,   180,   181,   182,   183,   184,   185,   109,    -1,
     111,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,
      -1,   142,   143,   144,    -1,   146,    -1,   148,   149,   150,
      -1,    30,    31,    -1,   155,   156,   157,   158,    -1,    -1,
     161,    -1,   163,    -1,   165,    -1,    -1,   168,    -1,   170,
      -1,    -1,   173,    -1,    -1,   176,   177,    -1,   179,   180,
      -1,   182,    -1,   184,    63,    64,    65,    66,    67,    68,
      69,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,    -1,    81,     5,    -1,    84,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    31,
     109,    -1,   111,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
     169,   170,    -1,   172,   173,    -1,   175,   176,   177,    -1,
     179,   180,   181,   182,   183,   184,   185,   109,    -1,   111,
      -1,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   201,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,   136,   137,   138,    -1,    -1,    -1,
     142,   143,   144,    -1,   146,    -1,   148,   149,   150,    -1,
      30,    31,    -1,   155,   156,   157,   158,    -1,    -1,   161,
      -1,   163,    -1,   165,    -1,    -1,   168,    -1,   170,    -1,
      -1,   173,    -1,    -1,   176,   177,    -1,   179,   180,    -1,
     182,    -1,   184,    63,    64,    65,    66,    67,    68,    69,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,
      -1,    81,     5,    -1,    84,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    31,   109,
      -1,   111,    -1,    -1,    -1,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,    -1,   167,   168,   169,
     170,    -1,   172,   173,    -1,   175,   176,   177,    -1,   179,
     180,   181,   182,   183,   184,   185,   109,    -1,   111,    -1,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,    -1,
     200,   201,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,   136,   137,   138,    -1,    -1,    -1,   142,
     143,   144,    -1,   146,    -1,   148,   149,   150,    -1,    30,
      31,    -1,   155,   156,   157,   158,    -1,    -1,   161,    -1,
     163,    -1,   165,    -1,    -1,   168,    -1,   170,    -1,    -1,
     173,    -1,    53,   176,   177,    -1,   179,   180,    -1,   182,
      -1,   184,    63,    64,    65,    66,    67,    68,    69,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    63,    64,
      81,    -1,    -1,    84,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   105,   106,    -1,    -1,   109,    -1,
     111,    -1,    -1,    -1,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,    -1,   167,   168,   169,   170,
      -1,   172,   173,    -1,   175,   176,   177,    -1,   179,   180,
     181,   182,   183,   184,   185,    -1,    -1,    -1,    -1,    -1,
     191,   192,   193,    -1,    -1,    -1,     3,     4,     5,   200,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    81,    -1,    -1,    84,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,    -1,   111,    -1,    -1,    -1,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,    -1,
     167,   168,   169,   170,    -1,   172,   173,    -1,   175,   176,
     177,    -1,   179,   180,   181,   182,   183,   184,   185,    -1,
      -1,    -1,    -1,    -1,   191,   192,   193,    -1,    -1,    -1,
       3,     4,     5,   200,     7,     8,     9,    10,    -1,    12,
      -1,   193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    81,    -1,
      -1,    84,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,   109,    -1,   111,    -1,
      -1,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    -1,   167,   168,   169,   170,    -1,   172,
     173,    -1,   175,   176,   177,    -1,   179,   180,   181,   182,
     183,   184,   185,    -1,    -1,    -1,    -1,    -1,   191,   192,
     193,    -1,    -1,    -1,     3,     4,     5,   200,     7,     8,
       9,    10,    -1,    -1,    -1,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    81,    -1,    -1,    84,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,    -1,   111,    -1,    -1,    -1,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,    -1,   167,   168,
     169,   170,    -1,   172,   173,    -1,   175,   176,   177,    -1,
     179,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
       5,    -1,   191,   192,   193,    10,    -1,    -1,    -1,    -1,
      -1,   200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,    -1,    -1,    -1,    31,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,   137,   138,    -1,    -1,    -1,   142,   143,   144,
      -1,   146,    -1,   148,   149,   150,    98,    -1,    -1,    -1,
     155,   156,   157,   158,    -1,    -1,   161,   109,   163,   111,
     165,    -1,    -1,   168,    -1,   170,    -1,    -1,   173,    -1,
      -1,   176,   177,    -1,   179,   180,    -1,   182,    -1,   184,
      -1,    -1,    -1,    -1,   136,   137,   138,   192,    -1,    -1,
     142,   143,   144,    -1,   146,   200,   148,   149,   150,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,    -1,    -1,   161,
      -1,   163,    -1,   165,    -1,    -1,   168,    -1,   170,    -1,
      -1,   173,    -1,    -1,   176,   177,    -1,   179,   180,    -1,
     182,    -1,   184,    -1,     4,     5,     6,    -1,    -1,    -1,
     192,    11,    -1,    -1,    -1,    15,    -1,    17,   200,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,   108,    -1,
     110,    -1,   112,   113,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   136,   137,   138,    -1,
      -1,    -1,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,    -1,    -1,    -1,   166,    -1,     4,     5,
       6,   171,    -1,    -1,   174,    11,    -1,    -1,   178,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,   193,   194,
     195,   196,    -1,    89,    90,    91,   201,    -1,    94,    95,
      96,    97,    -1,    99,   100,   101,   102,   103,   104,    -1,
      -1,   107,    -1,    -1,   110,    -1,   112,   113,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     136,   137,   138,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
     166,    -1,     4,     5,     6,   171,    -1,    -1,   174,    11,
      -1,    -1,   178,    15,    -1,    17,    -1,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,
      42,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    63,    64,    -1,    61,
      62,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,   193,   194,   195,   196,    -1,    89,    90,    91,
     201,    -1,    94,    95,    96,    97,    -1,    99,   100,   101,
     102,   103,   104,    -1,    -1,   107,    63,    64,   110,    -1,
     112,   113,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,   137,   138,    63,    64,    -1,
      -1,   143,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,   171,
      63,    64,   174,    -1,    -1,    -1,   178,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   193,   194,   195,   196,
      63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   193,   194,   195,   196,
      63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
     196,    63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,    63,    64,    -1,    -1,   201,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,    63,    64,    -1,    -1,   201,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     193,   194,   195,   196,    63,    64,    -1,    -1,   201,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    63,    64,    -1,    -1,   201,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,   195,   196,    63,    64,
      -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   193,   194,   195,   196,    63,    64,
      -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   193,   194,   195,   196,    63,    64,
      -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,    63,
      64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    63,    64,    -1,    -1,   201,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   193,   194,
     195,   196,    63,    64,    -1,    -1,   201,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   193,   194,
     195,   196,    63,    64,    -1,    -1,   201,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,    63,    64,    -1,    -1,   201,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,    63,    64,    -1,    -1,
     201,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   193,   194,   195,   196,    63,    64,    -1,    -1,
     201,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   193,   194,   195,   196,    63,    64,    -1,    -1,
     201,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    63,    64,    -1,
      -1,   201,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
      63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   193,   194,   195,   196,
      63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   193,   194,   195,   196,
      63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
     196,    63,    64,    -1,    -1,   201,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,    63,    64,    -1,    -1,   201,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     193,   194,   195,   196,    63,    64,    -1,    -1,   201,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,    -1,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,    63,    64,    -1,    -1,   201,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    63,    64,    -1,    -1,   201,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,   195,   196,    63,    64,
      -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   193,   194,   195,   196,    63,    64,
      -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   193,   194,   195,   196,    63,    64,
      -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,    63,
      64,    -1,    -1,   201,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    63,    64,    -1,    -1,   201,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   193,   194,
     195,   196,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   193,   194,
     195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,    63,    64,   199,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   193,   194,   195,   196,    63,    64,   199,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   193,   194,   195,   196,    63,    64,   199,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    63,    64,   199,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
      63,    64,   199,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   193,   194,   195,   196,
      63,    64,   199,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   193,   194,   195,   196,
      63,    64,   199,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,
     196,    63,    64,   199,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,   195,   196,    63,    64,   199,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     193,   194,   195,   196,    63,    64,   199,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     193,   194,   195,   196,    63,    64,   199,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196,    63,    64,   199,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,   195,   196,    63,    64,
     199,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   193,   194,   195,   196,    63,    64,
     199,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   193,   194,   195,   196,    63,    64,
     199,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,    63,
      64,   199,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   193,   194,
     195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   193,   194,
     195,   196,    -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
     195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,   195,   196,    63,    64,   199,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,    63,    64,   199,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   193,   194,   195,   196,    63,    64,   199,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,   195,   196,    -1,    -1,   199,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,   195,   196,    -1,    -1,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,   195,   196,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,   195,   196
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   186,   187,   188,   189,   190,   204,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    97,    99,   100,   101,   102,   103,   104,   107,   110,
     112,   113,   136,   137,   138,   143,   162,   166,   171,   174,
     178,   205,   206,   209,   210,   217,   218,   220,   221,   225,
     237,   238,   243,   249,   256,   264,   272,   275,   279,   282,
     288,     3,     4,     5,     7,     8,     9,    10,    30,    31,
      63,    64,    65,    66,    67,    68,    69,    81,    84,   105,
     106,   109,   111,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   167,   168,   169,   170,   172,   173,
     175,   176,   177,   179,   180,   181,   182,   183,   184,   185,
     191,   192,   193,   200,   223,   224,   226,   232,   234,   237,
     238,   200,   223,   209,   237,   238,   243,     0,    75,   200,
      75,   200,   257,   276,   280,     4,     7,   235,   235,   235,
      34,   226,   211,   212,   223,   239,   240,   239,   223,    28,
       7,   265,   273,   226,    58,    60,    61,   202,   319,   215,
     223,   226,     4,     5,   236,   226,   223,   226,   223,   226,
       4,     5,   299,   300,    10,   193,   194,   233,   234,   301,
     235,    89,    98,   202,   223,   226,   320,    89,    98,   114,
     320,   320,    88,   226,   231,    12,    53,   231,   231,   231,
      59,    89,    90,    91,    97,    96,   226,   226,   226,   226,
     218,   225,   223,   223,   223,   114,   200,   200,   200,   200,
     200,   223,   320,   223,   223,   223,    44,   207,    92,    93,
     108,    75,    75,    24,   200,   200,   200,   200,   226,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   226,   223,
     226,    70,    71,    72,    73,    74,    75,    76,   194,    44,
      63,    64,    70,    71,    72,    73,    74,    75,    76,    77,
     193,   194,   195,   196,   223,    44,    44,    44,   226,   239,
     223,   239,     4,   226,   206,    35,    36,    20,    21,     4,
       5,   250,   251,     4,     5,   252,   253,   223,   226,   241,
     242,   223,   226,   267,   206,   283,   289,   200,    58,   200,
       4,     7,   200,   223,   226,   302,    58,    60,    61,   202,
     304,   317,   200,   200,   199,   199,   199,   200,   200,   199,
     234,   234,   199,   226,   223,   226,    11,   199,   199,   223,
     199,   231,   216,    12,   199,   219,   219,   199,   231,    12,
     231,   199,   219,   219,     5,   222,   222,   222,   201,   226,
     223,   199,   199,   199,   199,    43,   231,   231,   231,   226,
     223,   244,   239,   239,   226,   226,   226,   226,   226,   226,
      98,   223,   320,   320,     4,     5,   229,   230,   229,   230,
     231,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   320,   226,   226,   226,   226,   226,   226,   226,
     226,   201,   226,   223,   223,   223,   223,   223,   226,   226,
     223,   226,   201,   226,   226,   223,   226,   223,   226,   223,
     223,   201,   223,   201,   223,   201,   223,   201,   223,   223,
     223,   223,   226,   223,   223,   223,   223,   223,   223,   320,
     223,   239,   239,   223,   226,   223,   223,   223,   223,   223,
     201,   201,   223,   222,   223,   222,   223,   223,   223,   201,
     201,   223,   223,   223,   223,   223,   223,   223,   223,   228,
     227,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   201,   201,    75,   277,    14,    16,    18,
      41,    44,    49,   281,   213,   214,   200,   200,   199,   200,
     200,   199,   199,    43,   266,    14,    16,    18,    41,    44,
      49,   274,    46,   206,   226,   200,   223,   226,    51,   303,
     198,   199,   200,    58,   200,     4,     7,   200,    10,   318,
     239,   239,     4,     5,   226,   226,   239,   239,   300,    10,
     233,   199,    86,    87,    98,   223,   226,   226,   304,   231,
     231,   223,   231,   219,   226,   226,   226,   200,   199,   199,
     199,   201,   201,   223,   226,   223,   226,   226,   226,   208,
     199,   219,   219,     4,     5,   248,   201,   201,   199,   199,
     201,   199,   199,   199,   201,   199,   201,   199,   201,   200,
     200,   201,   201,   199,   199,   219,   199,   201,   201,   201,
     201,   201,   199,   201,   201,   199,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   199,   201,   201,
     199,   199,   199,   201,   199,   199,   201,   199,   201,   201,
     201,   201,   201,   199,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   199,   199,   199,   201,   201,
     201,   201,   201,   199,   201,   201,   201,   201,   201,   201,
     199,   201,   199,   199,   199,   199,   199,   201,   199,   199,
     201,   199,   201,   201,   226,   226,   258,   206,   226,   235,
     321,   235,   322,   239,   239,   251,   239,   239,   253,   242,
      43,   268,   284,    49,    50,   290,   199,   226,   199,   201,
     201,   200,   223,   223,   226,   226,   200,   223,   305,   306,
     226,     4,     5,   296,   298,   201,   201,   200,   200,   199,
     199,   201,   201,   226,    85,    85,   199,   199,   219,   199,
     231,   199,   199,   199,   239,   226,   226,   226,   199,   199,
     210,   226,   231,   231,   245,   226,   226,   226,   226,   226,
     223,    98,   223,   201,   201,   226,   226,   231,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   223,   226,   223,
     223,   223,   223,   226,   226,   226,   226,     4,   230,   223,
     230,   223,   223,   226,    16,    44,   278,   199,   199,   201,
     201,   201,   201,    39,    40,   270,   206,   226,   199,   223,
      58,   223,   303,   199,   226,   199,   201,   296,   296,   201,
     200,   200,   199,   239,   239,   226,   226,   199,   320,   320,
     223,   223,   231,   223,   226,   226,   226,   201,   201,   201,
     199,   201,   223,   223,   219,   200,   201,   201,   201,   201,
     201,   201,   201,   199,   201,   201,   201,   201,   219,   201,
     201,   201,   201,   201,   199,   201,   201,   201,   199,   201,
     201,   201,   199,   201,   199,   201,   201,   201,   199,   199,
     201,   200,   199,   201,   201,   199,   201,   201,   201,    12,
     235,   235,   267,    43,    38,   285,   201,   226,   201,   200,
     199,   226,   199,   223,    58,   312,   307,   239,   239,   297,
     201,   201,   223,   199,   199,   199,    75,    75,   226,    75,
     199,   231,     4,     5,   254,   255,   223,   226,   226,   223,
     226,   226,   223,   226,   201,   223,   223,   226,   269,   271,
      48,   292,    60,    61,   201,    58,   226,   223,   201,   226,
     201,   200,   318,   296,   201,   201,   296,   223,   226,   223,
     223,   223,   201,   223,   226,   200,   200,   199,   201,   201,
     199,   201,   201,   201,   201,   201,   201,   201,   201,    13,
     262,   206,   206,   226,    47,   291,   200,   200,   199,   201,
      60,    61,   308,   201,    58,   313,   226,   296,    75,   201,
     201,   255,   246,   226,   226,   259,    46,   295,   206,   286,
     223,   226,   226,   314,   200,   318,   309,   200,   318,   199,
     223,   206,   201,   206,   293,    14,    16,    18,    41,    44,
      49,   287,   199,   201,   199,   201,   318,   223,   296,   318,
     226,   296,   226,    25,    44,   247,   260,   206,   223,   226,
     296,   199,   201,   296,   199,   201,    14,    16,    18,    41,
      44,    49,   261,   294,   201,   201,   223,   315,   226,   310,
       4,   263,   292,   201,   318,   201,   318,   316,   296,   311,
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
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   217,   217,   217,   217,   217,   218,   218,   218,
     218,   218,   218,   219,   219,   220,   220,   220,   220,   220,
     221,   221,   222,   222,   223,   223,   223,   223,   223,   223,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   225,   225,   227,   226,   228,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     229,   230,   230,   231,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   233,   233,   233,   234,   234,
     234,   234,   235,   235,   236,   236,   236,   236,   237,   238,
     240,   239,   241,   241,   241,   242,   242,   244,   245,   246,
     243,   247,   247,   248,   248,   249,   249,   249,   249,   250,
     250,   251,   251,   251,   251,   252,   252,   253,   253,   253,
     253,   254,   254,   254,   255,   255,   255,   255,   257,   258,
     259,   260,   256,   261,   261,   261,   261,   261,   261,   262,
     262,   263,   263,   265,   264,   266,   266,   267,   267,   268,
     269,   268,   270,   271,   270,   273,   272,   274,   274,   274,
     274,   274,   274,   276,   277,   275,   278,   278,   280,   279,
     281,   281,   281,   281,   281,   281,   283,   284,   285,   286,
     282,   287,   287,   287,   287,   287,   287,   289,   288,   290,
     290,   291,   291,   292,   293,   294,   292,   295,   295,   296,
     297,   296,   298,   298,   298,   298,   299,   299,   300,   300,
     300,   300,   301,   301,   301,   301,   302,   302,   302,   302,
     302,   303,   303,   303,   305,   304,   306,   304,   307,   304,
     308,   304,   309,   304,   310,   304,   311,   304,   312,   304,
     313,   304,   314,   304,   315,   304,   316,   304,   317,   304,
     318,   318,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   320,   320,   321,   321,
     322,   322
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
       2,     6,     2,     8,     2,     2,     2,     2,     1,     2,
       1,     2,     2,     2,     5,     7,     3,     2,     3,     4,
       5,     3,     2,     4,     3,     8,     6,     6,     2,     2,
       5,     7,     6,     4,     6,     8,     5,     2,     2,     2,
       2,     3,     2,     2,     1,     1,     3,     4,     4,     4,
       4,     4,     4,     1,     1,     2,     1,     2,     2,     8,
       6,     6,     0,     1,     1,     2,     2,     3,    10,     8,
       8,     8,     3,     1,     1,     6,     4,     4,     6,     6,
       4,     6,     1,     4,     1,     1,     1,     1,     3,     3,
       6,     6,     8,     6,     4,     6,     8,     4,     1,     3,
       4,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       4,     4,     4,     6,     1,     3,     1,     3,     4,     6,
       6,     4,     6,     4,     6,    10,     4,     4,     4,     8,
       6,     4,     3,     3,     0,     4,     0,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     4,     6,     1,     4,
       4,     6,     6,     1,     1,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     3,     6,     6,     4,     4,
       4,     4,     6,     6,     8,     6,     8,     4,     4,     4,
       8,     4,     4,     4,     4,     1,     3,     4,     1,     3,
       4,     1,     3,     4,     1,     3,     6,     6,     4,     6,
       6,     6,     4,     8,     6,     8,     6,     4,     4,     4,
       6,     6,     6,     8,     4,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       0,     2,     0,     1,     3,     1,     1,     0,     0,     0,
      11,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       3,     1,     1,     4,     4,     1,     3,     1,     1,     4,
       4,     0,     1,     3,     1,     1,     3,     3,     0,     0,
       0,     0,    14,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     1,     0,     7,     1,     2,     1,     1,     0,
       0,     5,     0,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     0,     6,     1,     1,     0,     4,
       1,     2,     1,     1,     1,     1,     0,     0,     0,     0,
      11,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       1,     0,     2,     0,     0,     0,     7,     0,     1,     1,
       0,     4,     1,     4,     1,     4,     1,     3,     1,     4,
       1,     4,     1,     1,     3,     3,     0,     2,     4,     1,
       3,     0,     2,     6,     0,     4,     0,     4,     0,     6,
       0,     9,     0,    10,     0,    13,     0,    15,     0,     7,
       0,     9,     0,    10,     0,    13,     0,    15,     0,     3,
       0,     1,     0,     2,     2,     4,     1,     4,     6,     6,
       7,    10,    12,     7,    10,    12,     2,     1,     1,     3,
       1,     3
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

  case 63: /* statement: tSETRGB expression ',' expression ',' expression ',' expression  */
                                                                    {add_command(cSETRGB);}
    break;

  case 64: /* statement: tSETDRAWBUF expression  */
                           {add_command(cSETDRAWBUF);}
    break;

  case 65: /* statement: tSETDISPBUF expression  */
                           {add_command(cSETDISPBUF);}
    break;

  case 68: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 69: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 70: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 71: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 72: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 74: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 75: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 76: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 77: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 78: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 79: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 80: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 82: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 83: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 84: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 85: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 86: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 87: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 88: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 89: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 90: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 91: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 92: /* statement: tGTRIANGLE coordinates to coordinates to coordinates  */
                                                         {add_command(cGTRIANGLE);}
    break;

  case 93: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 94: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 95: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 96: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 97: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 98: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 99: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 100: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 101: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 102: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 103: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 104: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 105: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 106: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 107: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 108: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 109: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 110: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 111: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 112: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 113: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 114: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 115: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 116: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 117: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 118: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 119: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 120: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 121: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 122: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 123: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 124: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 125: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 126: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 127: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 128: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 129: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 130: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 131: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 132: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 135: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 136: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 137: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 138: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 139: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 140: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 141: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 142: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 143: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 144: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 146: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 147: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 148: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 150: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 151: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 152: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 153: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 154: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 155: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 156: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 157: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 158: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 159: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 160: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 161: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 162: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 163: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 164: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 165: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 166: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 167: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 168: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 169: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 170: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 171: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 172: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 173: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 174: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 175: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 176: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 177: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 178: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 179: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 180: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 181: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 182: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 183: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 184: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 185: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 186: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 187: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 188: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 189: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 190: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 191: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 192: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 193: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 194: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 195: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 196: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 197: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 198: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 199: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 200: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 201: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 202: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 203: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 204: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 205: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 206: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 207: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 208: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 209: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 210: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 211: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 212: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 213: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 214: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 215: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 216: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 217: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 218: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 219: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 220: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 221: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 222: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 223: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 224: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 225: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 226: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 227: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 230: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 231: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 232: /* string_arrayref: tSYMBOL '(' ')'  */
                    {char *ps2_name=ps2_string_arrayref_name((yyvsp[-2].symbol)); create_pusharrayref(dotify(ps2_name,FALSE),stSTRINGARRAYREF); my_free(ps2_name);}
    break;

  case 234: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 235: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 236: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 237: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 238: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 239: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 240: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 241: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 242: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 243: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 244: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 245: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 246: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 247: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 248: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 249: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 250: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 251: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 252: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 253: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 254: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 255: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 256: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 257: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 258: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 259: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 260: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 261: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 262: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 263: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 264: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 265: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 266: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 267: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 268: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 269: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 270: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 271: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 272: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 273: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 274: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 275: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 276: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 277: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 278: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 279: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 280: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 281: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 282: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 283: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 284: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 285: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 286: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 287: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 288: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 289: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 290: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 291: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 292: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 293: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 294: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 295: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 296: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 297: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 298: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 299: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 300: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 301: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 302: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 303: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 304: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 305: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 306: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 307: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 308: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 309: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 310: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 311: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 312: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 313: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 314: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 315: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 316: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 317: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 318: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 319: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 320: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 327: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 328: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 329: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 330: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 331: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 332: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 333: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 334: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 335: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 336: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 337: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 338: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 341: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 342: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 343: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 344: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 347: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 348: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 349: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 350: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 354: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 355: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 356: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 357: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 358: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 359: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 360: /* $@17: %empty  */
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

  case 361: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 362: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 363: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 364: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 365: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 366: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 367: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 368: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 369: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 371: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 372: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 373: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 374: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 380: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 381: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 383: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 385: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 387: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 388: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 389: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 390: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 391: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 392: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 393: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 394: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 396: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 397: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 398: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 400: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 401: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 402: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 403: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 404: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 405: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 406: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 407: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 408: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 409: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 411: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 412: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 413: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 414: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 415: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 416: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 417: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 419: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 420: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 424: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 425: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 430: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 432: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 433: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 434: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 435: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 438: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 439: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 440: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 441: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 442: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 443: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 444: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 445: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 449: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 450: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 451: /* using: %empty  */
       {create_print('d');}
    break;

  case 452: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 453: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 454: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 455: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 456: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 457: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 458: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 459: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 460: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 461: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 462: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 463: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 464: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 465: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 466: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 467: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 468: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 469: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 470: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 471: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 472: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 473: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 474: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 475: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 476: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 477: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 478: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 479: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 480: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 481: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 482: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 483: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 484: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 485: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 486: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 487: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 488: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 489: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 490: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 491: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 492: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 493: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 494: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 495: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 498: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 499: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 500: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 501: /* gosub_list: gosub_list ',' symbol_or_lineno  */
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
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

