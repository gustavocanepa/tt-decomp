#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45F8(s32);                             /* extern */
s32 func_004F64C4(s32, s32, s32);               /* extern */

struct func_001074F8_arg0 {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

void func_001074F8(struct func_001074F8_arg0 *arg0) {
    s32 temp_s0;
    s32 temp_v0;

    if (arg0->unk10 == 0) {
        temp_s0 = arg0->unkC * 0x28;
        temp_v0 = func_004A45F8(temp_s0);
        func_004F64C4(temp_v0, arg0->unk8, temp_s0);
        arg0->unk8 = temp_v0;
        arg0->unk10 = 1;
    }
}
