#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00540AD0_arg0 {
    char pad0[0xC];
    f32 unkC;
};

void func_00540AD0(struct func_00540AD0_arg0 *arg0, f32 fparg0) {
    arg0->unkC = fparg0;
}
