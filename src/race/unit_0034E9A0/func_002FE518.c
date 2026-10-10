#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FE518_arg0 {
    char pad0[0x7A1];
    u8 unk7A1;
};

s32 func_002FE518(struct func_002FE518_arg0 *arg0) {
    return arg0->unk7A1 & 1;
}
