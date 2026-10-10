#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002BDA70(void *, s32, s32);        /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005A5A70[];
struct func_00518EE0_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};
struct func_00518EE0_temp_v1 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_00518EE0(struct func_00518EE0_arg0 *arg0, s32 arg1) {
    s32 temp_v0;
    struct func_00518EE0_temp_v1 *temp_v1;

    arg0->unk8 = (s32)D_005A5A70;
    temp_v1 = arg0->unk0 - 0x10;
    temp_v0 = temp_v1->unk8 - 1;
    temp_v1->unk8 = temp_v0;
    if (temp_v0 == 0) {
        func_002BDA70(temp_v1, temp_v1->unk4 + 0x10, 4);
    }
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
