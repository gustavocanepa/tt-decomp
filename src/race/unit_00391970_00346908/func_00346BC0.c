#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004A5C50();                                /* extern */
f32 func_004A5D18(f32);                             /* extern */

struct func_00346BC0_arg0 {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
};

void func_00346BC0(struct func_00346BC0_arg0 *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;

    temp_f21 = arg0->unk0;
    temp_f22 = arg0->unk8;
    temp_f20 = func_004A5C50();
    temp_f0 = func_004A5D18(fparg0);
    arg0->unk0 = (f32) ((temp_f21 * temp_f20) - (temp_f22 * temp_f0));
    arg0->unk8 = (f32) ((temp_f21 * temp_f0) + (temp_f22 * temp_f20));
}
