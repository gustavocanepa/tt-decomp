#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00361AA8(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D0930[];
struct RaceMTRGravityMeter__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

void RaceMTRGravityMeter__structor_0(struct RaceMTRGravityMeter__structor_0_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14 = (s32)D_005D0930;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    func_00361AA8(arg0);
}
