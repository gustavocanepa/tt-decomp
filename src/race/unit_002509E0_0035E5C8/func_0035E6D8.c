#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035E6D8_temp_a0 {
    char pad0[0x54];
    s32 unk54;
};

void func_0035E6D8(s32 arg0, s32 arg1) {
    struct func_0035E6D8_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xA44;
    temp_a0->unk54 = (s32) ((temp_a0->unk54 & 0xFFFFFF) | (arg1 << 0x18));
}
