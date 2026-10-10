#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554728_arg0 {
    char pad0[0xE4D0];
    s32 unkE4D0;
};

void func_00554728(struct func_00554728_arg0 *arg0, s32 arg1) {
    arg0->unkE4D0 = arg1;
}
