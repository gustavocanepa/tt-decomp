#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 RaceDisplayObjectBase__structor_1(s32, s32);                /* extern */
s32 func_004A45D0(void *);                      /* extern */

extern char D_005A9D40[];
struct mRaceData__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void mRaceData__structor_1(void *arg0, s32 arg1) {
    ((struct mRaceData__structor_1_arg0 *)arg0)->unk4 = (s32)D_005A9D40;
    RaceDisplayObjectBase__structor_1(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_004A45D0(arg0);
    }
}
