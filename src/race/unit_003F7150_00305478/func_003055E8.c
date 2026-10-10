#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

u16 func_003055E8(s32 arg0, s32 arg1) {
    return M2C_FIELD(((arg1 * 2) + arg0), u16 *, 0x21840);
}
