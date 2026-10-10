#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186B0_arg0 {
    char pad0[0x34C];
    s32 unk34C;
};

s32 func_004186B0(struct func_004186B0_arg0 *arg0) {
    return arg0->unk34C;
}
