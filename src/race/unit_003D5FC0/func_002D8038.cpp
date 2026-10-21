#include "types.h"

struct Node {
    char pad[0x10];
    Node *next;
};

extern "C" s32 func_002D7F68(void *, Node *);

extern "C" Node *func_002D8038(void *ctx, Node *n) {
    for (;;) {
        n = n->next;
        if (n == 0)
            return 0;
        if (func_002D7F68(ctx, n))
            return n;
    }
}
