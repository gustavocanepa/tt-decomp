typedef int s32;
typedef float f32;

extern "C" s32 func_00508F38(f32 fparg0) {
    s32 r = (s32)fparg0;
    if (fparg0 >= 0x1p63f) {
        r = (s32)(fparg0 + -0x1p63f);
    }
    return r;
}
