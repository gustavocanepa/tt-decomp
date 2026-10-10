#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559DF0_arg0 {
    char pad0[0x5458];
    f32 unk5458;
};

void func_00559DF0(struct func_00559DF0_arg0 *arg0, f32 fparg0) {
    arg0->unk5458 = fparg0;
}
