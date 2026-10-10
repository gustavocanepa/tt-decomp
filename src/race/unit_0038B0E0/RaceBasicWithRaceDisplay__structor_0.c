#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceBasic__structor_0();                            /* extern */
s32 func_0033E2F0(void *, s32);                 /* extern */
s32 func_0034F6E8(s32);                         /* extern */

extern char D_005CC5D0[];
struct RaceBasicWithRaceDisplay__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void RaceBasicWithRaceDisplay__structor_0(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0xE500;
    RaceBasic__structor_0();
    ((struct RaceBasicWithRaceDisplay__structor_0_arg0 *)arg0)->unk64 = (s32)D_005CC5D0;
    func_0034F6E8(temp_s1);
    func_0033E2F0(arg0, temp_s1);
}
