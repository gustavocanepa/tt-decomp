#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001B4B10(s32);                         /* extern */
void *func_00541D18();                              /* extern */

s32 func_0025CDD0(s32 arg0) {
    if (M2C_FIELD(func_00541D18(), s32 *, 8) == 0) {
        func_001B4B10(arg0);
    }
}
