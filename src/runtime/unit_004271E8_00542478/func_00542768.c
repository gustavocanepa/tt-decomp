#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542768_arg0 {
    char pad0[0x64];
    f32 unk64;
};

void func_00542768(struct func_00542768_arg0 *arg0, f32 fparg0) {
    arg0->unk64 = fparg0;
}
