#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_003E6350(s32, s32, s32);               /* extern */

s32 func_003D9328(s32 arg0, s32 arg1) {
    func_003E6350(arg0, arg1 + 0x10, arg1 + 0x30);
    return arg0;
}
