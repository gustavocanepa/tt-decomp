#include "types.h"
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = &((VObj_60 *)o)->vtbl[14];
    return e->fn(o + e->delta);
}
extern "C" void func_0015A6E8(void *);
extern "C" void func_0015A690(void *, s32);
extern "C" void func_0029B380(void *, float);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);
extern "C" void func_00299AB0(void *, s32);

struct Inner {
    char pad0[0x68];
    s32 value;
};
struct Mid {
    char pad0[0x10];
    Inner *inner;
};
struct A {
    Mid *p;
    s32 pad[3];
};

extern "C" void func_0015BB80(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    s32 b[4];
    if (arg2 > 0) {
        func_0015A6E8(&a);
        Mid *m = a.p;
        float f = vcall_60(*arg3);
        m->inner->value = (s32)(f * 128.0f);
        func_0015A690(&a, 2);
    } else {
        func_0015A6E8(&a);
        s32 *pb = b;
        func_0029B380(pb, (float)a.p->inner->value * 0.0078125f);
        if (arg0 != pb) {
            s32 newVal = pb[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            s32 oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_00299AB0(pb, 2);
        func_0015A690(&a, 2);
    }
}
