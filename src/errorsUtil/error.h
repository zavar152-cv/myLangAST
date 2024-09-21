#define MAX_ERRORS 50

typedef struct ErrorContext {
  unsigned int errorCount;
  char **errorText;
  unsigned int *errorLine;
  int *errPosInLine;
  char **errTokenText;
} ErrorContext;

void initErrorContext(ErrorContext *context);

void destroyErrorContext(ErrorContext *context);

void addError(ErrorContext *context, const char *errorMsg,
              unsigned int errorLine, int errPosInLine, const char *errTokenText);

void printErrors(ErrorContext *context);