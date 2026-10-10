#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5F30_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x118];
    f32 unk690;
    char pad694[0x298];
    f32 unk92C;
};

f32 func_002E5F30(struct func_002E5F30_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unk92C * temp_f12) + (arg0->unk690 * (0x1.0000000000000p+0f - temp_f12));
}
