#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00418AB8();                                /* extern */
s32 func_00418BF0(s32, s32);                    /* extern */

void func_00418BC0(s32 arg0, s32 arg1, s32 arg2) {
    func_00418BF0(func_00418AB8(), arg2);
}
