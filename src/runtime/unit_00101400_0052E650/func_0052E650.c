#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0052E650_arg0 {
    char pad0[0x64];
    f32 unk64;
    f32 unk68;
};

void func_0052E650(struct func_0052E650_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk64 = fparg0;
    arg0->unk68 = fparg1;
}
