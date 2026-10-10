#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001F26E0_arg0 {
    char pad0[0x13C];
    s32 unk13C;
    s32 unk140;
};

void func_001F26E0(struct func_001F26E0_arg0 *arg0, s32 arg1) {
    arg0->unk13C = arg1;
    arg0->unk140 = 1;
}
