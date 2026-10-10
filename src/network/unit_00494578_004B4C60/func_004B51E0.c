#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0();                            /* extern */
s32 func_004F6678(s32, s32, s32);       /* extern */

void func_004B51E0(s32 arg0) {
    func_004AE9C0();
    func_004F6678(arg0 + 0x30, 0, 0x120);
}
