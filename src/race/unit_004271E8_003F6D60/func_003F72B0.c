#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003F72B0_arg0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_003F72B0(struct func_003F72B0_arg0 *arg0) {
    return arg0->unk18;
}
