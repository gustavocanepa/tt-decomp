#include "types.h"

struct Node {
    char pad0[0xA8];
    struct Node *next;
    struct Node *prev;
};

struct Obj {
    char pad0[0x584];
    struct Node *sentinel;
    s32 count;
};

struct Src {
    char pad0[0x4];
    struct Node *unk4;
};

struct Blk8 {
    struct Node *w0;
    struct Node *w1;
};

extern "C" {

void func_0055B360(void *, void *);

struct Blk8 *func_0055B2B8(struct Blk8 *dst, struct Obj *arg1, struct Src *arg2, struct Blk8 *arg3) {
    struct Node *cur;
    struct Node *tail;
    struct Node *old;

    cur = arg2->unk4;
    if (cur != arg1->sentinel) {
        tail = arg3->w1;
        cur->prev->next = tail;
        tail->prev = cur->prev;
        if (cur != tail) {
            do {
                old = cur;
                cur = cur->next;
                func_0055B360(arg1, old);
                arg1->count = arg1->count - 1;
            } while (cur != tail);
        }
    }
    *dst = *arg3;
    return dst;
}

}
