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

#ifndef YY_YY_BISON_H_INCLUDED
# define YY_YY_BISON_H_INCLUDED
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
    tFNUM = 258,                   /* tFNUM  */
    tSYMBOL = 259,                 /* tSYMBOL  */
    tSTRSYM = 260,                 /* tSTRSYM  */
    tDOCU = 261,                   /* tDOCU  */
    tDIGITS = 262,                 /* tDIGITS  */
    tHEXDIGITS = 263,              /* tHEXDIGITS  */
    tBINDIGITS = 264,              /* tBINDIGITS  */
    tSTRING = 265,                 /* tSTRING  */
    tFOR = 266,                    /* tFOR  */
    tTO = 267,                     /* tTO  */
    tSTEP = 268,                   /* tSTEP  */
    tNEXT = 269,                   /* tNEXT  */
    tWHILE = 270,                  /* tWHILE  */
    tWEND = 271,                   /* tWEND  */
    tREPEAT = 272,                 /* tREPEAT  */
    tUNTIL = 273,                  /* tUNTIL  */
    tIMPORT = 274,                 /* tIMPORT  */
    tGOTO = 275,                   /* tGOTO  */
    tGOSUB = 276,                  /* tGOSUB  */
    tLABEL = 277,                  /* tLABEL  */
    tON = 278,                     /* tON  */
    tSUB = 279,                    /* tSUB  */
    tENDSUB = 280,                 /* tENDSUB  */
    tLOCAL = 281,                  /* tLOCAL  */
    tSTATIC = 282,                 /* tSTATIC  */
    tEXPORT = 283,                 /* tEXPORT  */
    tERROR = 284,                  /* tERROR  */
    tEXECUTE = 285,                /* tEXECUTE  */
    tEXECUTE2 = 286,               /* tEXECUTE2  */
    tCOMPILE = 287,                /* tCOMPILE  */
    tRUNTIME_CREATED_SUB = 288,    /* tRUNTIME_CREATED_SUB  */
    tINTERRUPT = 289,              /* tINTERRUPT  */
    tBREAK = 290,                  /* tBREAK  */
    tCONTINUE = 291,               /* tCONTINUE  */
    tSWITCH = 292,                 /* tSWITCH  */
    tSEND = 293,                   /* tSEND  */
    tCASE = 294,                   /* tCASE  */
    tDEFAULT = 295,                /* tDEFAULT  */
    tLOOP = 296,                   /* tLOOP  */
    tDO = 297,                     /* tDO  */
    tSEP = 298,                    /* tSEP  */
    tEOPROG = 299,                 /* tEOPROG  */
    tIF = 300,                     /* tIF  */
    tTHEN = 301,                   /* tTHEN  */
    tELSE = 302,                   /* tELSE  */
    tELSIF = 303,                  /* tELSIF  */
    tENDIF = 304,                  /* tENDIF  */
    tIMPLICITENDIF = 305,          /* tIMPLICITENDIF  */
    tUSING = 306,                  /* tUSING  */
    tPRINT = 307,                  /* tPRINT  */
    tINPUT = 308,                  /* tINPUT  */
    tRETURN = 309,                 /* tRETURN  */
    tDIM = 310,                    /* tDIM  */
    tEND = 311,                    /* tEND  */
    tEXIT = 312,                   /* tEXIT  */
    tAT = 313,                     /* tAT  */
    tSCREEN = 314,                 /* tSCREEN  */
    tREVERSE = 315,                /* tREVERSE  */
    tCOLOUR = 316,                 /* tCOLOUR  */
    tBACKCOLOUR = 317,             /* tBACKCOLOUR  */
    tAND = 318,                    /* tAND  */
    tOR = 319,                     /* tOR  */
    tNOT = 320,                    /* tNOT  */
    tBITNOT = 321,                 /* tBITNOT  */
    tEOR = 322,                    /* tEOR  */
    tSHL = 323,                    /* tSHL  */
    tSHR = 324,                    /* tSHR  */
    tNEQ = 325,                    /* tNEQ  */
    tLEQ = 326,                    /* tLEQ  */
    tGEQ = 327,                    /* tGEQ  */
    tLTN = 328,                    /* tLTN  */
    tGTN = 329,                    /* tGTN  */
    tEQU = 330,                    /* tEQU  */
    tEQU2 = 331,                   /* tEQU2  */
    tPOW = 332,                    /* tPOW  */
    tREAD = 333,                   /* tREAD  */
    tDATA = 334,                   /* tDATA  */
    tRESTORE = 335,                /* tRESTORE  */
    tOPEN = 336,                   /* tOPEN  */
    tCLOSE = 337,                  /* tCLOSE  */
    tSEEK = 338,                   /* tSEEK  */
    tTELL = 339,                   /* tTELL  */
    tAS = 340,                     /* tAS  */
    tREADING = 341,                /* tREADING  */
    tWRITING = 342,                /* tWRITING  */
    tORIGIN = 343,                 /* tORIGIN  */
    tWINDOW = 344,                 /* tWINDOW  */
    tDOT = 345,                    /* tDOT  */
    tLINE = 346,                   /* tLINE  */
    tCIRCLE = 347,                 /* tCIRCLE  */
    tTRIANGLE = 348,               /* tTRIANGLE  */
    tGTRIANGLE = 349,              /* tGTRIANGLE  */
    tTEXT = 350,                   /* tTEXT  */
    tCLEAR = 351,                  /* tCLEAR  */
    tFILL = 352,                   /* tFILL  */
    tPRINTER = 353,                /* tPRINTER  */
    tSETRGB = 354,                 /* tSETRGB  */
    tSETDRAWBUF = 355,             /* tSETDRAWBUF  */
    tSETDISPBUF = 356,             /* tSETDISPBUF  */
    tWAIT = 357,                   /* tWAIT  */
    tBELL = 358,                   /* tBELL  */
    tLET = 359,                    /* tLET  */
    tARDIM = 360,                  /* tARDIM  */
    tARSIZE = 361,                 /* tARSIZE  */
    tBIND = 362,                   /* tBIND  */
    tRECT = 363,                   /* tRECT  */
    tGETBIT = 364,                 /* tGETBIT  */
    tPUTBIT = 365,                 /* tPUTBIT  */
    tGETCHAR = 366,                /* tGETCHAR  */
    tPUTCHAR = 367,                /* tPUTCHAR  */
    tNEW = 368,                    /* tNEW  */
    tCURVE = 369,                  /* tCURVE  */
    tSIN = 370,                    /* tSIN  */
    tASIN = 371,                   /* tASIN  */
    tCOS = 372,                    /* tCOS  */
    tACOS = 373,                   /* tACOS  */
    tTAN = 374,                    /* tTAN  */
    tATAN = 375,                   /* tATAN  */
    tEXP = 376,                    /* tEXP  */
    tLOG = 377,                    /* tLOG  */
    tSQRT = 378,                   /* tSQRT  */
    tSQR = 379,                    /* tSQR  */
    tMYEOF = 380,                  /* tMYEOF  */
    tABS = 381,                    /* tABS  */
    tSIG = 382,                    /* tSIG  */
    tINT = 383,                    /* tINT  */
    tCEIL = 384,                   /* tCEIL  */
    tFLOOR = 385,                  /* tFLOOR  */
    tFRAC = 386,                   /* tFRAC  */
    tROUND = 387,                  /* tROUND  */
    tMOD = 388,                    /* tMOD  */
    tRAN = 389,                    /* tRAN  */
    tVAL = 390,                    /* tVAL  */
    tLEFT = 391,                   /* tLEFT  */
    tRIGHT = 392,                  /* tRIGHT  */
    tMID = 393,                    /* tMID  */
    tLEN = 394,                    /* tLEN  */
    tMIN = 395,                    /* tMIN  */
    tMAX = 396,                    /* tMAX  */
    tSTR = 397,                    /* tSTR  */
    tINKEY = 398,                  /* tINKEY  */
    tCHR = 399,                    /* tCHR  */
    tASC = 400,                    /* tASC  */
    tHEX = 401,                    /* tHEX  */
    tDEC = 402,                    /* tDEC  */
    tBIN = 403,                    /* tBIN  */
    tUPPER = 404,                  /* tUPPER  */
    tLOWER = 405,                  /* tLOWER  */
    tMOUSEX = 406,                 /* tMOUSEX  */
    tMOUSEY = 407,                 /* tMOUSEY  */
    tMOUSEB = 408,                 /* tMOUSEB  */
    tMOUSEMOD = 409,               /* tMOUSEMOD  */
    tTRIM = 410,                   /* tTRIM  */
    tLTRIM = 411,                  /* tLTRIM  */
    tRTRIM = 412,                  /* tRTRIM  */
    tSTRING2 = 413,                /* tSTRING2  */
    tINSTR = 414,                  /* tINSTR  */
    tRINSTR = 415,                 /* tRINSTR  */
    tCHOMP = 416,                  /* tCHOMP  */
    tSYSTEM = 417,                 /* tSYSTEM  */
    tSYSTEM2 = 418,                /* tSYSTEM2  */
    tPEEK = 419,                   /* tPEEK  */
    tPEEK2 = 420,                  /* tPEEK2  */
    tPOKE = 421,                   /* tPOKE  */
    tFRNFN_CALL = 422,             /* tFRNFN_CALL  */
    tFRNFN_CALL2 = 423,            /* tFRNFN_CALL2  */
    tFRNFN_SIZE = 424,             /* tFRNFN_SIZE  */
    tFRNBF_ALLOC = 425,            /* tFRNBF_ALLOC  */
    tFRNBF_FREE = 426,             /* tFRNBF_FREE  */
    tFRNBF_SIZE = 427,             /* tFRNBF_SIZE  */
    tFRNBF_DUMP = 428,             /* tFRNBF_DUMP  */
    tFRNBF_SET = 429,              /* tFRNBF_SET  */
    tFRNBF_GET = 430,              /* tFRNBF_GET  */
    tFRNBF_GET2 = 431,             /* tFRNBF_GET2  */
    tFRNBF_GET_BUFFER = 432,       /* tFRNBF_GET_BUFFER  */
    tFRNBF_SET_BUFFER = 433,       /* tFRNBF_SET_BUFFER  */
    tDATE = 434,                   /* tDATE  */
    tTIME = 435,                   /* tTIME  */
    tTOKEN = 436,                  /* tTOKEN  */
    tTOKENALT = 437,               /* tTOKENALT  */
    tSPLIT = 438,                  /* tSPLIT  */
    tSPLITALT = 439,               /* tSPLITALT  */
    tGLOB = 440,                   /* tGLOB  */
    tSTART_PROGRAM = 441,          /* tSTART_PROGRAM  */
    tSTART_EXPRESSION = 442,       /* tSTART_EXPRESSION  */
    tSTART_STRING_EXPRESSION = 443, /* tSTART_STRING_EXPRESSION  */
    tSTART_ASSIGNMENT = 444,       /* tSTART_ASSIGNMENT  */
    tSTART_FUNCTION_DEFINITION = 445, /* tSTART_FUNCTION_DEFINITION  */
    tEVAL = 446,                   /* tEVAL  */
    tEVAL2 = 447,                  /* tEVAL2  */
    UMINUS = 448                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  double fnum;          /* double number */
  int inum;             /* integer number */
  int token;            /* token of command */
  int nnl;              /* number of newlines */
  char *string;         /* quoted string */
  char *symbol;         /* general symbol */
  char *digits;         /* string of digits */
  char *docu;		/* embedded documentation */


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_BISON_H_INCLUDED  */
