#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6678(s32, s32, s32);       /* extern */

void func_0030E180(s32 arg0) {
    func_004F6678(arg0 + 0x20B24, 0, 0x24);
    func_004F6678(arg0 + 0x20B48, 0, 0x90);
}
