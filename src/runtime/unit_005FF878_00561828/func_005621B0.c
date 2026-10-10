#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005621B0_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

void func_005621B0(struct func_005621B0_arg0 *arg0, s32 arg1) {
    arg0->unk8210 = arg1;
}
