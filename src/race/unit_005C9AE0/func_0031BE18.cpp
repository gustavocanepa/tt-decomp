typedef int s32;
typedef short s16;

struct Obj_00396B20;
extern "C" void func_0034C940(Obj_00396B20 *o, s32 b);

struct VEntry1 {
    s16 delta;
    s16 index;
    void *(*fn)(void *self, void *member);
};

struct VEntry2 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self);
};

struct Obj_00396B20 {
    char pad0[4];
};

struct Holder80 {
    char pad0[4];
    Obj_00396B20 *f4;
};

struct Dev {
    char *vtbl;
    char pad4[0x80 - 4];
    Holder80 *f80;
    char pad84[0xA4C - 0x84];
    void *f9BC;
};

extern "C" void func_0031BE18(Dev *arg0, Dev *arg1) {
    VEntry1 *e1 = (VEntry1 *)(arg0->vtbl + 0xE0);
    void *o = e1->fn((char *)arg0 + e1->delta, arg0->f9BC);
    VEntry2 *e2 = (VEntry2 *)(*(char **)o + 0x108);
    s32 r = e2->fn((char *)o + e2->delta);
    if (r != 0) {
        func_0034C940(arg1->f80->f4, r - 1);
    }
}
