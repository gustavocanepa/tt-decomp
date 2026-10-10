#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00108C80(void *, s32);                         /* extern */
s32 RaceBasicWithRaceDisplay__structor_1(void *, s32);             /* extern */
s32 func_00377F78(void *, s32);             /* extern */
s32 RaceInput__structor_2(s32, s32);                /* extern */
s32 func_004CA4A0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D3B48[];
struct RaceSinglePlayer__structor_1_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void RaceSinglePlayer__structor_1(void *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x13A0C;
    ((struct RaceSinglePlayer__structor_1_arg0 *)arg0)->unk64 = (s32)D_005D3B48;
    func_00108C80(arg0, temp_s1);
    RaceInput__structor_2(temp_s1, 2);
    func_004CA4A0(arg0 + 0x139CC, 2);
    func_00377F78(arg0 + 0x139C0, 2);
    RaceBasicWithRaceDisplay__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
