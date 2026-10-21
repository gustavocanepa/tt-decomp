typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self);
};

struct Obj {
    char pad0[8];
    char *vtbl;
};

struct Self {
    char pad0[0xE4C4];
    Obj *slot;
};

extern "C" void func_0033DFF0(Self *self, Obj *val) {
    Obj *old = self->slot;
    if (old) {
        VEntry *e1 = (VEntry *)(old->vtbl + 0x18);
        e1->fn((char *)old + e1->delta);
    }
    self->slot = val;
    if (val) {
        VEntry *e2 = (VEntry *)(val->vtbl + 0x10);
        e2->fn((char *)val + e2->delta);
    }
}
