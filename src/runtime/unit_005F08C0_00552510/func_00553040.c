#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_00553040(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(((arg1 * 4) + arg0), s32 *, 0x140) = arg2;
}
