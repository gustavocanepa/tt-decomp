#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0055D980(s32);                             /* extern */

void func_0043BB18(s32 *arg0) {
    s32 temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        *arg0 = func_0055D980(temp_v0);
    }
}
