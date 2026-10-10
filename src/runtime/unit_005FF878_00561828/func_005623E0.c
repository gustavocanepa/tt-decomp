#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005623E0_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_005623E0(struct func_005623E0_arg0 *arg0) {
    return arg0->unk14;
}
