#include "grammar/ast/myAst.h"
#include <stdlib.h>
#include <string.h>

MyAstNode* newMyAstNode(const char* label, uint32_t childCount) {
  MyAstNode *node = (MyAstNode *)malloc(sizeof(MyAstNode));
  node->label = strdup(label);
  node->childCount = childCount;
  node->children = (MyAstNode **)malloc(childCount * sizeof(MyAstNode *));
  return node;
}

void destroyMyAstNodeTree(MyAstNode* root) {
  if (root == NULL) {
    return;
  }
  for (uint32_t i = 0; i < root->childCount; i++) {
    destroyMyAstNodeTree(root->children[i]);
  }
  free(root->children);
  free((void *)root->label);
  free(root);
}

MyAstNode *createMyTreeFromAntlrTree(pANTLR3_BASE_TREE root, uint64_t layer, bool debug) {
  if (root == NULL) {
    return NULL;
  }

  if (debug) {
    for (uint32_t i = 0; i < layer; i++) {
      printf("  ");
    }
    pANTLR3_BASE_TREE parent = root->getParent(root);
    const char *tokenText = (const char *)root->getToken(root)
                                       ->getText(root->getToken(root))
                                       ->chars;
    printf("%s", postProcessingNodeToken(tokenText));
    printf("\n");
  }

  pANTLR3_UINT8 tokenText =
      root->getToken(root)->getText(root->getToken(root))->chars;

  MyAstNode *newNode =
      newMyAstNode((const char *)tokenText, root->getChildCount(root));

  for (uint32_t i = 0; i < root->getChildCount(root); i++) {
    newNode->children[i] = createMyTreeFromAntlrTree(
        (pANTLR3_BASE_TREE)root->getChild(root, i), layer + 1, debug);
  }

  return newNode;
}

const char *postProcessingNodeToken(const char *tokenText) {
  if (strcmp(tokenText, "=") == 0) {
    return "ASSIGN";
  } else if (strcmp(tokenText, "+") == 0) {
    return "PLUS";
  } else if (strcmp(tokenText, "-") == 0) {
    return "MINUS";
  } else if (strcmp(tokenText, "*") == 0) {
    return "MUL";
  } else if (strcmp(tokenText, "/") == 0) {
    return "DIV";
  } else if (strcmp(tokenText, "%") == 0) {
    return "MOD";
  } else if (strcmp(tokenText, "==") == 0) {
    return "EQ";
  } else if (strcmp(tokenText, "!=") == 0) {
    return "NEQ";
  } else if (strcmp(tokenText, "<") == 0) {
    return "LE";
  } else if (strcmp(tokenText, ">") == 0) {
    return "GR";
  } else if (strcmp(tokenText, "<=") == 0) {
    return "LE_EQ";
  } else if (strcmp(tokenText, ">=") == 0) {
    return "GR_EQ";
  } else if (strcmp(tokenText, ",") == 0) {
    return "COMMA";
  } else {
    return tokenText;
  }
}