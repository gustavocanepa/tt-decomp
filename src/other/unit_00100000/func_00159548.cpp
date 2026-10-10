typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Child {
    char pad0[0x0];
    VEntry *vtbl;
};

struct Obj {
    char pad0[0x1C];
    Child *child;
};

extern "C" s32 func_00159548(Obj *self) {
    Child *c = self->child;
    if (c) {
        VEntry *e = c->vtbl + 20;
        return e->fn((char *)c + e->delta);
    }
    return 0;
}
