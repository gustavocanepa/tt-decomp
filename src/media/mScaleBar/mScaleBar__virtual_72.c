#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001EBB88(void *, s32);                 /* extern */
s32 func_001EBBE8(void *, s32);                             /* extern */
s32 func_001EBCA0(void *, s32);                     /* extern */
s32 func_001EC1D8(void *, f32);                 /* extern */
s32 func_0020B998(void *, s32, void *);         /* extern */

struct mScaleBar__virtual_72_arg2 {
    char pad0[0x20];
    s32 unk20;
};
struct mScaleBar__virtual_72_arg0 {
    char pad0[0xDC];
    f32 unkDC;
};

void mScaleBar__virtual_72(struct mScaleBar__virtual_72_arg0 *arg0, s32 arg1, struct mScaleBar__virtual_72_arg2 *arg2) {
    s32 temp_s0;

    temp_s0 = arg2->unk20;
    if ((func_001EBBE8(arg0, temp_s0) != 0) || (func_001EBCA0(arg0, temp_s0) != 0)) {
        func_001EC1D8(arg0, arg0->unkDC);
        func_001EBB88(arg0, arg1);
    }
    func_0020B998(arg0, arg1, arg2);
}
