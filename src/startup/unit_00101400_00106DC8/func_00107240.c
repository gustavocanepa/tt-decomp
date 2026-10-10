#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00107280();                            /* extern */
s32 func_004781B0(s32);                             /* extern */

struct func_00107240_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00107240(struct func_00107240_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    func_00107280();
    temp_v0 = func_004781B0(arg1);
    arg0->unk4 = arg1;
    arg0->unk0 = temp_v0;
}
