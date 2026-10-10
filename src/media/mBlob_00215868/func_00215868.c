#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001C1438(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);    /* extern */
s32 func_004A45D0(s32);                         /* extern */

extern char D_005B3F30[];
struct func_00215868_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xC];
    s32 unk14;
    char pad18[0x8];
    s32 unk20;
};

void func_00215868(struct func_00215868_arg0 *arg0, s32 arg1) {
    s32 temp_a0;

    arg0->unk4 = (s32)D_005B3F30;
    if (arg0->unk20 != 0) {
        temp_a0 = arg0->unk14;
        arg0->unk14 = 0;
        func_004A45D0(temp_a0);
    }
    func_001C1438(arg0, 0);
    if (arg1 & 1) {
        func_002BDA70(arg0, 0x24, 4);
    }
}
