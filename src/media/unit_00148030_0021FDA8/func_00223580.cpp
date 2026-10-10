typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00223580(struct Obj *arg0) {
    VEntry *e = (VEntry *)((char *)arg0->vtbl + 0x2A0);

    e->fn((char *)arg0 + e->delta, -1);
}
