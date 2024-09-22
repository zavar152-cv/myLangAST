#include <antlr3.h>
#include <stdint.h>
#include <stdio.h>

#include "ExampleLexer.h"
#include "ExampleParser.h"
#include "errorsUtils/error.h"
#include "dotUtils/dotUtils.h"

struct DotNode* preorderTraversalWithCopy(pANTLR3_BASE_TREE root, uint64_t layer, uint64_t *id) {
  if (root == NULL) {
    return NULL;
  }

  uint64_t currentId = (*id)++;

  for (uint32_t i = 0; i < layer; i++) {
    printf("  ");
  }
  printf("node %s_%lu [label=\"%s\"]", root->getToken(root)->getText(root->getToken(root))->chars, currentId,
         root->getToken(root)->getText(root->getToken(root))->chars);
  printf("\n");

  pANTLR3_UINT8 label = root->getToken(root)->getText(root->getToken(root))->chars;
  struct DotNode* newNode = newDotNode(currentId, (const char *) label, root->getChildCount(root));

  for (uint32_t i = 0; i < root->getChildCount(root); i++) {
    newNode->children[i] = preorderTraversalWithCopy((pANTLR3_BASE_TREE)root->getChild(root, i), layer + 1, 
                      id);
  }

  return newNode;
}

void writeTreeToDot(FILE *file, struct DotNode* root) {
  if (root == NULL) {
    return;
  }

  fprintf(file, "    node%s_%lu [label=\"%s\"]\n", root->label, root->id, root->label);

  for (uint32_t i = 0; i < root->childCount; i++) {
    struct DotNode* child = root->children[i];
    fprintf(file, "    node%s_%lu -> node%s_%lu;\n",
            root->label, root->id,
            child->label, child->id);
    writeTreeToDot(file, child);
  }
}

void generateDotFile(struct DotNode* root, const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error opening file %s for writing.\n", filename);
    return;
  }

  fprintf(file, "digraph Tree {\n");
  fprintf(file, "    node [shape=hexagon];\n");

  writeTreeToDot(file, root);

  fprintf(file, "}\n");
  fclose(file);
}

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

  struct DotNode* dotTree;
  if (errCount > 0) {
    printErrors(&errorContext);
  } else {
    pANTLR3_BASE_TREE tree = r.tree;
    printf("%s\n", tree->toStringTree(tree)->chars);
    printf("%u\n", tree->getChildCount(tree));
    uint64_t id = 0;
    dotTree = preorderTraversalWithCopy(tree, 0, &id);
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
