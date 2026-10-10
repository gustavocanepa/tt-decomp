#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005632C0_arg0 {
    char pad0[0x8C];
    s32 unk8C;
};

void func_005632C0(struct func_005632C0_arg0 *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}
