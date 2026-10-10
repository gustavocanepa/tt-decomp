#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D40_arg0 {
    char pad0[0x148];
    f32 unk148;
};

void func_00417D40(struct func_00417D40_arg0 *arg0, f32 fparg0) {
    arg0->unk148 = fparg0;
}
