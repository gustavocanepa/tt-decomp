#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF508();                                /* extern */
s32 func_004AF7D0(s32);                             /* extern */
s32 func_004AF928(s32, s32);                    /* extern */

void func_004AF8E8(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_004AF508();
    func_004AF928(temp_s1, func_004AF7D0(arg0 + 4));
}
