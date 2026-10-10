#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C20_arg0 {
    char pad0[0x100];
    f32 unk100;
};

void func_00417C20(struct func_00417C20_arg0 *arg0, f32 fparg0) {
    arg0->unk100 = fparg0;
}
