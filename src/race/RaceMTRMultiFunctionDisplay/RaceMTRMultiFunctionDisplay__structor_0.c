#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0035E910(s32);                         /* extern */
s32 func_00362760(void *);                      /* extern */
s32 RaceDisplayObjectBase__structor_0();                            /* extern */

extern char D_005D0870[];
struct RaceMTRMultiFunctionDisplay__structor_0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void RaceMTRMultiFunctionDisplay__structor_0(void *arg0) {
    RaceDisplayObjectBase__structor_0();
    ((struct RaceMTRMultiFunctionDisplay__structor_0_arg0 *)arg0)->unk14 = (s32)D_005D0870;
    func_0035E910(arg0 + 0x20);
    func_00362760(arg0);
}
