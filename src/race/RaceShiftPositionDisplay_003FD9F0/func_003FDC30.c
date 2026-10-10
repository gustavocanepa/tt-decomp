#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FDC30_arg0 {
    char pad0[0x1148];
    s32 unk1148;
};

void func_003FDC30(struct func_003FDC30_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg0->unk1148 & ~arg1;
    arg0->unk1148 = (s32) ((arg2 != 0) ? (temp_v0 | arg1) : temp_v0);
}
