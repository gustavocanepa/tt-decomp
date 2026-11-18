/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" void ModelSet2__begin(void *, int) throw();             /* extern */
extern "C" void ModelSet2__end(void *) throw();                      /* extern */
extern "C" void ModelSet2___render(void *, s32, s32);            /* extern */
extern "C" s32 func_004A8268(s32, s32) throw();                        /* extern */
extern "C" void *func_00567378(s32, s32, void *, int, int); /* extern */

extern "C" void func_00420A40(void *arg0, s32 arg1, s32 arg2) {
    struct StackFrame_00455610 { s32 sp0; s32 sp4; s8 sp8; s8 pad0[0x7]; } sp_;
    s32 temp_a1;
    s32 temp_s2;
    s32 temp_v1;
    void *temp_v0;
    void *var_s0;

    sp_.sp0 = arg1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x58);
    if (temp_v1 != 0) {
        temp_s2 = temp_v1 + (M2C_FIELD(arg0, u16 *, 0x2A) * 8);
        sp_.sp4 = temp_v1;
        sp_.sp8 = 0;
        temp_v0 = func_00567378(temp_v1, temp_s2, ((s8 *)&sp_), 0, 0);
        if ((temp_v0 != (void *)temp_s2) && (func_004A8268(M2C_FIELD(temp_v0, s32 *, 0), sp_.sp0) == 0)) {
            var_s0 = (char *)temp_v0 + 8;
            ModelSet2__begin(arg0, 0);
            ModelSet2___render(arg0, M2C_FIELD(temp_v0, s32 *, 4), arg2);
loop_4:
            if ((var_s0 != (void *)temp_s2) && (func_004A8268(M2C_FIELD(var_s0, s32 *, 0), sp_.sp0) == 0)) {
                temp_a1 = M2C_FIELD(var_s0, s32 *, 4);
                var_s0 = (char *)var_s0 + 8;
                ModelSet2___render(arg0, temp_a1, arg2);
                goto loop_4;
            }
            ModelSet2__end(arg0);
        }
    }
}
