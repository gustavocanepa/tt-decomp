#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00284F90_arg0 {
    char pad0[0x70];
    f32 unk70;
};

void func_00284F90(struct func_00284F90_arg0 *arg0, f32 fparg0) {
    arg0->unk70 = (f32) (0x1.0000000000000p+0f / fparg0);
}
