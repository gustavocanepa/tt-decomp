#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0041F9C8();                                /* extern */

struct func_0055A8B8_arg0 {
    char pad0[0x15];
    u8 unk15;
};

void func_0055A8B8(struct func_0055A8B8_arg0 *arg0, s32 arg1, s32 (*arg2)(s32, s32)) {
    if (!(arg0->unk15 & 1 & 0xFF)) {
        arg2(arg1, func_0041F9C8());
    }
}
