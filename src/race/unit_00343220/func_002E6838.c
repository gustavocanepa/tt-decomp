#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6838_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x1A8];
    f32 unk720;
    char pad724[0x2E4];
    f32 unkA08;
};

f32 func_002E6838(struct func_002E6838_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unkA08 * temp_f12) + (arg0->unk720 * (0x1.0000000000000p+0f - temp_f12));
}
