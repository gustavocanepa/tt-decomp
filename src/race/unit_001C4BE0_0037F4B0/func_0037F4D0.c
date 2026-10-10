#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0037F4D0_arg1 {
    char pad0[0x60];
    s32 *unk60;
};

s32 func_0037F4D0(s32 arg0, struct func_0037F4D0_arg1 *arg1) {
    return *arg1->unk60 < 2;
}
