#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005428A0_arg0 {
    char pad0[0x98];
    s32 unk98;
};

s32 func_005428A0(struct func_005428A0_arg0 *arg0) {
    return arg0->unk98;
}
