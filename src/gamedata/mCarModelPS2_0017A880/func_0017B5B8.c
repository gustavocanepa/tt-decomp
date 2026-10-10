/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001782B0(s32);                         /* extern */

void func_0017B5B8(s32 arg0) {
    func_001782B0(arg0 + 0x170);
    func_001782B0(arg0 + 0x184);
    func_001782B0(arg0 + 0x198);
    func_001782B0(arg0 + 0x1AC);
    func_001782B0(arg0 + 0x1D4);
}
