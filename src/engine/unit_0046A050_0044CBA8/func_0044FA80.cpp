#include "types.h"

extern "C" char D_00586A50[];

extern "C" void func_0044FA80(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        union { s32 i; f32 f; } zu;
        f32 one = 1.0f;
        zu.i = 0;
        f32 z = zu.f;
        f32 *p = (f32 *)D_00586A50;
        p[0] = z;
        p[1] = z;
        p[3] = one;
        p[2] = z;
    }
}
