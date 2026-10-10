#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceCourse__getCheckPointCount(s32, s32);                    /* extern */

struct DynamicsConductorBattle2P__virtual_41_arg0 {
    char pad0[0x20A20];
    s32 unk20A20;
};

s32 DynamicsConductor__GetNumberOfSplits(struct DynamicsConductorBattle2P__virtual_41_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = RaceCourse__getCheckPointCount(arg0->unk20A20, 0) + 1;
    return (temp_v0 >= 0x11) ? 0x10 : temp_v0;
}
