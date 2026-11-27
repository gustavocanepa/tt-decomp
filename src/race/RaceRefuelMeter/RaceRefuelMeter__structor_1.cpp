#include "types.h"

extern void *D_005D0CC8;
extern "C" void *RaceDisplayObjectBase__structor_0(void *);

struct RaceRefuelMeter__structor_1_arg0 {
    char pad0[0x14];
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

extern "C" void *RaceRefuelMeter__structor_1(struct RaceRefuelMeter__structor_1_arg0 *arg0) {
    void *r0 = RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk18 = 0x0;
    arg0->unk14 = &D_005D0CC8;
    arg0->unk1C = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk24 = 0x0;
    return r0;
}
