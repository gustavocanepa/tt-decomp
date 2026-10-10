#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002CD4A0_arg0 {
    char pad0[0x280];
    s32 unk280;
};

s32 func_002CD4A0(struct func_002CD4A0_arg0 *arg0) {
    return arg0->unk280;
}
