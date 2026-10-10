#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560DA0_arg0 {
    char pad0[0x40C];
    s32 unk40C;
};

s32 func_00560DA0(struct func_00560DA0_arg0 *arg0) {
    return arg0->unk40C;
}
