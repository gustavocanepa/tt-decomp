#include "types.h"

struct VEntry_50 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct ObjAct {
    char pad0[4];
    char *vtbl;
    char pad1[8];
    s32 f10;
    s32 f14;
};

struct S00305570 {
    char pad0[1];
};

extern "C" void func_00526860(const char *fmt, ...);
extern "C" const char *func_002A39C0(struct S00305570 *arg0);
extern "C" s32 func_0022F7B8(void *arg0);
extern "C" s32 func_0022F7C8(void *arg0);
extern "C" s32 func_0022F610(void *arg0, s32 arg1, s32 arg2);

extern char D_005EC008[];
extern char D_005EC010[];
extern char D_005EC028[];

static inline s32 vcall_50(char *o) {
    VEntry_50 *e = (VEntry_50 *)(((ObjAct *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" s32 func_00217048(char *arg0) {
    ObjAct *o = (ObjAct *)arg0;
    s32 t1;
    s32 r;
    const char *name;

    func_00526860(D_005EC008);
    name = func_002A39C0((struct S00305570 *)vcall_50(arg0));
    func_00526860(D_005EC010, name, o->f14, o->f10);
    t1 = func_0022F7B8(arg0);
    r = func_0022F610(arg0, t1, func_0022F7C8(arg0));
    func_00526860(D_005EC028);
    return r;
}
