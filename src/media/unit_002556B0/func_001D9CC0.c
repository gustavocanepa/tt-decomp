#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001D9CC0_arg0 {
    char pad0[0x48];
    s32 unk48;
};

s32 func_001D9CC0(struct func_001D9CC0_arg0 *arg0) {
    return arg0->unk48 & 1;
}
