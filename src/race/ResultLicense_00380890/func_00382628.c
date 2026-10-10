#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_00382628_arg0 {
    char pad0[0x12];
    s16 unk12;
    char pad14[0xB];
    u8 unk1F;
};

f32 func_00382628(struct func_00382628_arg0 *arg0) {
    return (func_00381890(arg0->unk12, arg0->unk1F) / 0x1.6800000000000p+7f) * 0x1.921fb40000000p+1f;
}
