#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0044C9F8(s32, s32);                /* extern */
s32 func_0044CC90();                            /* extern */
s32 func_0050E1A8(s32);                         /* extern */

void func_003F60D0(s32 arg0, s32 arg1) {
    func_0044CC90();
    func_0044C9F8(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
