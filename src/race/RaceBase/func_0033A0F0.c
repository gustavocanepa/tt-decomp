#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0036C908(s32, s32, s32, s32); /* extern */

struct func_0033A0F0_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    char pad70[0xDAC];
    s32 unkE1C;
};

s32 func_0033A0F0(struct func_0033A0F0_arg0 *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = arg0->unkE1C;
    temp_v1 = temp_v0 - 1;
    if (temp_v0 > 0) {
        arg0->unkE1C = temp_v1;
        if (temp_v1 == 1) {
            func_0036C908(arg0->unk6C + 0xF4, 1, 0, 0);
        }
    }
}
