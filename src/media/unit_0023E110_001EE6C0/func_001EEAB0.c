/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001EEAF8();                            /* extern */
s32 func_002661E8(s32, s32);                    /* extern */
s32 func_0042BE10();                            /* extern */

struct func_001EEAB0_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_001EEAB0(struct func_001EEAB0_arg0 *arg0, s32 arg1) {
    func_001EEAF8();
    func_0042BE10();
    func_002661E8(arg0->unk10, arg1);
}
