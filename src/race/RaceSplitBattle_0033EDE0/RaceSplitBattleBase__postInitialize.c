/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033AE38();                            /* extern */
s32 CarIconMaker__structor_1(s32, s32);                    /* extern */
s32 func_0037E020(void *, s32);                 /* extern */

struct RaceSplitBattle__virtual_39_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void RaceSplitBattleBase__postInitialize(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x32AD0;
    func_0033AE38();
    CarIconMaker__structor_1(temp_s1, ((struct RaceSplitBattle__virtual_39_arg0 *)arg0)->unk6C);
    func_0037E020(arg0 + 0x32B00, temp_s1);
}
