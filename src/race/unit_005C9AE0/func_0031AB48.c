#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_0031AB48_arg0 {
    char pad0[0xCE4];
    s32 unkCE4;
};

void func_0031AB48(void *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((arg1 * 0x1B4) + arg0), s32 *, 0x15C) = 7;
    ((struct func_0031AB48_arg0 *)arg0)->unkCE4 = arg2;
}
