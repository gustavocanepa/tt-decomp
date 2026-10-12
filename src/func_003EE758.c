#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00455FC0(void *, s32);                     /* extern */

s32 func_003EE758(void *arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    void *temp_s0;

    if (arg2 == 0x1000) {
        temp_s0 = M2C_FIELD(arg0, void **, 0x20);
        M2C_FIELD(temp_s0, s32 *, 0x8FC) = (s32) (func_00455FC0(arg0, arg4) + M2C_FIELD(temp_s0, s32 *, 0x900));
    }
    return -1;
}
