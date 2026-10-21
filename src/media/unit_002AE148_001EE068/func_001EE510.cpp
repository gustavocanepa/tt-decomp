typedef int s32;
typedef float f32;

struct VEntry_60 {
    short delta;
    short index;
    f32 (*fn)(void *);
};

struct VObj_60 {
    char pad0[4];
    VEntry_60 *vtbl;
};

static inline f32 vcall_60(char *o) {
    VEntry_60 *e = (VEntry_60 *)((char *)((VObj_60 *)o)->vtbl + 0x70);
    return e->fn(o + e->delta);
}

struct Obj_0023F9C0;

extern "C" void func_001EDBE0(void *arg0, int arg1);
extern "C" void func_001EDC38(void *arg0, void *arg1);
extern "C" void func_001EEC28(Obj_0023F9C0 *arg0, float arg1);

struct A {
    void *p;
    s32 pad[3];
};

extern "C" void func_001EE510(void *arg0, void *arg1, s32 arg2, void **arg3) {
    A a;
    f32 v = 1.0f;
    if (arg2 == 1) {
        v = vcall_60((char *)*arg3);
    }
    func_001EDC38(&a, arg1);
    func_001EEC28((Obj_0023F9C0 *)a.p, v);
    func_001EDBE0(&a, 2);
}
