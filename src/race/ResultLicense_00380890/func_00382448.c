#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s8, u8);                          /* extern */

struct func_00382448_arg0 {
    char pad0[0x4];
    s8 unk4;
    char pad5[0x12];
    u8 unk17;
};

f32 func_00382448(struct func_00382448_arg0 *arg0) {
    return func_00381890(arg0->unk4, arg0->unk17) * 0x1.47ae140000000p-7f;
}
