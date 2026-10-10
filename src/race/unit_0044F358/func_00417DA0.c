#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417DA0_arg0 {
    char pad0[0x160];
    f32 unk160;
};

void func_00417DA0(struct func_00417DA0_arg0 *arg0, f32 fparg0) {
    arg0->unk160 = fparg0;
}
