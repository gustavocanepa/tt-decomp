/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern s32 D_00579518;
extern "C" void func_00104868(void *, s32);
extern "C" void func_00104960(void *, s32);
extern "C" void func_00104A28(void *, s32);
extern "C" void func_00104A38(void *, s32);
extern "C" void func_00104A88(void *, s32);
extern "C" void func_00104B10(void *);
extern "C" void func_00104C88(void *);
extern "C" s32 func_00104E00(void *);
extern "C" void func_00465AF0(void *, s32, float, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_00473178(s32);
extern "C" void pglPushAttrib(s32);
extern "C" void func_004752F8(void *);
extern "C" void func_00478C98(s32);

static inline s32 first(s32 *p) { return *p; }

extern "C" void func_00390140(char *arg0, s32 arg1) {
    s32 sp20[16];
    char *s4 = arg0 + 0x8C;
    char *s3 = arg0 + 0xC8;
    pglPushAttrib(0x8C7);
    func_00104A28(s4, 0x40);
    float f = 0x1.36c8b4p+0f;
    func_00104A38(s4, 8);
    *(s32 *)(s4 + 4) = 0;
    func_00104B10(s4);
    func_00104A28(s3, 0x40);
    func_00104A38(s3, 0x40);
    *(s32 *)(s3 + 4) = 0;
    func_00104B10(s3);
    func_00478C98(8);
    s32 *ps = sp20;
    func_00104960(ps, arg1);
    func_00104A88(ps, 0);
    func_00104C88(ps);
    if (D_00579518 == 0) f = 0x1.d26e96p-1f;
    s32 s0 = first(ps);
    s32 s1 = sp20[2];
    func_00465AF0(arg0, s0, f, s1, func_00104E00(ps), *(s32 *)s4, 8, *(s32 *)s3, 0x40, 0x40,
                  *(s32 *)(arg0 + 0x7C), *(s32 *)(arg0 + 0x84));
    *(s32 *)(arg0 + 0xA28) = 0;
    *(s32 *)(arg0 + 0xA34) = 0;
    *(s32 *)(arg0 + 0x1848) = 0;
    func_00473178(1);
    func_004752F8(arg0 + 0x21B0);
    func_00473178(0);
    *(float *)(arg0 + 0x21AC) = *(float *)(arg0 + 0x21C4);
    func_00104868(ps, 2);
}
