#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00553020(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg1 + arg0), s8 *, 0x164) != 0;
}
