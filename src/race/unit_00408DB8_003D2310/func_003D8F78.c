#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D8378();                            /* extern */
s32 func_003E3A60(s32, s32);                    /* extern */

s32 func_003D8F78(s32 arg0, s32 arg1) {
    func_003D8378();
    func_003E3A60(arg0 + 0x170, arg1 + 0x170);
    return arg0;
}
