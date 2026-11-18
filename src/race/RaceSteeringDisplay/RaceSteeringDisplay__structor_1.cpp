#include "types.h"

extern void *D_005D1180;
extern "C" void RaceDisplayObjectBase__structor_0(void *);

struct RaceSteeringDisplay__structor_1_arg0 {
    char pad0[0x14];
    void *unk14;
    void *unk18;
    void *unk1C;
    float unk20;
};

extern "C" void RaceSteeringDisplay__structor_1(struct RaceSteeringDisplay__structor_1_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk14 = &D_005D1180;
    arg0->unk20 = *(float *)((char *)"GTMODE_MACHINE_TEST_MAX_SPEED" + 0x14c0);
    arg0->unk1C = 0x0;
    arg0->unk18 = 0x0;
}
