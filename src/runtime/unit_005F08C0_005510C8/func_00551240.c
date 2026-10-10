#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551240_arg0 {
    char pad0[0xCFF0];
    f32 unkCFF0;
};

void func_00551240(struct func_00551240_arg0 *arg0, f32 fparg0) {
    arg0->unkCFF0 = fparg0;
}
