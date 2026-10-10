#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00215248();                            /* extern */
s32 func_00234610(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */

extern char D_005B3EA8[];
struct func_002150E0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_002150E0(struct func_002150E0_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005B3EA8;
    func_00215248();
    func_00234610(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x20, 4);
    }
}
