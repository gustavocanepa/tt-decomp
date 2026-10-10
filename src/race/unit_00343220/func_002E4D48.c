#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E4D48_arg0 {
    char pad0[0x646];
    u8 unk646;
};

s32 func_002E4D48(struct func_002E4D48_arg0 *arg0) {
    return arg0->unk646 == 1;
}
