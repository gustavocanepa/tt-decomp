/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32, void *, s32, s32);
};
struct VObj {
    char pad0[4];
    char *vtbl;
};
struct Self {
    char pad0[0x10];
    char sub10[4];
    VObj *obj;
};
extern "C" void func_002A2208(Self *arg0, s32 arg1, s32 arg2, s32 arg3) {
    VObj *o = arg0->obj;
    VEntry *e = (VEntry *)(o->vtbl + 0x68);
    e->fn((char *)o + e->delta, arg1, arg0->sub10, arg2, arg3);
}
