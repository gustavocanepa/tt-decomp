typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x30];
    char *vtbl;
};

struct Holder {
    char pad[8];
    Obj *p;
};

extern "C" void func_0047D938(void *arg0);

extern "C" void func_0047D690(void *arg0, Holder *arg1) {
    Obj *o = arg1->p;
    arg1->p = 0;
    if (o != 0) {
        VEntry *e = (VEntry *)(o->vtbl + 0x28);
        e->fn((char *)o + e->delta);
        func_0047D938(o);
    }
}
