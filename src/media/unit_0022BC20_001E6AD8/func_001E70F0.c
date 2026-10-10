#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E70F0_arg0 {
    char pad0[0xF0];
    s32 unkF0;
};

s32 func_001E70F0(struct func_001E70F0_arg0 *arg0) {
    return ((s32) arg0->unkF0 >> 3) & 1;
}
