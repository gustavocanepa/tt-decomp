#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D10_arg0 {
    char pad0[0x13C];
    f32 unk13C;
};

void func_00417D10(struct func_00417D10_arg0 *arg0, f32 fparg0) {
    arg0->unk13C = fparg0;
}
