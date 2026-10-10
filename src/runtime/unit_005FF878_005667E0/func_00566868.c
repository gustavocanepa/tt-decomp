#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00418938(s32);                             /* extern */
s32 func_00418AB8();                                /* extern */
s32 func_00418BF0(s32, s32);                    /* extern */

void func_00566868(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = func_00418AB8();
    func_00418BF0(temp_s1, func_00418938(arg2));
}
