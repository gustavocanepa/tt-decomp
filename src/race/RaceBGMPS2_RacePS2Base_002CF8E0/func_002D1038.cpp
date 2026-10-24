#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct G {
    char pad[0x20];
    float f18;
    s32 i1c;
    char pad2[0x134 - 0x20];
};

extern G D_005794F0[];

extern "C" void func_00104868(void *, s32);
extern "C" void *func_00104960(void *, void *);
extern "C" void func_00104C88(void *);
extern "C" void func_00104DE0(void *);
extern "C" void *func_001050C0(void *, s32, s32, s32);
extern "C" void func_00105230(void *, void *, s32, s32, float, float, float, float);
extern "C" void func_0038B758(void *);
extern "C" void func_0038B818(void *, float, float);
extern "C" void func_0038B848(void *);
extern "C" void func_0038BD20(void *, void *, void *, void *, void *, float, s32, float, float, float);
extern "C" void func_0046F0F8(s32);
extern "C" void func_00478C98(s32);

typedef s32 (*TestFn)(char *);

extern "C" void func_002D1038(char *arg0, void *arg1, s32 arg2, void *arg3, void *arg4, float fp0, float fp1, float fp2) {
    char sp[0xC0];
    char obj[0x40];
    char *s1 = *(char **)(*(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4) + 0x80);
    func_00104DE0(arg1);
    float f20 = *(float *)(s1 + 0x38);
    func_001050C0(arg4, arg2, 0, 0);
    VEntry *e = (VEntry *)(*(char **)(arg0 + 0x64) + 0x498);
    if (((TestFn)e->fn)(arg0 + e->delta) != 0) {
        func_0038B758(sp);
        func_00104C88(arg3);
        func_0046F0F8(5);
        func_00478C98(6);
        G *g1 = &D_005794F0[1];
        func_00104960(obj, g1);
        *(s32 *)(obj + 4) = 1;
        func_0038B818(sp, fp0, 0x1.553f7c0000000p+0f);
        *(float *)(sp + 8) = fp1;
        *(float *)(sp + 0x10) = fp2;
        func_0038B848(sp);
        s32 ia = (g1 - 1)->i1c;
        float fa = (g1 - 1)->f18;
        func_0038BD20(sp, arg3, arg1, arg4, obj, fa, ia, f20, f20, f20);
        func_00104868(obj, 2);
        func_00104868(sp + 0x2C, 2);
    } else {
        func_00478C98(5);
        func_00105230(arg3, arg1, D_005794F0[0].i1c, 0, D_005794F0[0].f18, f20, f20, f20);
    }
}
