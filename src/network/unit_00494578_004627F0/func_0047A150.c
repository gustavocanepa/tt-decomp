#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_0047F9A8(void *);                      /* extern */
M2C_UNK func_0047F9D8(void *, M2C_UNK);             /* extern */
s32 func_0047FA40(void *, s32, s32, s32, s32, M2C_UNK); /* extern */

s32 func_0047A150(M2C_UNK arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct StackFrame_004B1B10 { s8 pad0[0x110]; } sp_;
    s32 temp_s0;

    func_0047F9A8(((s8 *)&sp_));
    temp_s0 = func_0047FA40(((s8 *)&sp_), arg1, arg2, arg3, arg4, 0);
    func_0047F9D8(((s8 *)&sp_), 2);
    return temp_s0;
}
