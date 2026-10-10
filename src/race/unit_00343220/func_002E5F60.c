#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5F60_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x11C];
    f32 unk694;
    char pad698[0x298];
    f32 unk930;
};

f32 func_002E5F60(struct func_002E5F60_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unk930 * temp_f12) + (arg0->unk694 * (0x1.0000000000000p+0f - temp_f12));
}
