#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005423D0_arg0 {
    char pad0[0x340];
    s32 unk340;
};

void func_005423D0(struct func_005423D0_arg0 *arg0, s32 arg1) {
    arg0->unk340 = arg1;
}
