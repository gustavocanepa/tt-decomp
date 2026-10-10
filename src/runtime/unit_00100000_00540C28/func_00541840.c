#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541840_arg0 {
    char pad0[0x130];
    s32 unk130;
};

void func_00541840(struct func_00541840_arg0 *arg0, s32 arg1) {
    arg0->unk130 = arg1;
}
