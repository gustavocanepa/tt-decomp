#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_003BD3F0(void *, s32);                 /* extern */
s32 *func_003BD4A8(void *);                         /* extern */
M2C_UNK func_003BD670(M2C_UNK *, s32);              /* extern */
f32 *func_003BD8D0(M2C_UNK *);                      /* extern */
f32 *func_003BD8E0(M2C_UNK *);                      /* extern */
f32 *func_003BD8F0(M2C_UNK *);                      /* extern */

void func_003C17A0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    struct StackFrame_003C17A0 { s8 pad0[0x4]; s32 sp4; s8 pad1[0x8]; } sp_;

    func_003BD3F0(((s8 *)&sp_), arg0);
    func_003BD670(&sp_.sp4, arg0 + 0x40);
    *func_003BD4A8(((s8 *)&sp_)) = 0xB;
    *func_003BD8D0(&sp_.sp4) = fparg0;
    *func_003BD8E0(&sp_.sp4) = fparg1;
    *func_003BD8F0(&sp_.sp4) = fparg2;
}
