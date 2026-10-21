#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004158D0(void *, void *, void *);      /* extern */
M2C_UNK func_00474CB8(s32, M2C_UNK);                /* extern */

s32 func_00415A58(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    struct StackFrame_00415A58 { f32 sp0; f32 sp4; f32 sp8; s8 pad0[0x4]; } sp_;
    s32 temp_f1;

    sp_.sp0 = fparg0;
    sp_.sp4 = fparg1;
    sp_.sp8 = fparg2;
    func_004158D0(arg0, ((s8 *)&sp_), ((s8 *)&sp_));
    M2C_FIELD(arg0, f32 *, 8) = sp_.sp0;
    M2C_FIELD(arg0, f32 *, 0xC) = sp_.sp4;
    temp_f1 = (s32) (sp_.sp8 * 0x1.0000000000000p+23f);
    func_00474CB8(temp_f1, 0xFF);
    return temp_f1;
}
