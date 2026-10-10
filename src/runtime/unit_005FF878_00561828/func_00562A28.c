#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562A28_arg0 {
    char pad0[0x113C];
    s32 unk113C;
};

void func_00562A28(struct func_00562A28_arg0 *arg0, s32 arg1) {
    arg0->unk113C = arg1;
}
