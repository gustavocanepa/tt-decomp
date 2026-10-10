#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00541820_arg0 {
    char pad0[0x128];
    f32 unk128;
};

void func_00541820(struct func_00541820_arg0 *arg0, f32 fparg0) {
    arg0->unk128 = fparg0;
}
