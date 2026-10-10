/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0040CE20(void *, s32);                 /* extern */

struct RaceMachineTestInformation__virtual_12_temp_s2 {
    char pad0[0x190];
    s32 unk190;
};

struct RaceMachineTestInformation__virtual_12_arg1 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x1164];
    s16 unk117C;
};

void RaceMachineTestInformation__updateEntryCar(s32 arg0, void *arg1) {
    s32 temp_s0;
    struct RaceMachineTestInformation__virtual_12_temp_s2 *temp_s2;

    temp_s2 = arg1 + 0xFD8;
    temp_s0 = ((struct RaceMachineTestInformation__virtual_12_arg1 *)arg1)->unk14;
    func_0040CE20(temp_s2, arg0 + 0x138);
    temp_s2->unk190 = (s32) (temp_s0 + 0x100);
    ((struct RaceMachineTestInformation__virtual_12_arg1 *)arg1)->unk117C = 0;
}
