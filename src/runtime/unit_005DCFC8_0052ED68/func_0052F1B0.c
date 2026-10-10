#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052F1B0_arg0 {
    char pad0[0xD8];
    f32 unkD8;
};

void func_0052F1B0(struct func_0052F1B0_arg0 *arg0, f32 fparg0) {
    arg0->unkD8 = fparg0;
}
