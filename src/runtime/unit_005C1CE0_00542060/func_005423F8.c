#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005423F8_arg0 {
    char pad0[0x368];
    s32 unk368;
};

void func_005423F8(struct func_005423F8_arg0 *arg0, s32 arg1) {
    arg0->unk368 = (s32) ((arg0->unk368 & ~1) | (arg1 != 0));
}
