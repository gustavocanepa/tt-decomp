#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005562C0_arg0 {
    char pad0[0x40];
    s32 unk40;
};

void func_005562C0(struct func_005562C0_arg0 *arg0, s32 arg1) {
    arg0->unk40 = (s32) ((arg0->unk40 & 0xFFFFFF) | (arg1 << 0x18));
}
