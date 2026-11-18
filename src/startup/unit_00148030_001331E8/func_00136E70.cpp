#include "types.h"

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    VEntry *vtbl;
};

struct Pair2 {
    VObj *a;
    VObj *b;
};

struct S;

struct Handle {
    S *p;
    char pad[0xC];
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" int func_001324D8(S *arg0);
extern "C" void func_00405FB8(s32 a, s32 b);

static inline s32 vcall(VObj *o) {
    VEntry *e = &o->vtbl[13];
    return e->fn((char *)o + e->delta);
}

extern "C" void func_00136E70(void *arg0, void *arg1, s32 arg2, Pair2 *arg3) {
    Handle h;
    s32 a;
    s32 b;

    func_00128470(&h, arg1);
    a = func_001324D8(h.p);
    func_00128418(&h, 2);
    b = vcall(arg3->b);
    if (vcall(arg3->a) == 0) {
        func_00405FB8(a, b);
    }
}
