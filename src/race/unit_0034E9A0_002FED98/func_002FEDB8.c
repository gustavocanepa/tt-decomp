#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s8 func_002FEDB8(s32 arg0, s32 arg1) {
    if (arg1 < 4) {
        return M2C_FIELD((arg1 + arg0), s8 *, 0x7D0);
    }
    return 0;
}
