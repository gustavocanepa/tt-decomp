#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceValueDisplayBase__structor_1();                            /* extern */

extern char D_005D10D0[];
struct RaceSpeedDisplay__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x50];
    f32 unk68;
    s32 unk6C;
};

s32 RaceSpeedDisplay__structor_0(struct RaceSpeedDisplay__structor_0_arg0 *arg0) {
    RaceValueDisplayBase__structor_1();
    arg0->unk14 = (s32)D_005D10D0;
    arg0->unk68 = -0x1.0000000000000p+0f;
    arg0->unk6C = 0;
}
