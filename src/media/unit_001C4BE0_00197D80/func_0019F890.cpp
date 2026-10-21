typedef int s32;
typedef signed char s8;

struct VE1D0228 {
    short delta;
    short index;
    void *fn;
};

extern "C" void func_0019B8F8(void *arg0, s32 arg1);
extern "C" s32 func_0019ECC8(void *arg0);
extern "C" s32 func_0042F4F8(void *arg0);
extern "C" s32 func_0042F830(s32 id);
extern "C" void func_0042F870(s8 *arg0);

extern "C" void func_0019F890(void *arg0, s32 *arg1, s32 *arg2) {
    char *self = (char *)arg0;
    VE1D0228 *e1 = (VE1D0228 *)(*(char **)(self + 0x4C) + 0x150);
    char *s1 = (char *)func_0042F830(((s32 (*)(void *, void *))e1->fn)(self + e1->delta, arg1));
    VE1D0228 *e2 = (VE1D0228 *)(*(char **)s1 + 0x48);
    ((void (*)(void *, void *))e2->fn)(s1 + e2->delta, self + 0x68);
    func_0019B8F8(arg0, 1);
    s32 s0 = (func_0042F4F8(s1) + 0x47) & ~0x3F;
    func_0042F870((s8 *)s1);
    s32 q = s0 + 0x3FF;
    s0 = s0 + 0x7FE;
    if (q < 0) {
        q = s0;
    }
    *arg1 = 2;
    *arg2 = q >> 10;
    s32 r = func_0019ECC8(arg0);
    s32 u = r + 0x3FF;
    s32 w = r + 0x7FE;
    if (u < 0) {
        u = w;
    }
    *arg2 += u >> 10;
}
