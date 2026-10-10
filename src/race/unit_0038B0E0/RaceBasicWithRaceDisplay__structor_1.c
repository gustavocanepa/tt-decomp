#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0033CE00(void *, s32);             /* extern */
s32 func_0034F970(s32, s32);                /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005CC5D0[];
struct RaceBasicWithRaceDisplay__structor_1_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void RaceBasicWithRaceDisplay__structor_1(void *arg0, s32 arg1) {
    ((struct RaceBasicWithRaceDisplay__structor_1_arg0 *)arg0)->unk64 = (s32)D_005CC5D0;
    func_0034F970(arg0 + 0xE500, 2);
    func_0033CE00(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
