/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00560FA0();                    /* extern */

void func_004604F0(s32 arg0, s32 arg1) {
    func_00560FA0(arg0 + 0xC);
    func_00560FA0(arg0 + 0x10, arg1);
}
