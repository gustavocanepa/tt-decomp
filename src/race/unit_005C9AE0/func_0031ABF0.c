#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0031ABF0_arg0 {
    char pad0[0xA4C];
    s32 unkA4C;
};

void func_0031ABF0(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((((struct func_0031ABF0_arg0 *)arg0)->unkA4C * 0x1B4) + arg0), s32 *, 0x1BC) = arg1;
    M2C_FIELD(((((struct func_0031ABF0_arg0 *)arg0)->unkA4C * 0x1B4) + arg0), s32 *, 0x1C0) = arg2;
}
