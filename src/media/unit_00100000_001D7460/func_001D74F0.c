#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D74F0_arg0 {
    char pad0[0x198];
    s32 unk198;
};

s32 func_001D74F0(struct func_001D74F0_arg0 *arg0) {
    return arg0->unk198;
}
