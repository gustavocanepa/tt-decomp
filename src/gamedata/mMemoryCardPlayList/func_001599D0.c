#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A7958(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_0050E1A8(s32);                         /* extern */

extern char D_005A7C10[];
struct func_001599D0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
};

void func_001599D0(struct func_001599D0_arg0 *arg0, s32 arg1) {
    arg0->unk4 = (s32)D_005A7C10;
    if (arg0->unk14 != 0) {
        func_0050E1A8(arg0->unk10);
    }
    func_002A7958(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x1C, 4);
    }
}
