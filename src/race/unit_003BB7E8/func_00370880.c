#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00370880_arg0 {
    char pad0[0x40];
    s32 unk40;
};

void func_00370880(struct func_00370880_arg0 *arg0) {
    s32 i;
    for (i = 15; i >= 0; i--) {
        ((s32 *)arg0)[i] = 0x157529FF;
    }
    arg0->unk40 = 0x157529FF;
}
