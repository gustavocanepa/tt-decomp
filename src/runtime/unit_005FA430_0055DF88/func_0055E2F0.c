/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055E2F0_arg0 {
    char pad0[0x50];
    f32 unk50;
    f32 unk54;
};

void func_0055E2F0(struct func_0055E2F0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk50 = fparg0;
    arg0->unk54 = fparg1;
}
