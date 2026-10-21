typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[4];
    VEntry *vtbl;
};

extern "C" int func_00234490(void *arg0, void *arg1, struct Obj *obj) {
    VEntry *e = (VEntry *)((char *)obj->vtbl + 0x228);

    e->fn((char *)obj + e->delta);
    return 1;
}
