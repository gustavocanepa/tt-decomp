#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00211C00();                            /* extern */

extern char D_005BD4C0[];
struct mMotionEvent__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x18];
    f32 unk20;
    f32 unk24;
};

s32 mMotionEvent__structor_0(struct mMotionEvent__structor_0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    func_00211C00();
    arg0->unk24 = fparg1;
    arg0->unk20 = fparg0;
    arg0->unk4 = (s32)D_005BD4C0;
}
