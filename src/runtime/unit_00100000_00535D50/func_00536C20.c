#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00536C20_arg0 {
    char pad0[0xC8];
    f32 unkC8;
};

void func_00536C20(struct func_00536C20_arg0 *arg0, f32 fparg0) {
    arg0->unkC8 = fparg0;
}
