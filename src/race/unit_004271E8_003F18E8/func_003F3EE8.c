/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004730A8();                            /* extern */

struct func_003F3EE8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_003F3EE8(struct func_003F3EE8_arg0 *arg0) {
    arg0->unk8 = (s32) (arg0->unk8 - 1);
    func_004730A8();
}
