#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_005226A0(s32 arg0, s32 arg1, f32 fparg0) {
    M2C_FIELD(((arg1 * 0x48) + arg0), f32 *, 0x1413C) = fparg0;
}
