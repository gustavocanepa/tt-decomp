#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C30_arg0 {
    char pad0[0x104];
    f32 unk104;
};

void func_00417C30(struct func_00417C30_arg0 *arg0, f32 fparg0) {
    arg0->unk104 = fparg0;
}
