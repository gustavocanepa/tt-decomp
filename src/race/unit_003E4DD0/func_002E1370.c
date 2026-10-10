#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E1428(void *);                      /* extern */
s32 func_004A4690(s32, s32);                /* extern */

struct func_002E1370_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x4];
    s32 unkC;
    char pad10[0x4];
    f32 unk14;
    f32 unk18;
};

void func_002E1370(struct func_002E1370_arg0 *arg0) {
    s32 temp_v0;

    arg0->unk0 = func_004A4690(0x40, 0x4000);
    temp_v0 = func_004A4690(0x40, 0x1400);
    arg0->unkC = 0;
    arg0->unk4 = temp_v0;
    arg0->unk14 = 0x1.0000000000000p+0f;
    arg0->unk18 = 0x1.0000000000000p+0f;
    func_002E1428(arg0);
}
