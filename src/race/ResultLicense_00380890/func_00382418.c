#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00381890(s8, u8);                          /* extern */

struct func_00382418_arg0 {
    char pad0[0x3];
    s8 unk3;
    char pad4[0x12];
    u8 unk16;
};

f32 func_00382418(struct func_00382418_arg0 *arg0) {
    return func_00381890(arg0->unk3, arg0->unk16) * 0x1.47ae140000000p-7f;
}
