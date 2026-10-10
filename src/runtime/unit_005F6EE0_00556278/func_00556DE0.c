#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556DE0_arg0 {
    char pad0[0x44];
    f32 unk44;
};

void func_00556DE0(struct func_00556DE0_arg0 *arg0, f32 fparg0) {
    arg0->unk44 = fparg0;
}
