#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceMessageDisplay__structor_1(void *);                      /* extern */
s32 RaceEventDisplay__structor_1(void *);                      /* extern */
s32 func_0035E910(s32);                         /* extern */
s32 func_003630E0(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D0810[];
struct RaceTooltipDisplay__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void RaceTooltipDisplay__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceTooltipDisplay__structor_0_arg0 *)arg0)->unk14 = (s32)D_005D0810;
    func_0035E910(arg0 + 0x20);
    RaceMessageDisplay__structor_1(arg0 + 0x3C);
    RaceEventDisplay__structor_1(arg0 + 0x18C);
    func_003630E0(arg0);
}
