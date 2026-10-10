#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_0041AE30(s32 arg0, s32 arg1, f32 fparg0) {
    M2C_FIELD(((arg1 * 4) + arg0), f32 *, 0x68) = fparg0;
}
