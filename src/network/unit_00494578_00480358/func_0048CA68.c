#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0048CA68_arg0 {
    char pad0[0x48];
    s32 unk48;
};

void func_0048CA68(struct func_0048CA68_arg0 *arg0, s32 arg1) {
    arg0->unk48 = arg1;
}
