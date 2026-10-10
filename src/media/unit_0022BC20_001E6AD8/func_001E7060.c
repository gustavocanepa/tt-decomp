#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E7060_arg0 {
    char pad0[0xF0];
    s32 unkF0;
};

void func_001E7060(struct func_001E7060_arg0 *arg0, s32 arg1) {
    arg0->unkF0 = (s32) ((arg0->unkF0 & ~1) | (arg1 != 0));
}
