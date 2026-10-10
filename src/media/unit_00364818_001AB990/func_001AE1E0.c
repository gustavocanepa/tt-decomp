#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AE1E0_arg0 {
    char pad0[0x14084];
    f32 unk14084;
    f32 unk14088;
    f32 unk1408C;
    f32 unk14090;
};

void func_001AE1E0(struct func_001AE1E0_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk14084 = fparg0;
    arg0->unk14088 = fparg1;
    arg0->unk1408C = fparg2;
    arg0->unk14090 = fparg3;
}
