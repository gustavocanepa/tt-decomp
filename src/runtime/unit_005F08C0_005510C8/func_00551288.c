#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00551288_arg0 {
    char pad0[0xD000];
    f32 unkD000;
};

void func_00551288(struct func_00551288_arg0 *arg0, f32 fparg0) {
    arg0->unkD000 = (f32) (-0x1.0000000000000p+0f / fparg0);
}
