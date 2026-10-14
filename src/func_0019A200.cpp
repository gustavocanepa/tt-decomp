typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct VE {
    s16 delta;
    s16 index;
    void *fn;
};

struct VObj {
    char pad0[0x0];
    char *vtbl;
};

extern char D_005E67A8[];

extern "C" void func_004A6500(int arg0, int arg1, ...);

static inline s32 vcall_98(char *o, void *a) {
    VE *e = (VE *)(((VObj *)o)->vtbl + 0x98);
    return ((s32 (*)(void *, void *))e->fn)(o + e->delta, a);
}

static inline s32 vcall_28(char *o) {
    VE *e = (VE *)(((VObj *)o)->vtbl + 0x28);
    return ((s32 (*)(void *))e->fn)(o + e->delta);
}

extern "C" s32 func_0019A200(void *arg0, s32 arg1) {
    s32 buf0[4];
    s32 spare[0x10];
    s32 s2 = 0;
    s32 s1;
    s32 v;
    s32 one = 1;
    s32 three = 3;
    char *self = (char *)arg0;

    func_004A6500((s32)buf0, (s32)D_005E67A8, arg1);

    s1 = vcall_98(self, buf0);
    v = vcall_28(self);

    if (v != 0 || s1 < 0) {
        s2 = 1;
    }
    if (s2 != 0) {
        return ((s1 ^ -2) == 0) ? three : one;
    }
    return 0;
}
