typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};

struct Obj {
    char pad[4];
    char *vtbl;
};

extern "C" void func_0017A080(Obj *, int);

extern "C" void func_0017A030(Obj *self, int arg) {
    VEntry *e = (VEntry *)(self->vtbl + 0x1E0);
    e->fn((char *)self + e->delta, arg);
    return func_0017A080(self, arg);
}
