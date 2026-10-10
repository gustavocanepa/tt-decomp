/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020DC50();                                /* extern */

struct func_00206998_arg0 {
    char pad0[0x5C];
    void *unk5C;
    char pad60[0x50];
    s32 unkB0;
};
struct func_00206998_temp_v0 {
    f32 unk0;
};
struct func_00206998_temp_v0_2 {
    char pad0[0x4];
    f32 unk4;
};

void func_00206998(struct func_00206998_arg0 *arg0, f32 fparg0, f32 fparg1) {
    struct func_00206998_temp_v0 *temp_v0;
    struct func_00206998_temp_v0_2 *temp_v0_2;

    if (func_0020DC50() != 0) {
        if (fparg0 >= 0x0.0p+0f) {
            temp_v0 = arg0->unk5C;
            if (temp_v0->unk0 != fparg0) {
                temp_v0->unk0 = fparg0;
                arg0->unkB0 = (s32) (arg0->unkB0 | 0x10);
            }
        }
        if (fparg1 >= 0x0.0p+0f) {
            temp_v0_2 = arg0->unk5C;
            if (temp_v0_2->unk4 != fparg1) {
                temp_v0_2->unk4 = fparg1;
                arg0->unkB0 = (s32) (arg0->unkB0 | 0x10);
            }
        }
    }
}
