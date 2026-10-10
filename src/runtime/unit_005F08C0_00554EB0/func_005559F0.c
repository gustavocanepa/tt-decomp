#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005559F0_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_005559F0(struct func_005559F0_arg0 *arg0, s32 arg1) {
    arg0->unk8 = arg1;
}
