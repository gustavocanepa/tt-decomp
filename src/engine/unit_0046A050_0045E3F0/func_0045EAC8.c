#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045EAC8_temp_a0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    char padC[0x4];
    s32 unk10;
};

void func_0045EAC8(s32 arg0) {
    struct func_0045EAC8_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x10;
    temp_a0->unk4 = 0;
    temp_a0->unk10 = (s32) temp_a0->unk8;
}
