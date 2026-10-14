typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct E8 {
    s32 a;
    s32 b;
};

struct S00480F78 {
    s32 f0;
    s32 f4;
    E8 *top;
};

extern "C" f32 func_0043E0B0(E8 *);
extern "C" s32 func_0043E0F8(E8 *);
extern "C" void func_00447500(s32, s32, s32, s32, s32, s32);
extern "C" void func_00447CD8(S00480F78 *);
extern "C" void func_00447D00(S00480F78 *, s32);

extern "C" s32 *func_00442000(s32 *arg0, s32 arg1, u32 arg2, S00480F78 *arg3) {
    u32 n = arg2;
    s32 fp = 0;
    s32 s7 = -1;
    s32 s6 = -1;
    s32 s4 = -1;
    s32 s2 = -1;

    if (n != 0) {
        n -= 1;
        fp = func_0043E0F8(arg3->top - 1);
        func_00447CD8(arg3);
    }
    if (n >= 4U) {
        n -= 4;
        s7 = (s32)func_0043E0B0(arg3->top - 1);
        func_00447CD8(arg3);
        s6 = (s32)func_0043E0B0(arg3->top - 1);
        func_00447CD8(arg3);
        s4 = (s32)func_0043E0B0(arg3->top - 1);
        func_00447CD8(arg3);
        s2 = (s32)func_0043E0B0(arg3->top - 1);
        func_00447CD8(arg3);
    }
    func_00447D00(arg3, (s32)n);
    func_00447500(arg1, fp, s7, s6, s4, s2);
    *arg0 = 1;
    return arg0;
}
