#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00473050();                            /* extern */

struct func_003F3EB8_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_003F3EB8(struct func_003F3EB8_arg0 *arg0) {
    func_00473050();
    arg0->unk8 = (s32) (arg0->unk8 + 1);
}
