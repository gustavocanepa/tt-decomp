#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F56B0_temp_a0 {
    char pad0[0x51A];
    s16 unk51A;
    char pad51C[0x134];
    f32 unk650;
    s32 unk654;
};

void func_002F56B0(s32 arg0) {
    struct func_002F56B0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    temp_a0->unk654 = 0;
    temp_a0->unk650 = (f32) temp_a0->unk51A;
}
