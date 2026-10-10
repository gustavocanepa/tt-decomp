#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00228CB0_temp_a0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

s32 func_00228CB0(s32 arg0) {
    struct func_00228CB0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xD4;
    return ((s32) (temp_a0->unk8 - temp_a0->unk4) >> 2) * 0xCCCCCCCD;
}
