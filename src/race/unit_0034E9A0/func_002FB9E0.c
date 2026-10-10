#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002F04D8();                              /* extern */
s32 func_00305CB0(s32, s32, s32, s32, s32, s32, u8); /* extern */

void func_002FB9E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 frag0;
    frag0 = M2C_FIELD(func_002F04D8(), u8 *, 0x5D7);
    func_00305CB0(arg0, arg1, arg2 - 1, arg3, arg5, arg6, frag0);
}
