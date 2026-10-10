#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E9140_arg0 {
    char pad0[0x31];
    u8 unk31;
};

s32 func_002E9140(struct func_002E9140_arg0 *arg0) {
    return *(s32 *)(0x582D50 + (arg0->unk31 * 4));
}
