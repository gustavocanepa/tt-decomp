#include "types.h"
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[14];
    return e->fn(o + e->delta);
}
extern "C" void func_00139C38(void *, void *);
extern "C" void func_00139BE0(void *, s32);
extern "C" void func_0013C938(void *, float);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_0013AFD0(void *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    float v = vcall_60(*arg3);
    func_00139C38(&a, arg1);
    func_0013C938(a.p, v);
    func_00139BE0(&a, 2);
}
