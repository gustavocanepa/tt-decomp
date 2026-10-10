#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_004A8368(s32);                             /* extern */
s32 func_0050F1B0(void **, s32, s32, s32, s32); /* extern */

void **func_002C17E0(void **arg0, s32 arg1) {
    func_0050F1B0(arg0, M2C_FIELD(*arg0, s32 *, -0x10), 0, arg1, func_004A8368(arg1));
    return arg0;
}
