#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005624E0_arg0 {
    char pad0[0x11EC];
    s32 unk11EC;
};

s32 func_005624E0(struct func_005624E0_arg0 *arg0) {
    return arg0->unk11EC;
}
