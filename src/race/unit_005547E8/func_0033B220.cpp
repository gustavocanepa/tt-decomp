/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
    char pad68[0xD94 - 0x68];
    s32 busy;
};

extern "C" void func_0033B220(Obj *self) {
    if (self->busy == 0) {
        VEntry *e = self->vtbl + 51;
        e->fn((char *)self + e->delta);
    }
}
