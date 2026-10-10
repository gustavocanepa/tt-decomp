#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629A0_arg0 {
    char pad0[0x111C];
    s32 unk111C;
};

s32 func_005629A0(struct func_005629A0_arg0 *arg0) {
    return arg0->unk111C;
}
