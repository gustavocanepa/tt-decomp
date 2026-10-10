#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A5750_temp_a0 {
    char pad0[0x4A8];
    f32 unk4A8;
    char pad4AC[0x8];
    f32 unk4B4;
};

f32 func_003A5750(s32 arg0, s32 arg1, f32 *arg2) {
    struct func_003A5750_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    *arg2 = temp_a0->unk4B4;
    return temp_a0->unk4A8;
}
