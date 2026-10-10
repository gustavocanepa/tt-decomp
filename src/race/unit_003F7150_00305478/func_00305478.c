#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002E4CB8(void *);
void *func_002F04D8(s32, s32);
struct func_00305478_temp_v0 {
    char pad0[0x5D2];
    u8 unk5D2;
};

s16 func_00305478(s32 arg0, s32 arg1, u8 *arg2) {
    struct func_00305478_temp_v0 *temp_v0;
    temp_v0 = func_002F04D8(arg0, arg1);
    *arg2 = temp_v0->unk5D2;
    return func_002E4CB8(temp_v0);
}
