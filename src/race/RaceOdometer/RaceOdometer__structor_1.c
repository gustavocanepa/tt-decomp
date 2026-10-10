#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00359578(void *, s32);             /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D13F8[];
struct RaceOdometer__structor_1_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void RaceOdometer__structor_1(struct RaceOdometer__structor_1_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0();
    arg0->unk18 = 0;
    arg0->unk14 = (s32)D_005D13F8;
    func_00359578(arg0, 6);
}
