#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void **func_00509268();                             /* extern */

struct func_0050E2A0_temp_a0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x8];
    s64 unk20;
};

void *func_0050E2A0(void) {
    struct func_0050E2A0_temp_a0 *temp_a0;

    temp_a0 = *func_00509268();
    temp_a0->unk14 = 1;
    temp_a0->unk20 = (s64) (temp_a0->unk20 + 1);
    return temp_a0;
}
