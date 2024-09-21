#include <stdint.h>

struct __attribute__((packed)) DotNode {
    struct DotNode** children;
    uint64_t id;
    uint32_t childCount;
    const char* label;
};

struct DotNode* newDotNode(uint64_t id, const char* label, uint32_t childCount);

void destroyDotNodeTree(struct DotNode* root);