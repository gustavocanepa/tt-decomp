#include "types.h"
#include "m2c_macros.h"
#define NULL 0

extern "C" s32 func_004A8368(s32);                             /* extern */
extern "C" M2C_UNK func_004F8588(s32, s32, s32);               /* extern */

extern char D_00579774[];
extern "C" void func_00117080(M2C_UNK arg0, s32 arg1) {
    s32 temp_v0;

    if (*(s32 *)D_00579774 != 0) {
        temp_v0 = func_004A8368(arg1);
        func_004F8588(*(s32 *)D_00579774 + 0x3CC, arg1, (temp_v0 < 0x40) ? temp_v0 : 0x3F);
    }
}
