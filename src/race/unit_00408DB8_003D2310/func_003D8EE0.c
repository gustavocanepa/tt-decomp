#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D8280();                            /* extern */
s32 func_003E32B8(s32);                         /* extern */

void func_003D8EE0(s32 arg0) {
    func_003D8280();
    func_003E32B8(arg0 + 0x170);
}
