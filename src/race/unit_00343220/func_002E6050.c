#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6050_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x124];
    f32 unk69C;
    char pad6A0[0x298];
    f32 unk938;
};

f32 func_002E6050(struct func_002E6050_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unk938 * temp_f12) + (arg0->unk69C * (0x1.0000000000000p+0f - temp_f12));
}
