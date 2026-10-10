#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417EC0_arg0 {
    char pad0[0x338];
    s32 unk338;
};

void func_00417EC0(struct func_00417EC0_arg0 *arg0, s32 arg1) {
    arg0->unk338 = arg1;
}
