#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550C88_arg0 {
    char pad0[0x327BC];
    f32 unk327BC;
};

void func_00550C88(struct func_00550C88_arg0 *arg0, f32 fparg0) {
    arg0->unk327BC = fparg0;
}
