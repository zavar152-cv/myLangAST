#include <antlr3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "ExampleLexer.h"
#include "ExampleParser.h"
#include "errorsUtils/error.h"
#include "dotUtils/dotUtils.h"

int main(int argc, char *argv[]) {
  pANTLR3_UINT8 filename = (pANTLR3_UINT8)argv[1];
  printf("%s\n", argv[1]);

  pANTLR3_INPUT_STREAM input;
  pExampleLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  pExampleParser parser;

  input = antlr3FileStreamNew(filename, ANTLR3_ENC_8BIT);
  lex = ExampleLexerNew(input);
  lex->pLexer->rec->reportError = reportLexerError;
  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
  parser = ExampleParserNew(tokens);

  ErrorContext errorContext;
  initErrorContext(&errorContext);

  parser->pParser->rec->state->userp = &errorContext;
  parser->pParser->rec->displayRecognitionError = extractRecognitionError;

  ExampleParser_source_return r = parser->source(parser);
  ANTLR3_UINT32 errCount = parser->pParser->rec->state->errorCount;

  DotNode* dotTree = NULL;
  if (errCount > 0) {
    printErrors(&errorContext);
  } else {
    pANTLR3_BASE_TREE tree = r.tree;
    printf("%s\n", tree->toStringTree(tree)->chars);
    printf("%u\n", tree->getChildCount(tree));
    uint64_t id = 0;
    dotTree = preorderTraversalWithCopy(tree, 0, &id, true);
    generateDotFile(dotTree, "./test.dot");
  }

  destroyDotNodeTree(dotTree);
  destroyErrorContext(&errorContext);
  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  input->close(input);
  return 0;
}
