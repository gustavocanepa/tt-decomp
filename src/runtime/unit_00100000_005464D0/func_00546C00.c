#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00546C00_temp_a0 {
    char pad0[0x38];
    f32 unk38;
    char pad3C[0x34];
    f32 unk70;
    s32 unk74;
};

void func_00546C00(s32 arg0, f32 fparg0) {
    struct func_00546C00_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xE4;
    temp_a0->unk38 = fparg0;
    temp_a0->unk74 = 1;
    temp_a0->unk70 = fparg0;
}
