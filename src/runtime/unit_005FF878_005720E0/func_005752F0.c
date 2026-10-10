#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004E81D0(s8, s32);                     /* extern */

s32 **func_005752F0(s32 **arg0, s8 arg1) {
    func_004E81D0(arg1, **arg0);
    return arg0;
}
