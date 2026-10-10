#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020DC50();                                /* extern */

struct func_00206B18_arg0_unk5C {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
};
struct func_00206B18_arg0 {
    char pad0[0x5C];
    struct func_00206B18_arg0_unk5C *unk5C;
};

void func_00206B18(struct func_00206B18_arg0 *arg0, f32 fparg0, f32 fparg1) {
    if (func_0020DC50() != 0) {
        if (fparg0 >= 0x0.0p+0f) {
            arg0->unk5C->unk10 = fparg0;
        }
        if (fparg1 >= 0x0.0p+0f) {
            arg0->unk5C->unk14 = fparg1;
        }
    }
}
