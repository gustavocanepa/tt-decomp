#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541858_arg0 {
    char pad0[0x14C];
    s32 unk14C;
};

s32 func_00541858(struct func_00541858_arg0 *arg0) {
    return arg0->unk14C;
}
