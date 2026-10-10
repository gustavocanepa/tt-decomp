#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559940_arg0 {
    char pad0[0xC];
    s32 unkC;
};

s32 func_00559940(struct func_00559940_arg0 *arg0) {
    return arg0->unkC;
}
