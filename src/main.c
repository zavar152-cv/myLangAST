#include <antlr3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "grammar/myLang.h"
#include "dotUtils/dotUtils.h"


int main(int argc, char *argv[]) {
  pANTLR3_UINT8 filename = (pANTLR3_UINT8)argv[1];
  printf("%s\n", argv[1]);

  MyLangResult result;
  pANTLR3_INPUT_STREAM input = antlr3FileStreamNew(filename, ANTLR3_ENC_8BIT);
  createMyLangResult(&result, input);

  DotNode* dotTree = NULL;
  if (!result.isValid) {
    printErrors(&result.errorContext);
  } else {
    pANTLR3_BASE_TREE tree = result.tree;
    printf("%s\n", tree->toStringTree(tree)->chars);
    printf("%u\n", tree->getChildCount(tree));
    uint64_t id = 0;
    dotTree = preorderTraversalWithCopy(tree, 0, &id, true);
    generateDotFile(dotTree, "./test.dot");
  }

  destroyDotNodeTree(dotTree);
  destroyMyLangResult(&result);
  input->close(input);

  return 0;
}
