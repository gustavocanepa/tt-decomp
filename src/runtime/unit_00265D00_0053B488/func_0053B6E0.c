#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0053B6E0_arg0 {
    char pad0[0x1B8];
    f32 unk1B8;
};

void func_0053B6E0(struct func_0053B6E0_arg0 *arg0, f32 fparg0) {
    arg0->unk1B8 = fparg0;
}
