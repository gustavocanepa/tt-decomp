#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003F4158_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_003F4158(struct func_003F4158_arg0 *arg0) {
    arg0->unk8 = (s32) (arg0->unk8 - 1);
}
