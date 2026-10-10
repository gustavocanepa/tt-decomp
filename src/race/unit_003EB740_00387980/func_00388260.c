#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002CF8D0();                                /* extern */
s32 RacePause__structor_0(void *);                      /* extern */
s32 func_00377730(void *, void *);              /* extern */
s32 func_0037AA40();                            /* extern */
s32 RaceTrainingBase__setGuideMode(void *, s32);             /* extern */

extern char D_005D5308[];
struct func_00388260_temp_s0 {
    char pad0[0x28];
    s32 unk28;
};

struct func_00388260_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0xDC4];
    s32 unkE2C;
};

void func_00388260(void *arg0) {
    struct func_00388260_temp_s0 *temp_s0;

    func_0037AA40();
    temp_s0 = arg0 + 0x13C00;
    ((struct func_00388260_arg0 *)arg0)->unk64 = (s32)D_005D5308;
    RacePause__structor_0(temp_s0);
    if (func_002CF8D0() == 0) {
        temp_s0->unk28 = 1;
        func_00377730(temp_s0, arg0 + 0xE418);
    }
    RaceTrainingBase__setGuideMode(arg0, 0);
    ((struct func_00388260_arg0 *)arg0)->unkE2C = 3;
}
