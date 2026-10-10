typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Child {
    char *vtbl;
};

struct Obj {
    char pad[0xE4E0];
    Child *child;
};

extern "C" void func_002CF700(Obj *);

extern "C" void func_0033DEC8(Obj *self) {
    func_002CF700(self);
    Child *c = self->child;
    if (c != 0) {
        VEntry *e = (VEntry *)(c->vtbl + 0x20);
        e->fn((char *)c + e->delta);
    }
}
