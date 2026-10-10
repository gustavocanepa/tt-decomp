#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417DD0_arg0 {
    char pad0[0x170];
    f32 unk170;
};

void func_00417DD0(struct func_00417DD0_arg0 *arg0, f32 fparg0) {
    arg0->unk170 = fparg0;
}
