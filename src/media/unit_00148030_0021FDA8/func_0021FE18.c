#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00205C50(s32);                             /* extern */
f32 func_00205CB0(s32);                             /* extern */

struct func_0021FE18_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    f32 unk50;
    f32 unk54;
    char pad58[0x10];
    s32 unk68;
};

void func_0021FE18(struct func_0021FE18_arg0 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f20;

    arg0->unk4C = arg1;
    if (arg1 != 0) {
        temp_f20 = func_00205C50(arg1);
        temp_f0 = func_00205CB0(arg0->unk4C);
        arg0->unk50 = temp_f20;
        arg0->unk54 = temp_f0;
        arg0->unk68 = 0;
    }
}
