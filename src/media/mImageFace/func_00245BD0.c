#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00245BD0_arg0 {
    char pad0[0x174];
    u8 unk174;
};

f32 func_00245BD0(struct func_00245BD0_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = (f32) arg1 / (f32) arg0->unk174;
    return (temp_f0 + 0x1.0000000000000p+0f) / temp_f0;
}
