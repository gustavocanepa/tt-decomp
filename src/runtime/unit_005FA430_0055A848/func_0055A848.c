#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0041F9C8();                                /* extern */
s32 func_0041FA80(void *, s32);                     /* extern */

struct func_0055A848_arg0 {
    char pad0[0x15];
    u8 unk15;
    char pad16[0x66];
    s32 unk7C;
};

s32 func_0055A848(struct func_0055A848_arg0 *arg0, s32 (*arg1)(s32)) {
    if (arg0->unk15 & 1 & 0xFF) {
        return arg0->unk7C;
    }
    return func_0041FA80(arg0, arg1(func_0041F9C8()));
}
