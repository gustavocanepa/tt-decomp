#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s8, u8);                          /* extern */

struct func_003823B8_arg0 {
    char pad0[0x1];
    s8 unk1;
    char pad2[0x12];
    u8 unk14;
};

f32 func_003823B8(struct func_003823B8_arg0 *arg0) {
    return func_00381890(arg0->unk1, arg0->unk14) * 0x1.47ae140000000p-7f;
}
