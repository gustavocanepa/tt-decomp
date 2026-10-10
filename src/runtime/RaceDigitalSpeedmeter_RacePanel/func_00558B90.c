#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558B90_arg0 {
    char pad0[0x36C];
    s32 unk36C;
};

void func_00558B90(struct func_00558B90_arg0 *arg0, s32 arg1) {
    arg0->unk36C = (s32) ((arg0->unk36C & ~0xFF) | (arg1 & 0xFF));
}
