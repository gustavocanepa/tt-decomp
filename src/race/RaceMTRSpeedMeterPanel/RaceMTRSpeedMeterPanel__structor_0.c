#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003620B0(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D08D0[];
struct RaceMTRSpeedMeterPanel__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    char pad20[0x4];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

void RaceMTRSpeedMeterPanel__structor_0(struct RaceMTRSpeedMeterPanel__structor_0_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk14 = (s32)D_005D08D0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    func_003620B0(arg0);
}
