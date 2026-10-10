#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C3C0_arg0 {
    char pad0[0x17C];
    s32 unk17C;
};

void func_0053C3C0(struct func_0053C3C0_arg0 *arg0, s32 arg1) {
    arg0->unk17C = arg1;
}
