#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern f32 D_00583A0C[];
struct func_00317F20_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00317F20(struct func_00317F20_arg0 *arg0, s32 arg1) {
    if (arg1 <= 0) arg1 = 1;
    if (arg1 > 16) arg1 = 16;
    arg0->unk4 = D_00583A0C[arg1] * 100.0f;
}
