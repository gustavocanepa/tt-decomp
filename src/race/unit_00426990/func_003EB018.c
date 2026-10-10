#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003EB018_arg0 {
    char pad0[0x18C];
    s32 unk18C;
};

s32 func_003EB018(struct func_003EB018_arg0 *arg0) {
    return arg0->unk18C;
}
