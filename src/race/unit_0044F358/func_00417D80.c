#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D80_arg0 {
    char pad0[0x158];
    f32 unk158;
};

void func_00417D80(struct func_00417D80_arg0 *arg0, f32 fparg0) {
    arg0->unk158 = fparg0;
}
