#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005226C0_arg0 {
    char pad0[0x140A4];
    f32 unk140A4;
    f32 unk140A8;
    f32 unk140AC;
    f32 unk140B0;
};

void func_005226C0(struct func_005226C0_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk140A4 = fparg0;
    arg0->unk140A8 = fparg1;
    arg0->unk140AC = fparg2;
    arg0->unk140B0 = fparg3;
}
