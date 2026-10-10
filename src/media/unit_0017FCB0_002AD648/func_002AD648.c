#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002978B8(s32, s32);                /* extern */
s32 func_002A2628(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C5C48[];
struct func_002AD648_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002AD648(void *arg0, s32 arg1) {
    ((struct func_002AD648_arg0 *)arg0)->unk4 = (s32)D_005C5C48;
    func_002978B8(arg0 + 0xC, 2);
    func_002A2628(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x10, 4);
    }
}
