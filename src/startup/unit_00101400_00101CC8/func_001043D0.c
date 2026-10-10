#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001043D0_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x38];
    s32 unk44;
};

s32 func_001043D0(struct func_001043D0_arg0 *arg0) {
    if (arg0->unk8 != 0) {
        arg0->unk44 = 1;
    }
    return (arg0->unk44 != 0) ? 0 : -1;
}
