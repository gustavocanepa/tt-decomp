#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003EAF28_arg0 {
    char pad0[0x188];
    s32 unk188;
};

s32 func_003EAF28(struct func_003EAF28_arg0 *arg0) {
    return arg0->unk188;
}
