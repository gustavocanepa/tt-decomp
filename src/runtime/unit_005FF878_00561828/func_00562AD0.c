#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AD0_arg0 {
    char pad0[0x114C];
    s32 unk114C;
};

s32 func_00562AD0(struct func_00562AD0_arg0 *arg0) {
    return arg0->unk114C;
}
