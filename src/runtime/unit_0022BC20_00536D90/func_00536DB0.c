#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536DB0_arg0 {
    char pad0[0x11C];
    s32 unk11C;
};

s32 func_00536DB0(struct func_00536DB0_arg0 *arg0) {
    return ((s32) arg0->unk11C >> 2) & 1;
}
