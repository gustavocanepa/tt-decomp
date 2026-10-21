#include "types.h"

struct VEntry_58 {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj_58 {
    char pad0[4];
    VEntry_58 *vtbl;
};

static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}

extern "C" void func_00265580(void *arg0, int arg1);
extern "C" void func_002655D8(void *arg0, void *arg1);
extern "C" void func_00266418(void *arg0, s32 arg1);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_00265D20(void *arg0, void *arg1, s32 arg2, char **arg3) {
    if (arg2 == 1) {
        A a;
        s32 v = vcall_58(*arg3) != 0;
        func_002655D8(&a, arg1);
        func_00266418(a.p, v);
        func_00265580(&a, 2);
    }
}
