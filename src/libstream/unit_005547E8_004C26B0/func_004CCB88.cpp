#include "types.h"

extern "C" int D_005A07E0;
extern "C" int D_005A07E4;
extern "C" int D_005A07E8;
extern "C" char D_00779FC0[];

extern "C" void func_004CCB88(void) {
    s32 *src = (s32 *)&D_00779FC0[0x4380 - 0x4380];
    D_005A07E8 = src[0];
    D_005A07E4 = src[1];
    D_005A07E0 = src[2];
}
