#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052D4F0_arg0 {
    char pad0[0xE4];
    s32 unkE4;
};

void func_0052D4F0(struct func_0052D4F0_arg0 *arg0, s32 arg1) {
    arg0->unkE4 = arg1;
}
