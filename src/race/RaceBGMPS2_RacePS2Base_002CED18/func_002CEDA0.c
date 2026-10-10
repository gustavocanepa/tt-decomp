#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002CEDA0_temp_a0 {
    char pad0[0x34];
    s32 unk34;
};

void func_002CEDA0(s32 arg0) {
    struct func_002CEDA0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xD038;
    temp_a0->unk34 = (s32) (temp_a0->unk34 ^ 1);
}
