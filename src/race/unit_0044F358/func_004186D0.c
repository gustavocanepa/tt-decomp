#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186D0_arg0 {
    char pad0[0x354];
    s32 unk354;
};

s32 func_004186D0(struct func_004186D0_arg0 *arg0) {
    return arg0->unk354;
}
