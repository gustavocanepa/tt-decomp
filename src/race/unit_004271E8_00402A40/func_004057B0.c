#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_004057B0_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};

void func_004057B0(void *arg0, s32 arg1, s16 arg2) {
    M2C_FIELD(((((((struct func_004057B0_arg0 *)arg0)->unk4D8 * 0xC8) + arg1) * 2) + arg0), s16 *, 0x118) = arg2;
}
