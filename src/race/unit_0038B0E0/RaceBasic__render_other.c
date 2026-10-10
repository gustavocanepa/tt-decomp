#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002D27B0(void *, s32);                 /* extern */
s32 RaceMonitor__isFullScreenMode(s32);                             /* extern */

struct RaceNetBattle__virtual_107_arg0 {
    char pad0[0xE4E4];
    s32 unkE4E4;
};

s32 RaceBasic__render_other(struct RaceNetBattle__virtual_107_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unkE4E4;
    if ((temp_v0 == 0) || (RaceMonitor__isFullScreenMode(temp_v0) == 0)) {
        func_002D27B0(arg0, arg1);
    }
}
