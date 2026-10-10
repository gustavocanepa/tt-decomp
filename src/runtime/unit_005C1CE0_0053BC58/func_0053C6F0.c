#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C6F0_arg0 {
    char pad0[0x150];
    s32 unk150;
};

s32 func_0053C6F0(struct func_0053C6F0_arg0 *arg0) {
    return ((s32) arg0->unk150 >> 3) & 1;
}
