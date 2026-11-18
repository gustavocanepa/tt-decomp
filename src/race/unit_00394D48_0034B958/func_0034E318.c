#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_0034E690(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32); /* extern */
M2C_UNK func_00390438(s32, void *, f32, f32, f32, f32, f32); /* extern */

void func_0034E318(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    struct StackFrame_0034E318 { f32 sp0; f32 sp4; f32 sp8; s8 pad0[0x4]; } sp_;

    if (M2C_FIELD(arg0, s32 *, 0x10) & 0x400) {
        func_0034E690(((s8 *)&sp_), arg1, arg2, arg3, arg4, arg5, arg6, arg7, M2C_FIELD(arg0, f32 *, 0x9DC), M2C_FIELD(arg0, f32 *, 0x9E0));
        sp_.sp0 *= 0x1.4000000000000p+3f;
        sp_.sp4 *= 0x1.4000000000000p+3f;
        sp_.sp8 *= 0x1.4000000000000p+3f;
        func_00390438(arg1, ((s8 *)&sp_), M2C_FIELD(arg0, f32 *, 0x9C0), M2C_FIELD(arg0, f32 *, 0x9C4), M2C_FIELD(arg0, f32 *, 0x9C8), M2C_FIELD(arg0, f32 *, 0x9D8), M2C_FIELD(arg0, f32 *, 0x9D4) * 0x1.4000000000000p+3f);
    }
}
