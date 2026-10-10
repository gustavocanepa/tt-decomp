#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554538_arg0 {
    char pad0[0xE2C];
    s32 unkE2C;
};

void func_00554538(struct func_00554538_arg0 *arg0, s32 arg1) {
    arg0->unkE2C = arg1;
}
