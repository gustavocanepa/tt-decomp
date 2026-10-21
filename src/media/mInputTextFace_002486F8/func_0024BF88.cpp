typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x4];
    VEntry *vtbl;
};

extern "C" void func_001DADF8(Obj *);

extern "C" void func_0024BF88(Obj *self) {
    func_001DADF8(self);
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x268);

    e->fn((char *)self + e->delta);
}
