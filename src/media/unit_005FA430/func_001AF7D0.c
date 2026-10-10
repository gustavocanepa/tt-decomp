#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AF7D0_arg0 {
    char pad0[0x14284];
    s32 unk14284;
    f32 unk14288;
    f32 unk1428C;
};

void func_001AF7D0(struct func_001AF7D0_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    arg0->unk14284 = arg1;
    arg0->unk14288 = fparg0;
    arg0->unk1428C = fparg1;
}
