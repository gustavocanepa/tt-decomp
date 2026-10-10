/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0033D258();                            /* extern */
s32 RaceInput__setRunMode(void *, s32);                 /* extern */

struct RaceFreeRun__virtual_18_arg0 {
    char pad0[0xD8C];
    s32 unkD8C;
};

void RaceSolitaire__notifyChangeSpecMode(void *arg0) {
    func_0033D258();
    RaceInput__setRunMode(arg0 + 0xE54C, ((struct RaceFreeRun__virtual_18_arg0 *)arg0)->unkD8C);
    RaceInput__setRunMode(arg0 + 0xE90C, ((struct RaceFreeRun__virtual_18_arg0 *)arg0)->unkD8C);
}
