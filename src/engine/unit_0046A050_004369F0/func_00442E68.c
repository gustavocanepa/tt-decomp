#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00447D00(s32, s32);                    /* extern */
s32 func_004F73A0();                                /* extern */

f32 func_00442E68(s32 arg0, s32 arg1) {
    func_00447D00(arg1, arg0);
    return (f32) func_004F73A0() / 0x1.fffffe0000000p+30f;
}
