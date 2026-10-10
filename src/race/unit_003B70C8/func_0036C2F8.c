#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0036C2F8_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_0036C2F8(struct func_0036C2F8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk10 = arg1;
    arg0->unk14 = arg2;
}
