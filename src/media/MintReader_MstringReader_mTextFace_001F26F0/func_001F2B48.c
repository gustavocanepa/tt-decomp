#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001F2B48_arg0 {
    char pad0[0x13C];
    s32 unk13C;
    s32 unk140;
};

void func_001F2B48(struct func_001F2B48_arg0 *arg0) {
    arg0->unk13C = 1;
    arg0->unk140 = 1;
}
