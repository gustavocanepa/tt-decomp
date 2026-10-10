#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553CF8_arg0 {
    char pad0[0x1D0];
    f32 unk1D0;
};

void func_00553CF8(struct func_00553CF8_arg0 *arg0, f32 fparg0) {
    arg0->unk1D0 = fparg0;
}
