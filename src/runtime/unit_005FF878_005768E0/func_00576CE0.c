#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00576CE0_arg0 {
    char pad0[0x58];
    s32 unk58;
};

s32 func_00576CE0(struct func_00576CE0_arg0 *arg0) {
    return arg0->unk58;
}
