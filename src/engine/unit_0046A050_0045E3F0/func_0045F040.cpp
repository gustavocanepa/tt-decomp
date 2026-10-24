/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct S00490640;
extern "C" f32 func_0045F008(S00490640 *arg0);

struct S00490660 {
    char pad0[0x48];
    f32 f30;
    char pad1[0x18];
    s32 i4C;
    char pad2[0x4];
    f32 f54;
    char pad3[0x4];
    f32 f5C;
};

extern "C" s32 func_0045F040(S00490660 *arg0, f32 fparg0) {
    arg0->f30 = arg0->f30 + fparg0;
    if (arg0->i4C != 0) {
        return 1;
    }
    f32 t = func_0045F008((S00490640 *)arg0);
    f32 x = (arg0->f5C - arg0->f54) - t;
    if (arg0->f30 < x) {
        return 1;
    }
    return 0;
}
