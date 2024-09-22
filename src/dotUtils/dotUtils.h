#include <stdint.h>
#include <antlr3.h>
#include <stdbool.h>

typedef struct __attribute__((packed)) DotNode {
    struct DotNode** children;
    uint64_t id;
    uint32_t childCount;
    const char* label;
} DotNode;

DotNode* newDotNode(uint64_t id, const char* label, uint32_t childCount);

void destroyDotNodeTree(DotNode* root);

DotNode* preorderTraversalWithCopy(pANTLR3_BASE_TREE root, uint64_t layer, uint64_t *id, bool debug);

void writeTreeToDot(FILE *file, DotNode* root);

void generateDotFile(DotNode* root, const char *filename);