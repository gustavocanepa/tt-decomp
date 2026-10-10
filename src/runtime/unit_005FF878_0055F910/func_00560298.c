#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560298_arg0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

void func_00560298(struct func_00560298_arg0 *arg0, s32 arg1) {
    arg0->unk1D0 = arg1;
}
