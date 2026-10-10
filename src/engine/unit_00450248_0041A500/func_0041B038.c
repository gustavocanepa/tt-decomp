#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_0041B038(s32 arg0, u32 arg1, f32 fparg0) {
    if (arg1 < 2U) {
        M2C_FIELD(((arg1 * 4) + arg0), f32 *, 0x80) = fparg0;
    }
}
