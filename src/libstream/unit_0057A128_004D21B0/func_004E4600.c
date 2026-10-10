#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004E42B0();                            /* extern */
s32 func_004F5140(s32);                         /* extern */

extern char D_005A30A8[];
s32 func_004E4600(void **arg0) {
    if (M2C_FIELD(*arg0, s64 *, 0x10) & 0x2000) {
        func_004E42B0();
    }
    if (M2C_FIELD(*arg0, s64 *, 0x10) & 0x4000) {
        func_004F5140(M2C_FIELD(*(void **)(s32)D_005A30A8, s32 *, 8));
        func_004F5140(M2C_FIELD(*(void **)(s32)D_005A30A8, s32 *, 0xC));
    }
}
