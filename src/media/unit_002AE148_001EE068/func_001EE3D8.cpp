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

extern "C" void func_001EDBE0(void *arg0, int arg1);
extern "C" void func_001EDC38(void *arg0, void *arg1);
extern "C" void func_001EED90(void *arg0, s32 arg1);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_001EE3D8(void *arg0, void *arg1, s32 arg2, char **arg3) {
    if (arg2 == 1) {
        A a;
        s32 v = vcall_58(*arg3) != 0;
        func_001EDC38(&a, arg1);
        func_001EED90(a.p, v);
        func_001EDBE0(&a, 2);
    }
}
