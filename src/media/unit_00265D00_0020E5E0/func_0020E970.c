#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020E970_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

void func_0020E970(struct func_0020E970_arg0 *arg0, s32 arg1) {
    arg0->unkAC = (s32) ((arg0->unkAC & ~0xF) | (arg1 & 0xF));
}
