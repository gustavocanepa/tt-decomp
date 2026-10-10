#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005627F0_arg0 {
    char pad0[0x10B0];
    s32 unk10B0;
};

s32 func_005627F0(struct func_005627F0_arg0 *arg0) {
    return arg0->unk10B0;
}
