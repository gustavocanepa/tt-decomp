#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_003C7448(s32, s32, s32);               /* extern */

s32 func_003C74B0(s32 arg0, s32 arg1, s32 arg2) {
    func_003C7448(arg0, arg2, arg1 + 0xF0);
    return arg0;
}
