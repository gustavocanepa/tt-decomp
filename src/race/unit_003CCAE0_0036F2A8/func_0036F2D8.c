#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0036F2D8_arg1 {
    char pad0[0xC];
    f32 unkC;
};

void func_0036F2D8(f32 *arg0, struct func_0036F2D8_arg1 *arg1) {
    *arg0 = arg1->unkC;
}
