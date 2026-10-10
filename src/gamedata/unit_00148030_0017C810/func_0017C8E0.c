#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0017C8E0_arg0 {
    char pad0[0x108];
    s32 unk108;
};

s32 func_0017C8E0(struct func_0017C8E0_arg0 *arg0) {
    return *(s32 *)(0x579C60 + (arg0->unk108 * 4));
}
