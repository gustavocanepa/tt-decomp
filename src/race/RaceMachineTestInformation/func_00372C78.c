#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceInformation__structor_0();                            /* extern */
s32 func_0037AFA8(s32);                         /* extern */

extern char D_005D3428[];
struct func_00372C78_arg0 {
    char pad0[0x120];
    s32 unk120;
    char pad124[0x10];
    s32 unk134;
};

s32 func_00372C78(void *arg0) {
    RaceInformation__structor_0();
    ((struct func_00372C78_arg0 *)arg0)->unk134 = (s32)D_005D3428;
    func_0037AFA8(arg0 + 0x138);
    ((struct func_00372C78_arg0 *)arg0)->unk120 = 2;
}
