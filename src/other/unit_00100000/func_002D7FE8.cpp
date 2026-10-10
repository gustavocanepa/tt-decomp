typedef int s32;

struct Node { char pad[0xC]; Node *next; };
extern "C" s32 func_002D7F68(void *, Node *);

extern "C" Node *func_002D7FE8(void *ctx, Node *n) {
    for (;;) {
        n = n->next;
        if (!n)
            return 0;
        if (func_002D7F68(ctx, n))
            return n;
    }
}
