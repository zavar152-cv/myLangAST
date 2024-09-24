#include <antlr3.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "grammar/myLang.h"
#include "dotUtils/dotUtils.h"


int main(int argc, char *argv[]) {
  pANTLR3_UINT8 filename = (pANTLR3_UINT8)argv[1];

  MyLangResult result;
  pANTLR3_INPUT_STREAM input = antlr3FileStreamNew(filename, ANTLR3_ENC_8BIT);
  createMyLangResult(&result, input);

  if (!result.isValid) {
    printErrors(&result.errorContext);
  } 

  int err = generateDotFileFromAntlrTree(result.tree, argv[2], false);

  if (err == FILE_ERROR) {
    fprintf(stderr, "Error opening file %s for writing.\n", argv[2]);
  }
  
  destroyMyLangResult(&result);
  input->close(input);

  return 0;
}
