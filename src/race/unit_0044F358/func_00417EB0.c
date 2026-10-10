#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417EB0_arg0 {
    char pad0[0x200];
    f32 unk200;
};

void func_00417EB0(struct func_00417EB0_arg0 *arg0, f32 fparg0) {
    arg0->unk200 = fparg0;
}
