#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426FA0_arg0 {
    char pad0[0x43C];
    s32 unk43C;
};

s32 func_00426FA0(struct func_00426FA0_arg0 *arg0) {
    return arg0->unk43C;
}
