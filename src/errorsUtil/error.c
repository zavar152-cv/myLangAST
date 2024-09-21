#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errorsUtil/error.h"

void initErrorContext(ErrorContext *context) {
  context->errorCount = 0;
  context->errorText = (char **)malloc(sizeof(char *) * MAX_ERRORS);
  context->errorLine =
      (unsigned int *)malloc(sizeof(unsigned int) * MAX_ERRORS);
  context->errPosInLine = (int *)malloc(sizeof(int) * MAX_ERRORS);
  context->errTokenText = (char **)malloc(sizeof(char *) * MAX_ERRORS);
}

void destroyErrorContext(ErrorContext *context) {
  for (int i = 0; i < context->errorCount; i++) {
    free(context->errorText[i]);
    free(context->errTokenText[i]);
  }
  free(context->errorText);
  free(context->errTokenText);
  free(context->errorLine);
  free(context->errPosInLine);
}

void addError(ErrorContext *context, const char *errorMsg,
              unsigned int errorLine, int errPosInLine,
              const char *errTokenText) {
  if (context->errorCount < MAX_ERRORS) {
    context->errorText[context->errorCount] = strdup(errorMsg);
    context->errorLine[context->errorCount] = errorLine;
    context->errPosInLine[context->errorCount] = errPosInLine;
    context->errTokenText[context->errorCount] = strdup(errTokenText);
    context->errorCount++;
  }
}

void printErrors(ErrorContext *context) {
  for (int i = 0; i < context->errorCount; i++) {
    printf("Error %d in line %u at %d in token '%s': %s\n", i + 1,
           context->errorLine[i], context->errPosInLine[i],
           context->errTokenText[i], context->errorText[i]);
  }
}