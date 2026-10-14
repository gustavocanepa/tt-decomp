typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef float f32; typedef double f64;

extern "C" f32 func_004EE530(f32);                  /* extern */

extern "C" f32 *func_003E78E8(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    if (((fparg0 + fparg1) < fparg2) || ((fparg0 * fparg1) == 0.0f)) {
        *arg0 = 0.0f;
    } else {
        *arg0 = 1.5707963f - func_004EE530((((fparg0 * fparg0) + (fparg1 * fparg1)) - (fparg2 * fparg2)) / (2.0f * fparg0 * fparg1));
    }
    return arg0;
}
