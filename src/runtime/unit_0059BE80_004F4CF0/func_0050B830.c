#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45F8(s32);                         /* extern */
s32 func_0050B7C8(s32, s32);                    /* extern */

void func_0050B830(s32 arg0) {
    func_0050B7C8(arg0, func_004A45F8(0x18));
}
