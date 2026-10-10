#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003EB080_arg0 {
    char pad0[0x190];
    s32 unk190;
};

s32 func_003EB080(struct func_003EB080_arg0 *arg0) {
    return arg0->unk190;
}
