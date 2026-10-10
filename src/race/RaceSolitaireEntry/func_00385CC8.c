#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_0037AFA8(s32);                         /* extern */

extern char D_005D4C80[];
struct func_00385CC8_arg0 {
    char pad0[0x134];
    s32 unk134;
};

void func_00385CC8(void *arg0) {
    RaceInformation__structor_0();
    ((struct func_00385CC8_arg0 *)arg0)->unk134 = (s32)D_005D4C80;
    func_0037AFA8(arg0 + 0x138);
}
