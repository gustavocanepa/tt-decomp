#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E72F0(s32, s32);                /* extern */
s32 func_002E7418(s32);                         /* extern */
s32 func_00425DE0(s32);                     /* extern */

void func_002F2070(s32 arg0) {
    func_002E72F0(arg0, -1);
    func_00425DE0(arg0 + 0x218D0);
    func_002E7418(arg0);
}
