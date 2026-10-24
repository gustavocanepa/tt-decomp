#include "types.h"
struct VEntry_58 { short delta; short index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = &((VObj_58 *)o)->vtbl[13];
    return e->fn(o + e->delta);
}
extern "C" void func_00139C38(void *, void *);
extern "C" void func_00139BE0(void *, s32);
extern "C" void func_0013C948(void *, s32);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_0013ABF0(void *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    s32 v = vcall_58(*arg3) != 0;
    func_00139C38(&a, arg1);
    func_0013C948(a.p, v);
    func_00139BE0(&a, 2);
}
