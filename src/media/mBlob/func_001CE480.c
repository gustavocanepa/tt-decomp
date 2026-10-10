#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0022C048(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_004A45D0(s32);                         /* extern */

extern char D_005AFAF0[];
struct func_001CE480_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_001CE480(struct func_001CE480_arg0 *arg0, s32 arg1) {
    s32 temp_a0;

    arg0->unk4 = (s32)D_005AFAF0;
    if (arg0->unkC != 0) {
        temp_a0 = arg0->unk8;
        arg0->unk8 = 0;
        func_004A45D0(temp_a0);
    }
    func_0022C048(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x24, 4);
    }
}
