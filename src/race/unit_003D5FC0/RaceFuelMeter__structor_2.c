#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceEventDisplay__structor_2(s32, s32);                /* extern */
s32 func_0038E308(void *, s32);             /* extern */
s32 RaceMonitor__unload();                            /* extern */
s32 func_0050E1A8(s32);                         /* extern */

extern char D_005C9130[];
extern char D_005D0D20[];
extern char D_005D1128[];
struct RaceFuelMeter__structor_2_temp_v1 {
    char pad0[0x14];
    s32 unk14;
};
struct RaceFuelMeter__structor_2_temp_v1_2 {
    char pad0[0x14];
    s32 unk14;
};
struct RaceFuelMeter__structor_2_temp_v1_3 {
    char pad0[0x14];
    s32 unk14;
};

void RaceFuelMeter__structor_2(s32 arg0, s32 arg1) {
    struct RaceFuelMeter__structor_2_temp_v1 *temp_v1;
    struct RaceFuelMeter__structor_2_temp_v1_2 *temp_v1_2;
    struct RaceFuelMeter__structor_2_temp_v1_3 *temp_v1_3;

    RaceMonitor__unload();
    RaceEventDisplay__structor_2(arg0 + 0x358, 2);
    temp_v1 = arg0 + 0x328;
    temp_v1->unk14 = (s32)D_005D1128;
    func_0038E308(temp_v1, 0);
    temp_v1_2 = arg0 + 0x300;
    temp_v1_2->unk14 = (s32)D_005D0D20;
    func_0038E308(temp_v1_2, 0);
    temp_v1_3 = arg0 + 0x298;
    temp_v1_3->unk14 = (s32)D_005C9130;
    func_0038E308(temp_v1_3, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
