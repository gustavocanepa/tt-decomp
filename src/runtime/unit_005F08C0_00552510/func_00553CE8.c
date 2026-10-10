#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553CE8_arg0 {
    char pad0[0x1D4];
    f32 unk1D4;
};

void func_00553CE8(struct func_00553CE8_arg0 *arg0, f32 fparg0) {
    arg0->unk1D4 = fparg0;
}
