#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053DFD0_temp_a0 {
    char pad0[0x34];
    f32 unk34;
    char pad38[0x34];
    f32 unk6C;
    char pad70[0x4];
    s32 unk74;
};

void func_0053DFD0(s32 arg0, f32 fparg0) {
    struct func_0053DFD0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xB4;
    temp_a0->unk34 = fparg0;
    temp_a0->unk74 = 1;
    temp_a0->unk6C = fparg0;
}
