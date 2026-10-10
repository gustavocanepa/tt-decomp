#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559D60_arg0 {
    char pad0[0x4848];
    s32 unk4848;
};

s32 func_00559D60(struct func_00559D60_arg0 *arg0) {
    return arg0->unk4848;
}
