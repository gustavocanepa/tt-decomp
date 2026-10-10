#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003D8FB8(s32, f32);                        /* extern */
s32 func_003D96A0();                                /* extern */

struct func_003D9AC0_arg0 {
    char pad0[0x50];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    char pad5C[0x4];
    f32 unk60;
    f32 unk64;
    f32 unk68;
};

void func_003D9AC0(struct func_003D9AC0_arg0 *arg0) {
    func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D96A0(), arg0->unk50), arg0->unk54), arg0->unk58), arg0->unk60), arg0->unk64), arg0->unk68);
}
