#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s8, u8);                          /* extern */

struct func_00382478_arg0 {
    char pad0[0x5];
    s8 unk5;
    char pad6[0x12];
    u8 unk18;
};

f32 func_00382478(struct func_00382478_arg0 *arg0) {
    return func_00381890(arg0->unk5, arg0->unk18) * 0x1.47ae140000000p-7f;
}
