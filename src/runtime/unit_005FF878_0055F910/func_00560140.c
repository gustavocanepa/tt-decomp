/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560140_arg0 {
    char pad0[0x60];
    f32 unk60;
    f32 unk64;
};

void func_00560140(struct func_00560140_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk60 = fparg0;
    arg0->unk64 = fparg1;
}
