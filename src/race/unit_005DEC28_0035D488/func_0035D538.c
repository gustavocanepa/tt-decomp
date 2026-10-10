#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035D538_temp_a0 {
    char pad0[0x34];
    s32 unk34;
};

void func_0035D538(s32 arg0, s32 arg1) {
    struct func_0035D538_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x128;
    temp_a0->unk34 = (s32) ((temp_a0->unk34 & 0xFFFFFF) | (arg1 << 0x18));
}
