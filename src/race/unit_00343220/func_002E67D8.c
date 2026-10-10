#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E67D8_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x394];
    f32 unk90C;
    char pad910[0xEC];
    f32 unk9FC;
};

f32 func_002E67D8(struct func_002E67D8_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unk9FC * temp_f12) + (arg0->unk90C * (0x1.0000000000000p+0f - temp_f12));
}
