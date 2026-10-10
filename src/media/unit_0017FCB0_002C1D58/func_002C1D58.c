#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A75A8(s32, s32);                /* extern */
s32 func_002BC1D8(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005C7AD8[];
struct func_002C1D58_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002C1D58(void *arg0, s32 arg1) {
    ((struct func_002C1D58_arg0 *)arg0)->unk4 = (s32)D_005C7AD8;
    func_002A75A8(arg0 + 0x10, 2);
    func_002BC1D8(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x14, 4);
    }
}
