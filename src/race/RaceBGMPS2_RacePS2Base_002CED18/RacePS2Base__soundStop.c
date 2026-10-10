/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceBase__soundStop();                            /* extern */
s32 RaceCourseSound__playStop(s32, s32);                /* extern */
s32 func_0039D1B0(s32);                         /* extern */

void RacePS2Base__soundStop(s32 arg0) {
    RaceBase__soundStop();
    RaceCourseSound__playStop(arg0 + 0xE220, 0);
    func_0039D1B0(arg0 + 0x36C0);
}
