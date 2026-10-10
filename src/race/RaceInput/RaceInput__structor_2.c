#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002E87C0(void *, s32);             /* extern */
s32 func_00400A70(void *, s32);             /* extern */
s32 func_004CA1A8(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D7378[];
struct RaceInput__structor_2_arg0 {
    char pad0[0xD0];
    s32 unkD0;
};

void RaceInput__structor_2(void *arg0, s32 arg1) {
    ((struct RaceInput__structor_2_arg0 *)arg0)->unkD0 = (s32)D_005D7378;
    func_00400A70(arg0 + 0x1A0, 2);
    func_00400A70(arg0 + 0x170, 2);
    func_002E87C0(arg0 + 0xD4, 2);
    func_004CA1A8(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
