#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_00382538_arg0 {
    char pad0[0xA];
    s16 unkA;
    char padC[0xF];
    u8 unk1B;
};

f32 func_00382538(struct func_00382538_arg0 *arg0) {
    return (func_00381890(arg0->unkA, arg0->unk1B) / 0x1.6800000000000p+7f) * 0x1.921fb40000000p+1f;
}
