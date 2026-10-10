#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001FC7C0(void *, s32);             /* extern */
s32 func_002BDA70(void *, s32, s32);        /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005AFBC8[];
struct func_00528A28_arg0 {
    s32 unk0;
    s32 unk4;
};
struct func_00528A28_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_00528A28(struct func_00528A28_arg0 *arg0, s32 arg1) {
    s32 temp_v0;
    struct func_00528A28_temp_v1 *temp_v1;

    arg0->unk0 = (s32)D_005AFBC8;
    temp_v1 = arg0->unk4 - 0x10;
    temp_v0 = temp_v1->unk8 - 1;
    temp_v1->unk8 = temp_v0;
    if (temp_v0 == 0) {
        func_002BDA70(temp_v1, temp_v1->unk4 + 0x10, 4);
    }
    func_001FC7C0(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
