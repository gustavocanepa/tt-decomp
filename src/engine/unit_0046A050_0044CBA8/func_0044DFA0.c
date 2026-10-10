/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0044E9D8(s32, f32, f32, f32);          /* extern */
f32 func_004A5B78(f32, f32);                        /* extern */
f32 func_004EE530(f32);                             /* extern */

struct func_0044DFA0_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    char padC[0xC];
    f32 unk18;
    char pad1C[0xC];
    f32 unk28;
};

void func_0044DFA0(s32 arg0, struct func_0044DFA0_arg1 *arg1) {
    f32 temp_f20;
    f32 temp_f21;

    temp_f21 = func_004A5B78(arg1->unk18, arg1->unk28);
    temp_f20 = func_004EE530(-arg1->unk8);
    func_0044E9D8(arg0, temp_f21, temp_f20, func_004A5B78(arg1->unk4, arg1->unk0));
}
