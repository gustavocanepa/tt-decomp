#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA840(s32);                         /* extern */
s32 func_004FA860(s32);                         /* extern */

struct func_004CDDF8_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0x4];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

void func_004CDDF8(struct func_004CDDF8_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    func_004FA860(arg0->unk20);
    temp_v1 = arg0->unk18;
    if (temp_v1 != 0) {
        temp_v0 = arg0->unk14 + 1;
        arg0->unk18 = (s32) (temp_v1 - 1);
        arg0->unk14 = temp_v0;
        if (temp_v0 == arg0->unkC) {
            arg0->unk14 = 0;
        }
    }
    func_004FA840(arg0->unk20);
    temp_v1_2 = arg0->unk1C;
    if (temp_v1_2 != -1) {
        func_004FA840(temp_v1_2);
    }
}
