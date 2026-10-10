#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001CE6D8(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_004A45D0(s32);                         /* extern */

extern char D_005B3FC0[];
struct func_00215B98_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_00215B98(struct func_00215B98_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005B3FC0;
    if (arg0->unkC != 0) {
        func_004A45D0(arg0->unk8);
    }
    func_001CE6D8(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x10, 4);
    }
}
