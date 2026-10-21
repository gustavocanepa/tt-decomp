typedef int s32;
struct VEntry_60 { short delta; short index; float (*fn)(void *); };
struct VObj_60 { char pad0[4]; VEntry_60 *vtbl; };
static inline float vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}
extern "C" void func_0017C4A0(void *, void *);
extern "C" void func_0017C448(void *, s32);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_0017F2B8(void *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    float v = vcall_60(*arg3);
    func_0017C4A0(&a, arg1);
    *(float *)((char *)a.p + 0x110) = v;
    func_0017C448(&a, 2);
}
