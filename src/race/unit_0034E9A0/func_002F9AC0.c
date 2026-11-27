#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F9A40();                                /* extern */
s32 func_002F9A60(s32, f32);                    /* extern */

struct func_002F9AC0_temp_s0 {
    char pad0[0x4];
    s8 unk4;
    s8 unk5;
};

void func_002F9AC0(s32 arg0) {
    struct func_002F9AC0_temp_s0 *temp_s0;

    if (func_002F9A40() != 0) {
        temp_s0 = arg0 + 0x7E4;
        func_002F9A60(arg0, 0x1.0000000000000p+0f);
        temp_s0->unk4 = 0;
        temp_s0->unk5 = 0;
    }
}
