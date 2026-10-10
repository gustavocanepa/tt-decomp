#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00364228_arg0 {
    char pad0[0x38];
    s32 unk38;
};

void func_00364228(struct func_00364228_arg0 *arg0, s32 arg1) {
    arg0->unk38 = (s32) ((arg0->unk38 & ~0xFF) | (arg1 & 0xFF));
}
