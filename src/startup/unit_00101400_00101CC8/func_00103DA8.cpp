#include "types.h"

struct func_00103DA8_arg0 {
    char pad0[0x48];
    f32 unk34;
    char pad1[0x14];
    f32 unk4C;
};

void func_00103930(void *, s32, f32);   /* extern */
s32 func_001098E0(void *, f32);         /* extern */

void func_00103DA8(struct func_00103DA8_arg0 *arg0, s32 arg1, f32 fparg0) {
    func_00103930(arg0, arg1, fparg0);
    if (arg0->unk34 >= 1.0f) {
        f32 *p = &arg0->unk4C;
        if (*p == 0.0f) {
            *p = 1.0f;
        }
    }
    func_001098E0(&arg0->unk4C, fparg0);
}
