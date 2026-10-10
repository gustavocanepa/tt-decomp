#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 *func_004130E8();                       /* extern */

void func_00413448(s32 arg0, s32 arg1) {
    s32 *temp_v0;

    if (*func_004130E8() <= 0x7FFFFFFE) {
        temp_v0 = func_004130E8(arg0, arg1);
        *temp_v0 += 1;
    }
}
