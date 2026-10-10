#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_003824A8_arg0 {
    char pad0[0x6];
    s16 unk6;
    char pad8[0x11];
    u8 unk19;
};

f32 func_003824A8(struct func_003824A8_arg0 *arg0) {
    return (func_00381890(arg0->unk6, arg0->unk19) / 0x1.6800000000000p+7f) * 0x1.921fb40000000p+1f;
}
