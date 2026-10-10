#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00248298_arg0 {
    char pad0[0x1A4];
    s32 unk1A4;
};

s32 func_00248298(struct func_00248298_arg0 *arg0) {
    return arg0->unk1A4 == 4;
}
