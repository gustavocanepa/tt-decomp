#include "types.h"

extern char D_005A07E8[];
extern char D_005A07E4[];
extern char D_005A07E0[];
extern char D_00779FB8[];

extern "C" void func_004CCB58(void) {
    s32 *p = (s32 *)D_00779FB8;
    *(s32 *)D_005A07E8 = 0;
    *(s32 *)D_005A07E4 = 0;
    *(s32 *)D_005A07E0 = 0;
    p[1] = 0;
    p[0] = 0;
}
