#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005231E0_arg0 {
    char pad0[0xC];
    f32 unkC;
};

void func_005231E0(struct func_005231E0_arg0 *arg0, f32 fparg0) {
    arg0->unkC = fparg0;
}
