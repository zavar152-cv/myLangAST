#include "dotUtils/dotUtils.h"
#include <stdlib.h>
#include <string.h>

DotNode* newDotNode(uint64_t id, const char* label, uint32_t childCount) {
    DotNode* node = (DotNode*)malloc(sizeof(DotNode));
    node->id = id;
    node->label = strdup(label);
    node->childCount = childCount;
    node->children = (DotNode**)malloc(childCount * sizeof(DotNode*));
    return node;
}

void destroyDotNodeTree(DotNode* root) {
    if (root == NULL) {
        return;
    }
    for (uint32_t i = 0; i < root->childCount; i++) {
        destroyDotNodeTree(root->children[i]);
    }
    free(root->children);
    free((void*)root->label);
    free(root);
}

const char* postProcessingNodeToken(const char* tokenText) {
    if(strcmp(tokenText, "=") == 0) {
        return "ASSIGN";
    } else if(strcmp(tokenText, "+") == 0) {
        return "PLUS";
    } else if(strcmp(tokenText, "-") == 0) {
        return "MINUS";
    } else if(strcmp(tokenText, "*") == 0) {
        return "MUL";
    } else if(strcmp(tokenText, "/") == 0) {
        return "DIV";
    } else if(strcmp(tokenText, "==") == 0) {
        return "EQ";
    } else if(strcmp(tokenText, "!=") == 0) {
        return "NEQ";
    } else if(strcmp(tokenText, "<") == 0) {
        return "LE";
    } else if(strcmp(tokenText, ">") == 0) {
        return "GR";
    } else if(strcmp(tokenText, "<=") == 0) {
        return "LE_EQ";
    } else if(strcmp(tokenText, ">=") == 0) {
        return "GR_EQ";
    } else {
        return tokenText;
    }
}

DotNode* preorderTraversalWithCopy(pANTLR3_BASE_TREE root, uint64_t layer, uint64_t *id, bool debug) {
  if (root == NULL) {
    return NULL;
  }

  uint64_t currentId = (*id)++;

  for (uint32_t i = 0; i < layer; i++) {
    printf("  ");
  }

  if(debug) {
    const char* nodeName = postProcessingNodeToken((const char*)root->getToken(root)->getText(root->getToken(root))->chars);
    printf("node %s_%lu [label=\"%s\"]", nodeName, currentId,
          root->getToken(root)->getText(root->getToken(root))->chars);
    printf("\n");
  }


  pANTLR3_UINT8 label = root->getToken(root)->getText(root->getToken(root))->chars;
  DotNode* newNode = newDotNode(currentId, (const char *) label, root->getChildCount(root));

  for (uint32_t i = 0; i < root->getChildCount(root); i++) {
    newNode->children[i] = preorderTraversalWithCopy((pANTLR3_BASE_TREE)root->getChild(root, i), layer + 1, 
                      id, debug);
  }

  return newNode;
}

void writeTreeToDot(FILE *file, DotNode* root) {
  if (root == NULL) {
    return;
  }

  fprintf(file, "    node%s_%lu [label=\"%s\"]\n", postProcessingNodeToken(root->label), root->id, root->label);

  for (uint32_t i = 0; i < root->childCount; i++) {
    DotNode* child = root->children[i];
    fprintf(file, "    node%s_%lu -> node%s_%lu;\n",
            postProcessingNodeToken(root->label), root->id,
            postProcessingNodeToken(child->label), child->id);
    writeTreeToDot(file, child);
  }
}

void generateDotFile(DotNode* root, const char *filename) {
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
