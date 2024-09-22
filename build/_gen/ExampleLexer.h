/** \file
 *  This C header file was generated by $ANTLR version 3.5.3
 *
 *     -  From the grammar source file : src/grammar/rec/Example.g3
 *     -                            On : 2024-09-22 21:28:22
 *     -                 for the lexer : ExampleLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
ExampleLexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pExampleLexer, which is returned from a call to ExampleLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in pExampleLexer are  as follows:
 *
 *  - 
 void
      pExampleLexer->T__68(pExampleLexer)
 *  - 
 void
      pExampleLexer->T__69(pExampleLexer)
 *  - 
 void
      pExampleLexer->T__70(pExampleLexer)
 *  - 
 void
      pExampleLexer->T__71(pExampleLexer)
 *  - 
 void
      pExampleLexer->T__72(pExampleLexer)
 *  - 
 void
      pExampleLexer->T__73(pExampleLexer)
 *  - 
 void
      pExampleLexer->MINUS_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->EXCL_MARK_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->PLUS_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->MUL_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->ASSIGN_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->DIV_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->EQ_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->NEQ_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->LE_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->GR_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->LE_EQ_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->GR_EQ_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->BOOL_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->BYTE_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->INT_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->UINT_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->LONG_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->ULONG_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->CHAR_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->STRING_TYPE(pExampleLexer)
 *  - 
 void
      pExampleLexer->BOOL_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->IDENTIFIER_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->BITS_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->HEX_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->DEC_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->CHAR_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->STR_TOKEN(pExampleLexer)
 *  - 
 void
      pExampleLexer->NEWLINE(pExampleLexer)
 *  - 
 void
      pExampleLexer->WSS(pExampleLexer)
 *  - 
 void
      pExampleLexer->TRUE(pExampleLexer)
 *  - 
 void
      pExampleLexer->FALSE(pExampleLexer)
 *  - 
 void
      pExampleLexer->ALPHA(pExampleLexer)
 *  - 
 void
      pExampleLexer->SPECIAL(pExampleLexer)
 *  - 
 void
      pExampleLexer->DIGIT(pExampleLexer)
 *  - 
 void
      pExampleLexer->BINARY_DIGIT(pExampleLexer)
 *  - 
 void
      pExampleLexer->HEX_DIGIT(pExampleLexer)
 *  - 
 void
      pExampleLexer->WS(pExampleLexer)
 *  - 
 void
      pExampleLexer->Tokens(pExampleLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_ExampleLexer_H
#define _ExampleLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct ExampleLexer_Ctx_struct ExampleLexer, * pExampleLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
ExampleLexer

 */
struct ExampleLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mT__68)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mT__69)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mT__70)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mT__71)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mT__72)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mT__73)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mMINUS_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mEXCL_MARK_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mPLUS_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mMUL_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mASSIGN_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mDIV_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mEQ_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mNEQ_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mLE_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mGR_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mLE_EQ_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mGR_EQ_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mBOOL_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mBYTE_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mINT_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mUINT_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mLONG_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mULONG_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mCHAR_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mSTRING_TYPE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mBOOL_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mIDENTIFIER_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mBITS_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mHEX_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mDEC_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mCHAR_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mSTR_TOKEN)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mNEWLINE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mWSS)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mTRUE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mFALSE)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mALPHA)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mSPECIAL)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mDIGIT)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mBINARY_DIGIT)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mHEX_DIGIT)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mWS)	(struct ExampleLexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct ExampleLexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct ExampleLexer_Ctx_struct * ctx);
    void	    (*free)   (struct ExampleLexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pExampleLexer ExampleLexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API pExampleLexer ExampleLexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__68      68
#define T__69      69
#define T__70      70
#define T__71      71
#define T__72      72
#define T__73      73
#define ALPHA      4
#define ARRAY_TYPE      5
#define ASSIGN      6
#define ASSIGN_TOKEN      7
#define BINARY_DIGIT      8
#define BINARY_OP      9
#define BITS      10
#define BITS_TOKEN      11
#define BOOL      12
#define BOOL_TOKEN      13
#define BOOL_TYPE      14
#define BRACES      15
#define BUILTIN_TYPE      16
#define BYTE_TYPE      17
#define CHAR_TOKEN      18
#define CHAR_TYPE      19
#define CUSTOM_TYPE      20
#define DEC      21
#define DEC_TOKEN      22
#define DIGIT      23
#define DIV_TOKEN      24
#define EQ_TOKEN      25
#define EXCL_MARK_TOKEN      26
#define EXPR      27
#define FALSE      28
#define GR_EQ_TOKEN      29
#define GR_TOKEN      30
#define HEX      31
#define HEX_DIGIT      32
#define HEX_TOKEN      33
#define IDENTIFIER      34
#define IDENTIFIER_TOKEN      35
#define INT_TYPE      36
#define LE_EQ_TOKEN      37
#define LE_TOKEN      38
#define LITERAL      39
#define LONG_TYPE      40
#define MINUS      41
#define MINUS_TOKEN      42
#define MUL      43
#define MUL_TOKEN      44
#define NEG      45
#define NEQ_TOKEN      46
#define NEWLINE      47
#define NOT      48
#define PLACE      49
#define PLUS      50
#define PLUS_TOKEN      51
#define RUNE      52
#define SOURCE      53
#define SOURCE_ITEM      54
#define SPECIAL      55
#define STR      56
#define STRING_TYPE      57
#define STR_TOKEN      58
#define TERM      59
#define TRUE      60
#define TYPE      61
#define UINT_TYPE      62
#define ULONG_TYPE      63
#define UNARY_OP      64
#define VAR      65
#define WS      66
#define WSS      67
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for ExampleLexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
