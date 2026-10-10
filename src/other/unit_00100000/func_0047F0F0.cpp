struct VEntry {
    short delta;
    short index;
    int (*fn)(void *, void *);
};

struct Obj {
    char pad0[0xA4];
    VEntry *vtbl;
};

extern "C" Obj *func_0047F398(void *self);

extern "C" int func_0047F0F0(void *self) {
    Obj *o = func_0047F398(self);
    VEntry *e = &o->vtbl[18];
    return e->fn((char *)o + e->delta, self);
}
