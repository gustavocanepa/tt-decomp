#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005447D8_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_005447D8(struct func_005447D8_arg0 *arg0, s32 arg1) {
    arg0->unk34 = arg1;
}
