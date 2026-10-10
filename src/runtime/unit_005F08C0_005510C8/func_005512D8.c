#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005512D8_arg0 {
    char pad0[0xD004];
    f32 unkD004;
};

void func_005512D8(struct func_005512D8_arg0 *arg0, f32 fparg0) {
    arg0->unkD004 = (f32) (-0x1.0000000000000p+0f / fparg0);
}
