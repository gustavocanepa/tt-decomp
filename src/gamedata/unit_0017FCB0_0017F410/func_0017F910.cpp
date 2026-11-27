#include "types.h"
struct VEntry { short delta; short index; float (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
static inline float vcall(char *o) {
    VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}
extern "C" void *func_0017C4A0(void *);
extern "C" void func_0017C448(void *, s32);
extern "C" void func_0029B380(void *, float);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

struct Target {
    char pad0[0x138];
    float value;
};
struct A {
    Target *p;
    s32 pad[3];
};

extern "C" void func_0017F910(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    if (arg2 == 0) {
        func_0017C4A0(&a);
        s32 b[4];
        s32 *pb = b;
        func_0029B380(pb, a.p->value);
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
        func_0017C448(&a, 2);
    } else if (arg2 == 1) {
        func_0017C4A0(&a);
        Target *t = a.p;
        t->value = vcall(*arg3);
        func_0017C448(&a, 2);
    }
}
