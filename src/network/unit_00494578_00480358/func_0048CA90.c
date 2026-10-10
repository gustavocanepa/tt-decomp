#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CA90_arg0 {
    char pad0[0x54];
    s32 unk54;
};

void func_0048CA90(struct func_0048CA90_arg0 *arg0, s32 arg1) {
    arg0->unk54 = arg1;
}
