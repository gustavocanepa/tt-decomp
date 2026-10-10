#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00544230_arg0 {
    char pad0[0x878];
    s32 unk878;
};

void func_00544230(struct func_00544230_arg0 *arg0, s32 arg1) {
    arg0->unk878 = arg1;
}
