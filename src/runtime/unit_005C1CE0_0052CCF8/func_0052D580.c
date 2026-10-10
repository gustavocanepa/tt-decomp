#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052D580_temp_a0 {
    char pad0[0x34];
    f32 unk34;
    f32 unk38;
    char pad3C[0x30];
    f32 unk6C;
    f32 unk70;
};

void func_0052D580(s32 arg0) {
    struct func_0052D580_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xB4;
    temp_a0->unk6C = (f32) temp_a0->unk34;
    temp_a0->unk70 = (f32) temp_a0->unk38;
}
