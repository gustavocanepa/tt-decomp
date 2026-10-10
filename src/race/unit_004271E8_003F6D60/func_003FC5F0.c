#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003FC5F0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_003FC5F0(struct func_003FC5F0_arg0 *arg0) {
    return arg0->unk4 == 2;
}
