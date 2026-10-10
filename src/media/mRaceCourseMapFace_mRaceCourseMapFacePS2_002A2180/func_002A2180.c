#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A2588(s32, s32);                /* extern */
s32 func_002A75A8(void *, s32);             /* extern */
s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C50E8[];
struct func_002A2180_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002A2180(void *arg0, s32 arg1) {
    ((struct func_002A2180_arg0 *)arg0)->unk4 = (s32)D_005C50E8;
    func_002A2588(arg0 + 0x14, 2);
    func_002A75A8(arg0 + 0x10, 2);
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x18, 4);
    }
}
