typedef int s32;
struct VEntry_58 { short delta; short index; s32 (*fn)(void *); };
struct VObj_58 { char pad0[4]; VEntry_58 *vtbl; };
static inline s32 vcall_58(char *o) {
    VEntry_58 *e = (VEntry_58 *)((char *)((VObj_58 *)o)->vtbl + 0x68);
    return e->fn(o + e->delta);
}
extern "C" void func_00139C38(void *, void *);
extern "C" void func_00139BE0(void *, s32);
extern "C" void func_0013C530(void *, s32);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_0013A9D0(void *arg0, void *arg1, s32 arg2, char **arg3) {
    A a;
    s32 v;
    if (arg2 > 0) {
        v = vcall_58(*arg3) != 0;
    } else {
        v = 1;
    }
    func_00139C38(&a, arg1);
    func_0013C530(a.p, v);
    func_00139BE0(&a, 2);
}
