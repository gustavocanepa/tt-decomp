#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001F2D70(s32);                             /* extern */

struct func_002868F0_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
};

void func_002868F0(struct func_002868F0_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    arg0->unk4C = arg1;
    temp_v0 = func_001F2D70(arg1);
    arg0->unk54 = 0;
    arg0->unk50 = temp_v0;
    arg0->unk58 = 0;
}
