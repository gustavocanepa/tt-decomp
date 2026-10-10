/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0040FC28(s64, s32);                    /* extern */

void func_003F8020(s64 *arg0, s64 arg1) {
    *arg0 = arg1;
    func_0040FC28(arg1, arg0 + 1);
}
