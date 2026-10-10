#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186C0_arg0 {
    char pad0[0x350];
    s32 unk350;
};

s32 func_004186C0(struct func_004186C0_arg0 *arg0) {
    return arg0->unk350;
}
