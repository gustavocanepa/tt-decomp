#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559DE0_arg0 {
    char pad0[0x5450];
    s32 unk5450;
};

s32 func_00559DE0(struct func_00559DE0_arg0 *arg0) {
    return arg0->unk5450;
}
