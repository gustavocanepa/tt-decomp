#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003D8FB8(s32, f32);                        /* extern */

struct func_003D90C8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[0x4];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_003D90C8(struct func_003D90C8_arg0 *arg0, s32 arg1) {
    func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(func_003D8FB8(arg1, arg0->unk0), arg0->unk4), arg0->unk8), arg0->unk10), arg0->unk14), arg0->unk18), arg0->unk1C);
}
