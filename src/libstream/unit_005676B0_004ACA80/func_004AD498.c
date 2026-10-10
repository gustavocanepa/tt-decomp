#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F6574(s32, s32, s32);               /* extern */

struct func_004AD498_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
};

void func_004AD498(struct func_004AD498_arg0 *arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_2;

    temp_a0 = arg0->unk4C;
    temp_a0_2 = temp_a0 + 8;
    arg0->unk4C = temp_a0_2;
    func_004F6574(temp_a0_2, temp_a0, ((s32) (arg1 - temp_a0) >> 3) * 8);
    arg0->unk50 = (s32) (arg0->unk50 - 1);
}
