typedef int s32;
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}
extern "C" void *func_001FCB58(void *);
extern "C" void func_001FCB00(void *, s32);
extern "C" void func_0029B380(void *, float);
extern "C" void func_00299AB0(void *, s32);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

struct Target {
    char pad0[0xD8];
    float value;
};
struct A {
    Target *p;
    s32 pad[3];
};

extern "C" void func_001FE0B0(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    if (arg2 == 0) {
        func_001FCB58(&a);
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
        func_001FCB00(&a, 2);
    } else if (arg2 == 1) {
        func_001FCB58(&a);
        Target *t = a.p;
        t->value = vcall_60(*arg3);
        func_001FCB00(&a, 2);
    }
}
