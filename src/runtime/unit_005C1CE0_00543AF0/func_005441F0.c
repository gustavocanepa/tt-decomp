#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005441F0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

s32 func_005441F0(struct func_005441F0_arg0 *arg0) {
    return arg0->unk64;
}
