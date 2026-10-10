#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A75A8(void *, s32);             /* extern */
s32 func_002BC0E0(s32, s32);                /* extern */
s32 func_002BC618(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C54E8[];
struct func_002A6878_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002A6878(void *arg0, s32 arg1) {
    ((struct func_002A6878_arg0 *)arg0)->unk4 = (s32)D_005C54E8;
    func_002BC0E0(arg0 + 0x18, 2);
    func_002A75A8(arg0 + 0x14, 2);
    func_002BC618(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x1C, 4);
    }
}
