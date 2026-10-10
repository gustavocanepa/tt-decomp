#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556240_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_00556240(struct func_00556240_arg0 *arg0, s32 arg1) {
    arg0->unk34 = (s32) ((arg0->unk34 & 0xFFFFFF) | (arg1 << 0x18));
}
