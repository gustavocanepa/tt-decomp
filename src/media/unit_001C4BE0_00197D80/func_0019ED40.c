#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
M2C_UNK func_0019EDC8(s32, s32, void *);            /* extern */
M2C_UNK func_004A45D0(s32);                         /* extern */

s32 func_0019ED40(s32 arg0, void **arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    struct StackFrame_0019ED40 { s8 pad0[0x4]; s32 sp4; s32 sp8; s32 spC; s8 pad1[0x10]; } sp_;
    s32 temp_s0;
    void *temp_v1;

    sp_.sp4 = 0;
    sp_.sp8 = 0;
    sp_.spC = 0;
    func_0019EDC8(arg0, arg4, ((s8 *)&sp_));
    temp_v1 = *arg1;
    temp_s0 = ({ VEntry *e1_ = (VEntry *)((char *)temp_v1 + 0x80); ((s32 (*)(void *, s32, s32, s32))e1_->fn)((char *)arg1 + e1_->delta, arg2, sp_.sp4, sp_.sp8 - sp_.sp4); }) == 0;
    if (sp_.sp4 != 0) {
        func_004A45D0(sp_.sp4);
    }
    return temp_s0;
}
