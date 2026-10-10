#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004D54B0_arg0 {
    char pad0[0x16];
    u16 unk16;
};

void func_004D54B0(struct func_004D54B0_arg0 *arg0) {
    arg0->unk16 = (u16) (arg0->unk16 & 0xFFFE);
}
