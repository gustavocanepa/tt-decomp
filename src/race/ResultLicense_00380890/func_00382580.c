#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_00382580_arg0 {
    char pad0[0xC];
    s16 unkC;
    char padE[0xE];
    u8 unk1C;
};

f32 func_00382580(struct func_00382580_arg0 *arg0) {
    return func_00381890(arg0->unkC, arg0->unk1C) * 0x1.47ae140000000p-7f;
}
