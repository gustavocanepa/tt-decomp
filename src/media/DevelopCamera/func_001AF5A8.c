#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AF5A8_arg0 {
    char pad0[0x140D0];
    f32 unk140D0;
    f32 unk140D4;
    f32 unk140D8;
    f32 unk140DC;
};

void func_001AF5A8(struct func_001AF5A8_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk140D0 = fparg0;
    arg0->unk140D4 = fparg1;
    arg0->unk140D8 = fparg2;
    arg0->unk140DC = fparg3;
}
