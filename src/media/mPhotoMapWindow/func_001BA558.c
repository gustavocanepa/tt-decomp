/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020E5B0(s32, s32);                /* extern */
s32 func_00210418(s32);                         /* extern */

void func_001BA558(s32 *arg0, s32 arg1) {
    func_00210418(arg1);
    func_0020E5B0(*arg0, 1);
}
