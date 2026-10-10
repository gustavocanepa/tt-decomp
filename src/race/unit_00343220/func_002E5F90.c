#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5F90_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x388];
    f32 unk900;
    char pad904[0x18];
    f32 unk91C;
};

f32 func_002E5F90(struct func_002E5F90_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unk91C * temp_f12) + (arg0->unk900 * (0x1.0000000000000p+0f - temp_f12));
}
