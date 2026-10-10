#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004E4600();                            /* extern */

s32 func_005752C0(void **arg0) {
    if (M2C_FIELD(*arg0, s64 *, 0x10) & 0x6000) {
        func_004E4600();
    }
}
