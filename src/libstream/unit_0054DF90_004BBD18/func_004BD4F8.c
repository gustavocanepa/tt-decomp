#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void *func_004AE6D8(s32);                       /* extern */
s32 func_004AE750(s32, s32);                /* extern */

struct func_004BD4F8_temp_s0 {
    char pad0[0x4];
    s32 unk4;
    void *unk8;
    void *unkC;
};

void *func_004BD4F8(void) {
    struct func_004BD4F8_temp_s0 *temp_s0;

    temp_s0 = func_004AE6D8(0x24);
    temp_s0->unk4 = func_004AE750(0x10, 0x2000);
    temp_s0->unk8 = func_004AE6D8(0x44);
    temp_s0->unkC = func_004AE6D8(0x2C);
    return temp_s0;
}
