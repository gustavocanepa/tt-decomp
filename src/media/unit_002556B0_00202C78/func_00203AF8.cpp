typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_00202788(void *arg0, int arg1);
extern "C" void func_002027E0(void *arg0, void *arg1);
extern "C" void mWidget__setActive(s32 arg0, s32 arg1);

extern "C" void func_00203AF8(s32 *arg0, void *arg1, s32 arg2, ObjA **arg3) {
    s32 buf[4];
    s32 h;
    ObjA *o;
    VEntry *e;

    func_002027E0(buf, arg1);
    o = *arg3;
    e = o->vtbl + 13;
    h = buf[0];
    mWidget__setActive(h, e->fn((char *)o + e->delta) != 0);
    func_00202788(buf, 2);
}
