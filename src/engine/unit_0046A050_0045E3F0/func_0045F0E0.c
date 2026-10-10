#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F0E0_arg0 {
    char pad0[0x6C];
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
};

void func_0045F0E0(struct func_0045F0E0_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk6C = fparg0;
    arg0->unk70 = fparg1;
    arg0->unk74 = (f32) (fparg0 + fparg2);
    arg0->unk78 = (f32) (fparg1 + fparg3);
}
