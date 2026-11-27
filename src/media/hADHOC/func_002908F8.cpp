#include "types.h"

struct Node {
    s32 color;
    Node *parent;
    Node *left;
    Node *right;
    s32 key;
    s32 value;
};

struct Iter {
    Node *node;
    Node *operator->() const { return node; }
};

struct Map {
    s32 alloc;
    Node *header;
};

struct Obj {
    s32 a;
    s32 b;
    Map m;
};

extern "C" Iter func_005471D8(Map *, s32);

extern "C" s32 func_002908F8(Obj *self, s32 key) {
    Map *m = &self->m;
    Iter it = func_005471D8(m, key);
    if (it.node == m->header)
        return 0;
    return it->value;
}
