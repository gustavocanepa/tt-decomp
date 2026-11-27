#include "types.h"

struct VEntry_50 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct VEntry_2A8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, void *, s32);
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

extern char D_005EF1E0[];
extern char D_005EF1E8[];
extern char D_005EF200[];

extern "C" void func_00526860(const char *fmt, ...);
extern "C" const char *func_002A39C0(struct S00305570 *arg0);
extern "C" s32 func_0022F7B8(void *arg0);
extern "C" void *func_0022F7C8(void *arg0);

static inline s32 vcall_50(char *o) {
    VEntry_50 *e = (VEntry_50 *)(((ObjAct *)o)->vtbl + 0x58);
    return e->fn(o + e->delta);
}

extern "C" s32 func_00262A88(char *arg0) {
    ObjAct *o = (ObjAct *)arg0;
    s32 r = 1;
    const char *name;

    func_00526860(D_005EF1E0);
    name = func_002A39C0((struct S00305570 *)vcall_50(arg0));
    func_00526860(D_005EF1E8, name, o->f14, o->f10);
    if (func_0022F7C8(arg0) != 0) {
        char *p = (char *)func_0022F7C8(arg0);
        VEntry_2A8 *e = (VEntry_2A8 *)(*(char **)(p + 4) + 0x348);
        char *t = p + e->delta;
        s32 a1 = func_0022F7B8(arg0);
        r = e->fn(t, a1, arg0, 1);
    }
    func_00526860(D_005EF200);
    return r;
}
