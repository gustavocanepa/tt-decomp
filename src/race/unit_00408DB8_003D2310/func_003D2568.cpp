/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef int s32;

extern "C" void func_003D2568(s32 a0, s32 a1, f32 *a2, f32 *a3, s32 *t0, f32 *t1, f32 *t2, f32 *t3,
                              f32 fp0, f32 fp1,
                              s32 d8, s32 d9, s32 d10, s32 d11, s32 d12, s32 d13, s32 d14, s32 d15,
                              s32 *sp40) {
    *t1 += fp1;
    *sp40 = 0;
    f32 v = *t1;
    *a2 = v;
    *a3 = v;
    *t0 = 0;
    f32 w = *(f32 *)t0;
    *t3 = w;
    *t2 = w;
}
