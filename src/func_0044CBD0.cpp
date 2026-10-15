typedef int s32;
struct A { char p[4]; s32 f4; };
struct T { s32 a; s32 b; s32 c; s32 d[5]; };
extern "C" void func_0044CBA8(void *, s32);
extern "C" void func_0047DC60(s32 *, s32, T *, s32);
extern "C" void func_0047DFB0(T *, s32);
extern "C" s32 func_004A4690(s32, s32);
extern "C" s32 func_0044CBD0(A *arg0, s32 arg1, s32 arg2, s32 arg3) {
    T t;
    s32 out[8];
    func_0047DFB0(&t, arg1);
    s32 s0 = t.c;
    if (arg2 == 0) {
        arg2 = func_004A4690(0x40, s0);
        arg0->f4 = 1;
    } else if (arg3 < s0) {
        return 0;
    }
    t.a = arg2;
    t.b = s0;
    func_0047DC60(out, arg1, &t, 1);
    if (out[0] == 0) {
        func_0044CBA8(arg0, arg2);
        return 1;
    }
    return 0;
}
