#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560418_arg0 {
    char pad0[0x148];
    s32 unk148;
};

s32 func_00560418(struct func_00560418_arg0 *arg0) {
    return arg0->unk148;
}
