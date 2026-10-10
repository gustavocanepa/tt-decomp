typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" void func_00340EB0(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0xA8);

    e->fn((char *)arg0 + e->delta);
}
