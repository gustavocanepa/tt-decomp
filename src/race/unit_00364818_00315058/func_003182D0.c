#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003182D0_arg0 {
    char pad0[0x4];
    f32 unk4;
};

void func_003182D0(struct func_003182D0_arg0 *arg0, f32 fparg0) {
    arg0->unk4 = fparg0;
}
