#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005524A0(s32, s32);                    /* extern */

struct func_002E7B48_arg0 {
    s32 unk0;
    s32 unk4;
    s8 unk8;
    char pad9[0x3];
    s32 unkC;
    char pad10[0x38];
    s32 unk48;
    s32 unk4C;
};

void func_002E7B48(struct func_002E7B48_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_005524A0(arg1, 8);
    arg0->unk0 = temp_v0;
    arg0->unk4C = arg2;
    arg0->unk48 = arg1;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk4 = temp_v0;
}
