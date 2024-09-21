#include "dotUtils/dotUtils.h"
#include <stdlib.h>
#include <string.h>

struct DotNode* newDotNode(uint64_t id, const char* label, uint32_t childCount) {
    struct DotNode* node = (struct DotNode*)malloc(sizeof(struct DotNode));
    node->id = id;
    node->label = strdup(label);
    node->childCount = childCount;
    node->children = (struct DotNode**)malloc(childCount * sizeof(struct Node*));
    return node;
}

void destroyDotNodeTree(struct DotNode* root) {
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
