#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417CE0_arg0 {
    char pad0[0x130];
    f32 unk130;
};

void func_00417CE0(struct func_00417CE0_arg0 *arg0, f32 fparg0) {
    arg0->unk130 = fparg0;
}
