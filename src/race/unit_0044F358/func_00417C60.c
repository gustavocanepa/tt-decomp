#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C60_arg0 {
    char pad0[0x110];
    f32 unk110;
};

void func_00417C60(struct func_00417C60_arg0 *arg0, f32 fparg0) {
    arg0->unk110 = fparg0;
}
