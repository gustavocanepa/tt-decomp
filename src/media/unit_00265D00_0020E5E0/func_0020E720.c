#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020E570();                                /* extern */
s32 func_0020E580(s32, s32);                /* extern */

s32 func_0020E720(s32 arg0) {
    s32 temp_s1;

    temp_s1 = func_0020E570();
    func_0020E580(arg0, 0);
    return temp_s1;
}
