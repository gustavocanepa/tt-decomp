#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5EA0_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x380];
    f32 unk8F8;
    char pad8FC[0x18];
    f32 unk914;
};

f32 func_002E5EA0(struct func_002E5EA0_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unk914 * temp_f12) + (arg0->unk8F8 * (0x1.0000000000000p+0f - temp_f12));
}
