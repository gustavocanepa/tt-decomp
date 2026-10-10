#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002CD1A8();                            /* extern */

struct func_002CD168_temp_s0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void *func_002CD168(s32 arg0) {
    struct func_002CD168_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x110;
    if (temp_s0->unk8 == temp_s0->unk4) {
        func_002CD1A8();
    }
    return temp_s0;
}
