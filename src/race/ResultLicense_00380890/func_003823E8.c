#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s8, u8);                          /* extern */

struct func_003823E8_arg0 {
    char pad0[0x2];
    s8 unk2;
    char pad3[0x12];
    u8 unk15;
};

f32 func_003823E8(struct func_003823E8_arg0 *arg0) {
    return func_00381890(arg0->unk2, arg0->unk15) * 0x1.47ae140000000p-7f;
}
