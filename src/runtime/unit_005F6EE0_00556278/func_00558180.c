#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00558180_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

s32 func_00558180(struct func_00558180_arg0 *arg0) {
    return arg0->unk6C;
}
