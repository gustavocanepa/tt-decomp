#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0034ADD0_arg0 {
    char pad0[0xB8];
    s32 unkB8;
};

void func_0034ADD0(struct func_0034ADD0_arg0 *arg0, s32 arg1) {
    arg0->unkB8 = arg1;
}
