typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
    char pad1[0x6CC - 8];
    s32 count;
};

extern "C" s32 func_001E4EC0(Obj *arg0);

extern "C" void func_001E5128(Obj *self) {
    if (func_001E4EC0(self) != 0) {
        s32 n = self->count - 1;
        self->count = n;
        char *p = (char *)self + (n << 4);
        if (n > 0) {
            VEntry *e = (VEntry *)(self->vtbl + 0x210);
            e->fn((char *)self + e->delta, p + 0x8C);
        } else {
            VEntry *e = (VEntry *)(self->vtbl + 0x208);
            e->fn((char *)self + e->delta, p);
        }
    }
}
