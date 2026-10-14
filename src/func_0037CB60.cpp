typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Child {
    char pad[0x64];
    VEntry *vtbl;
};

struct Obj {
    char pad[0x84];
    Child *child;
};

extern Obj *D_005846B4;

static inline s32 vcall(Child *c) {
    VEntry *e = (VEntry *)((char *)c->vtbl + 0x1B0);
    return e->fn((char *)c + e->delta);
}

extern "C" void func_0037CB60(void) {
    vcall(D_005846B4->child);
}
