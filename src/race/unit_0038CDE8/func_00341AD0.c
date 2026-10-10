#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00341AD0_arg0 {
    char pad0[0x8];
    s32 unk8;
};

s32 func_00341AD0(struct func_00341AD0_arg0 *arg0) {
    return arg0->unk8;
}
