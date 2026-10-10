#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052F2E8_arg0 {
    char pad0[0x160];
    s32 unk160;
};

void func_0052F2E8(struct func_0052F2E8_arg0 *arg0, s32 arg1) {
    arg0->unk160 = arg1;
}
