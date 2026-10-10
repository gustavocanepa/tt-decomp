#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053C3D0_arg0 {
    char pad0[0x180];
    f32 unk180;
};

void func_0053C3D0(struct func_0053C3D0_arg0 *arg0, f32 fparg0) {
    arg0->unk180 = fparg0;
}
