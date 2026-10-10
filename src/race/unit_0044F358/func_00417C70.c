#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C70_arg0 {
    char pad0[0x114];
    f32 unk114;
};

void func_00417C70(struct func_00417C70_arg0 *arg0, f32 fparg0) {
    arg0->unk114 = fparg0;
}
