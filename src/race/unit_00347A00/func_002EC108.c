#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004311F8(s32);                         /* extern */

struct func_002EC108_temp_s0 {
    char pad0[0x487];
    u8 unk487;
    char pad488[0x28];
    f32 unk4B0;
};

void func_002EC108(s32 arg0) {
    struct func_002EC108_temp_s0 *temp_s0;

    func_004311F8(arg0 + 0x14);
    temp_s0 = arg0 + 0x104;
    if (temp_s0->unk487 == 8) {
        temp_s0->unk4B0 = 1.0f;
    }
}
