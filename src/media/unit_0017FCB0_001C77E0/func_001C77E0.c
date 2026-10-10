#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104868(s32, s32);                /* extern */
s32 func_001DF5B8(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005AF5D8[];
struct func_001C77E0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_001C77E0(void *arg0, s32 arg1) {
    ((struct func_001C77E0_arg0 *)arg0)->unk4 = (s32)D_005AF5D8;
    func_00104868(arg0 + 0x1D58, 2);
    func_001DF5B8(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x1DA8, 4);
    }
}
