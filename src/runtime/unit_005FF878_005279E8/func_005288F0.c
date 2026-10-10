#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005288F0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
};

void func_005288F0(struct func_005288F0_arg0 *arg0, s32 arg1) {
    arg0->unk1C = arg1;
}
