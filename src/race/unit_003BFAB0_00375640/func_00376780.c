#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0036BBF8(s32, s32, s32);               /* extern */
s32 func_00370958(s32, void *, s32);            /* extern */

struct func_00376780_arg0 {
    char pad0[0x60];
    void *unk60;
};

void func_00376780(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;

    temp_s0 = *(s32 *)((arg1 * 4) + M2C_FIELD(((struct func_00376780_arg0 *)arg0)->unk60, s32 *, 8));
    func_0036BBF8(temp_s0, arg2, arg3);
    func_00370958(temp_s0 + 0x1264, arg0 + 0x928, arg2);
}
