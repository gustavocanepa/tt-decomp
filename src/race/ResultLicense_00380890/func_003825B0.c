#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s16, u8);                         /* extern */

struct func_003825B0_arg0 {
    char pad0[0xE];
    s16 unkE;
    char pad10[0xD];
    u8 unk1D;
};

f32 func_003825B0(struct func_003825B0_arg0 *arg0) {
    return (func_00381890(arg0->unkE, arg0->unk1D) / 0x1.6800000000000p+7f) * 0x1.921fb40000000p+1f;
}
