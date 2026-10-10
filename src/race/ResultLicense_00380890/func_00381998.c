#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004172F0();                                /* extern */
s32 func_004180D8(s32, s32);                    /* extern */

void func_00381998(s32 arg0) {
    func_004180D8(func_004172F0(), arg0);
}
