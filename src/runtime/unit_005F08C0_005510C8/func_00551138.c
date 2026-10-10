#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00551138_arg0 {
    char pad0[0x34];
    s32 unk34;
};

void func_00551138(struct func_00551138_arg0 *arg0) {
    arg0->unk34 = (s32) (arg0->unk34 ^ 1);
}
