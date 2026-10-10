#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417C90_arg0 {
    char pad0[0x11C];
    f32 unk11C;
};

void func_00417C90(struct func_00417C90_arg0 *arg0, f32 fparg0) {
    arg0->unk11C = fparg0;
}
