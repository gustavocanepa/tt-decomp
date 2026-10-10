#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_0040BBD0(s32);                         /* extern */

extern char D_005D25A0[];
struct RaceGTmodeInformation__structor_0_arg0 {
    char pad0[0x120];
    s32 unk120;
    char pad124[0x10];
    s32 unk134;
    char pad138[0x190];
    s32 unk2C8;
};

s32 RaceGTmodeInformation__structor_0(void *arg0) {
    RaceInformation__structor_0();
    ((struct RaceGTmodeInformation__structor_0_arg0 *)arg0)->unk134 = (s32)D_005D25A0;
    func_0040BBD0(arg0 + 0x138);
    ((struct RaceGTmodeInformation__structor_0_arg0 *)arg0)->unk120 = 6;
    ((struct RaceGTmodeInformation__structor_0_arg0 *)arg0)->unk2C8 = 0;
}
