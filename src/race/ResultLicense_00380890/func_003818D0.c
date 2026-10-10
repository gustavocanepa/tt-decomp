#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003826E0();                            /* extern */
s32 func_00382A80(s32, s32);                    /* extern */

void func_003818D0(s32 arg0, s32 arg1, s32 arg2) {
    func_003826E0();
    func_00382A80(arg0, arg2);
}
