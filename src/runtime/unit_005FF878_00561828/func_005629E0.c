#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005629E0_arg0 {
    char pad0[0x112C];
    s32 unk112C;
};

s32 func_005629E0(struct func_005629E0_arg0 *arg0) {
    return arg0->unk112C;
}
