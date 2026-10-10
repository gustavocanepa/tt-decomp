#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551128_arg0 {
    char pad0[0x1BC];
    f32 unk1BC;
};

void func_00551128(struct func_00551128_arg0 *arg0, f32 fparg0) {
    arg0->unk1BC = fparg0;
}
