#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560440_arg0 {
    char pad0[0x14C];
    s32 unk14C;
};

void func_00560440(struct func_00560440_arg0 *arg0, s32 arg1) {
    arg0->unk14C = arg1;
}
