#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0028FA68(void *, s32, s32, s32); /* extern */
s32 func_003FCC50(s32);                         /* extern */

extern char D_005FAB10[];
void func_004013E0(s32 arg0) {
    s8 sp[0x10];
    func_003FCC50(arg0 + 0x680);
    func_0028FA68(sp, (s32)D_005FAB10, 0, 0);
}
