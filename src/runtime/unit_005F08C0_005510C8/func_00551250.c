#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551250_arg0 {
    char pad0[0xCFF4];
    f32 unkCFF4;
};

void func_00551250(struct func_00551250_arg0 *arg0, f32 fparg0) {
    arg0->unkCFF4 = fparg0;
}
