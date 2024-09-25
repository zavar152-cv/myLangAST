#include "MyLangLexer.h"
#include "MyLangParser.h"
#include "errorsUtils/errorUtils.h"
#include <stdbool.h>

typedef struct MyLangResult {
    pANTLR3_BASE_TREE tree;
    ErrorContext errorContext;
    pMyLangLexer lex;
    pANTLR3_COMMON_TOKEN_STREAM tokens;
    pMyLangParser parser;
    bool isValid;
} MyLangResult;

void parseMyLang(MyLangResult *result, pANTLR3_INPUT_STREAM input);

void destroyMyLangResult(MyLangResult *result);