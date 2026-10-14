#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern f32 D_005F57D0;
struct func_0035E878_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
};

void func_0035E878(struct func_0035E878_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk10 = (fparg0 == 0x0.0p+0f) ? D_005F57D0 : (0x1.0000000000000p+0f / fparg0);
    arg0->unk14 = (fparg1 == 0x0.0p+0f) ? D_005F57D0 : (0x1.0000000000000p+0f / fparg1);
}
