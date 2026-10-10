#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00360570(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D0E28[];
struct RaceSideGravityMeter__structor_1_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    char pad1C[0xC];
    s32 unk28;
};

void RaceSideGravityMeter__structor_1(struct RaceSideGravityMeter__structor_1_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk14 = (s32)D_005D0E28;
    arg0->unk28 = 0x80E3B896;
    arg0->unk18 = 0;
    func_00360570(arg0);
}
