#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033E8E0();                            /* extern */
s32 func_0033E2F0(void *, s32);                 /* extern */
s32 func_00358698(s32);                         /* extern */

extern char D_005CCFE0[];
struct RaceSplitBattle__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void RaceSplitBattle__structor_0(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x3DD00;
    func_0033E8E0();
    ((struct RaceSplitBattle__structor_0_arg0 *)arg0)->unk64 = (s32)D_005CCFE0;
    func_00358698(temp_s1);
    func_0033E2F0(arg0, temp_s1);
}
