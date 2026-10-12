#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_003ACC30(void *, s32);                 /* extern */
s32 *func_003ACC70(void *);                         /* extern */
M2C_UNK func_003ACD10(M2C_UNK *, s32);              /* extern */
f32 *func_003AD148(M2C_UNK *);                      /* extern */
f32 *func_003AD158(M2C_UNK *);                      /* extern */
f32 *func_003AD168(M2C_UNK *);                      /* extern */

void func_003BC7D8(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    struct StackFrame_003BC7D8 { s8 pad0[0x4]; s32 sp4; s8 pad1[0x8]; } sp_;

    func_003ACC30(((s8 *)&sp_), arg0);
    func_003ACD10(&sp_.sp4, arg0 + 0x40);
    *func_003ACC70(((s8 *)&sp_)) = 0;
    *func_003AD148(&sp_.sp4) = fparg0;
    *func_003AD158(&sp_.sp4) = fparg1;
    *func_003AD168(&sp_.sp4) = fparg2;
}
