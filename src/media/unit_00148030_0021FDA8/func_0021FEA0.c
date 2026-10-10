#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0021FEA0_arg0 {
    char pad0[0x60];
    f32 unk60;
};

void func_0021FEA0(struct func_0021FEA0_arg0 *arg0, f32 fparg0) {
    arg0->unk60 = (f32) (0x1.6800000000000p+8f / (fparg0 * 0x1.e000000000000p+5f));
}
