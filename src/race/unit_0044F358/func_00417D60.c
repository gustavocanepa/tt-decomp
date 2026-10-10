#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D60_arg0 {
    char pad0[0x150];
    f32 unk150;
};

void func_00417D60(struct func_00417D60_arg0 *arg0, f32 fparg0) {
    arg0->unk150 = fparg0;
}
