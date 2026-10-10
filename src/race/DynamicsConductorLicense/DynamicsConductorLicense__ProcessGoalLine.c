#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

void *func_002F04D8();                   /* extern */
s32 func_003A5048(void *, void *, s32);         /* extern */

struct DynamicsConductorLicense__virtual_22_arg0 {
    char pad0[0x238E2];
    u8 unk238E2;
};

s32 DynamicsConductorLicense__ProcessGoalLine(struct DynamicsConductorLicense__virtual_22_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    if (arg0->unk238E2 == 2) {
        func_003A5048(arg0, func_002F04D8(), arg5);
        M2C_FIELD(func_002F04D8(arg0, arg1), s32 *, 0x734) = arg4;
        return 1;
    }
    return 0;
}
