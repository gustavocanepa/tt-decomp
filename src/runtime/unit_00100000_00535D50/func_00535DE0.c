#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00535DE0_arg0 {
    char pad0[0x24];
    s32 unk24;
};

s32 func_00535DE0(struct func_00535DE0_arg0 *arg0) {
    return arg0->unk24 & 0xF;
}
