#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056E310_arg1 {
    char pad0[0x14];
    s32 unk14;
};

void func_0056E310(s32 arg0, struct func_0056E310_arg1 *arg1, s32 arg2) {
    arg1->unk14 = arg2;
}
