#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004AFC98(s32, f32, f32);               /* extern */

struct func_004AFD08_arg0 {
    char pad0[0x8];
    f32 unk8;
};

void *func_004AFD08(struct func_004AFD08_arg0 *arg0, f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    temp_f0 = arg0->unk8 - fparg0;
    arg0->unk8 = temp_f0;
    arg0->unk8 = (f32) (func_004AFC98(1, temp_f0, fparg1 - fparg0) + fparg0);
    return arg0;
}
