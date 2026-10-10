#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s64 func_0040FB40(s32);                             /* extern */
s32 func_004F7B74(s32);                             /* extern */

void func_003F7FE8(s64 *arg0) {
    *arg0 = func_0040FB40(func_004F7B74(arg0 + 1));
}
