#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6678(s32, s32, s32);       /* extern */

void func_002FEF78(s32 arg0) {
    func_004F6678(arg0 + 0x7D0, 0, 4);
    func_004F6678(arg0 + 0x7D4, 0, 0x10);
}
