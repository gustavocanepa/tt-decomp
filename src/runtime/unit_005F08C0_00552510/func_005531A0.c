#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005531A0_arg0 {
    char pad0[0x140];
    s32 unk140;
};

s32 func_005531A0(struct func_005531A0_arg0 *arg0) {
    return arg0->unk140;
}
