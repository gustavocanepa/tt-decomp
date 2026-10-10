#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055F5B0_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_0055F5B0(struct func_0055F5B0_arg0 *arg0, s32 arg1) {
    arg0->unk18 = arg1;
}
