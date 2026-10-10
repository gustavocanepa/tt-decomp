#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_00543740(s32, s32);                /* extern */

extern char D_005BDF40[];
struct func_0026CF40_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0026CF40(void *arg0, s32 arg1) {
    ((struct func_0026CF40_arg0 *)arg0)->unk4 = (s32)D_005BDF40;
    func_00543740(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x150, 4);
    }
}
