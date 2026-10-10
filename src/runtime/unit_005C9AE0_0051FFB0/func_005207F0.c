#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005207F0_arg0 {
    char pad0[0x48];
    u16 unk48;
};

s32 func_005207F0(struct func_005207F0_arg0 *arg0) {
    return ((u16) arg0->unk48 >> 2) & 1;
}
