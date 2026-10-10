#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0030DBD0_temp_a0 {
    char pad0[0x464];
    f32 unk464;
    f32 unk468;
    f32 unk46C;
};

void func_0030DBD0(s32 arg0) {
    f32 temp_f0;
    struct func_0030DBD0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    temp_f0 = temp_a0->unk464;
    temp_a0->unk468 = (f32) (temp_f0 * 0x1.1111100000000p-6f);
    temp_a0->unk46C = (f32) (0x1.e000000000000p+5f / temp_f0);
}
