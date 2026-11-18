#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004368A8(M2C_UNK *, s32, M2C_UNK);     /* extern */
s32 func_00436968(M2C_UNK *, s32);                  /* extern */
s32 *func_004369F0(s32, M2C_UNK);                   /* extern */
s32 *func_00437CE8(M2C_UNK *, s32, void *, s32 *, f32); /* extern */

s32 *func_00438920(s32 arg0, s32 *arg1, f32 fparg0) {
    struct StackFrame_00438920 { s8 pad0[0x4]; s32 sp4; s8 pad1[0x8]; s32 sp10; s8 pad2[0xC]; } sp_;
    s32 *var_v0;

    var_v0 = func_004369F0(arg0, 5);
    if (var_v0 != NULL) {
        if (*func_004369F0(arg0, 5) < *arg1) {
            *arg1 = 0;
        }
        func_004368A8(&sp_.sp10, arg0, 5);
        var_v0 = func_00437CE8(&sp_.sp10, *arg1, ((s8 *)&sp_), &sp_.sp4, fparg0);
        if (var_v0 != NULL) {
            *arg1 = sp_.sp4;
            var_v0 = func_00436968(&sp_.sp10, sp_.sp4) + 0x38;
        }
    }
    return var_v0;
}
