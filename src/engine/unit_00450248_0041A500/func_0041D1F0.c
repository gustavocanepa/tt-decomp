#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041D1F0_arg0 {
    char pad0[0x8C];
    s32 unk8C;
    char pad90[0x55C];
    s32 unk5EC;
};

void func_0041D1F0(struct func_0041D1F0_arg0 *arg0, s32 arg1) {
    arg0->unk5EC = arg1;
    arg0->unk8C = (s32) (arg1 != 0);
}
