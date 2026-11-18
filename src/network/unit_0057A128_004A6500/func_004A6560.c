#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004A6AA0(M2C_UNK *, s32, s32);             /* extern */
M2C_UNK func_004A7B48(M2C_UNK *, M2C_UNK, void *, M2C_UNK); /* extern */
M2C_UNK func_004A7B90(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_004A7BF8(M2C_UNK *);                   /* extern */

s32 func_004A6560(s32 arg0, s32 arg1) {
    struct StackFrame_004A6560 { s8 pad0[0x40]; s32 sp40; s8 pad1[0x2C]; } sp_;
    s32 temp_s1;

    func_004A7B48(&sp_.sp40, 1, ((s8 *)&sp_), 0x40);
    temp_s1 = func_004A6AA0(&sp_.sp40, arg0, arg1);
    func_004A7BF8(&sp_.sp40);
    func_004A7B90(&sp_.sp40, 2);
    return temp_s1;
}
