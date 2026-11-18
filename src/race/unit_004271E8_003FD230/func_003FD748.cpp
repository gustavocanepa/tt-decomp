/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    VEntry *vtbl;
};

extern "C" Obj *func_00403570(char *arg0, s32 arg1);

extern "C" void func_003FD748(char *arg0, s32 arg1, s32 arg2) {
    Obj *o = func_00403570(arg0 + 0x1238, arg2);
    VEntry *e = &o->vtbl[4];
    e->fn((char *)o + e->delta, arg1);
}
