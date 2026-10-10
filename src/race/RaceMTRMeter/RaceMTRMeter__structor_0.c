#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0035E778(s32);                         /* extern */
s32 func_00360D20(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D09F0[];
struct RaceMTRMeter__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    char pad30[0x3C];
    s32 unk6C;
};

void RaceMTRMeter__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk14 = (s32)D_005D09F0;
    func_0035E778(arg0 + 0x4C);
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk18 = 0;
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk1C = 0;
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk20 = 0;
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk24 = 0;
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk28 = 0;
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk2C = 0;
    ((struct RaceMTRMeter__structor_0_arg0 *)arg0)->unk6C = 0;
    func_00360D20(arg0);
}
