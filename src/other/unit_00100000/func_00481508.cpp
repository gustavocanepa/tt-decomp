struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x30];
    void (*handler)(Obj *);
    int handlerArg;
    char pad38[0xA8 - 0x38];
    VEntry *vtbl;
};

extern "C" void func_00481578(Obj *o);

extern "C" void func_00481508(Obj *o) {
    VEntry *e = &o->vtbl[6];
    e->fn((char *)o + e->delta);
    o->handler = func_00481578;
    o->handlerArg = 0;
}
