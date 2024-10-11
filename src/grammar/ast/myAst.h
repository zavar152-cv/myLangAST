#pragma once

#include <antlr3.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct __attribute__((packed)) MyAstNode {
  struct MyAstNode **children;
  uint32_t childCount;
  const char *label;
} MyAstNode;

MyAstNode *newMyAstNode(const char *label, uint32_t childCount);

void destroyMyAstNodeTree(MyAstNode *root);

MyAstNode *createMyTreeFromAntlrTree(pANTLR3_BASE_TREE root, uint64_t layer,
                                      bool debug);

const char *postProcessingNodeToken(const char *tokenText);