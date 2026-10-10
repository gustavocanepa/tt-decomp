#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417CD0_arg0 {
    char pad0[0x12C];
    f32 unk12C;
};

void func_00417CD0(struct func_00417CD0_arg0 *arg0, f32 fparg0) {
    arg0->unk12C = fparg0;
}
