#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417CA0_arg0 {
    char pad0[0x120];
    f32 unk120;
};

void func_00417CA0(struct func_00417CA0_arg0 *arg0, f32 fparg0) {
    arg0->unk120 = fparg0;
}
