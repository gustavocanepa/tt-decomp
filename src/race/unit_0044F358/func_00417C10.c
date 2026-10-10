#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C10_arg0 {
    char pad0[0xFC];
    f32 unkFC;
};

void func_00417C10(struct func_00417C10_arg0 *arg0, f32 fparg0) {
    arg0->unkFC = fparg0;
}
