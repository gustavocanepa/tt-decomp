#include "types.h"

extern "C" f32 D_00768E30[][24];

extern "C" void func_003A0B20(s32 arg0, s32 arg1, f32 fparg0) {
    D_00768E30[arg0][arg1] = fparg0;
}
