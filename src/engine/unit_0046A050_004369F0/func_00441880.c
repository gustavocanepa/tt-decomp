#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004447B0(s32);                             /* extern */

struct func_00441880_arg0 {
    s32 unk0;
    f32 unk4;
};

void *func_00441880(struct func_00441880_arg0 *arg0, s32 arg1) {
    f32 temp_f0;

    temp_f0 = func_004447B0(arg1);
    arg0->unk0 = 6;
    arg0->unk4 = temp_f0;
    return arg0;
}
