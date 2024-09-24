#include "grammar/myLang.h"
#include <stdbool.h>

void createMyLangResult(MyLangResult *result, pANTLR3_INPUT_STREAM input) {
  pMyLangLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  pMyLangParser parser;

  lex = MyLangLexerNew(input);
  lex->pLexer->rec->reportError = reportLexerError;

  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));

  initErrorContext(&result->errorContext);
  result->isValid = false;
  result->tree = NULL;

  parser = MyLangParserNew(tokens);
  parser->pParser->rec->state->userp = &result->errorContext;
  parser->pParser->rec->displayRecognitionError = extractRecognitionError;

  result->parser = parser;
  result->lex = lex;
  result->tokens = tokens;

  MyLangParser_source_return r = parser->source(parser);
  result->tree = r.tree;
  result->isValid = parser->pParser->rec->state->errorCount == 0;
}

void destroyMyLangResult(MyLangResult *result) {
  pMyLangLexer lex = result->lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens = result->tokens;
  pMyLangParser parser = result->parser;
  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  destroyErrorContext(&result->errorContext);
}