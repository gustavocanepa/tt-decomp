#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_0037AFA8(void *);                      /* extern */

extern char D_005CDFC0[];
struct func_00554838_arg0 {
    char pad0[0x134];
    s32 unk134;
    char pad138[0x338];
    s32 unk470;
};

void func_00554838(void *arg0) {
    RaceInformation__structor_0();
    ((struct func_00554838_arg0 *)arg0)->unk134 = (s32)D_005CDFC0;
    func_0037AFA8(arg0 + 0x138);
    func_0037AFA8(arg0 + 0x2D0);
    ((struct func_00554838_arg0 *)arg0)->unk470 = 0;
}
