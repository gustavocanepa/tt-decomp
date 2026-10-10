#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5E70_arg0 {
    char pad0[0x574];
    f32 unk574;
    char pad578[0x50];
    f32 unk5C8;
    char pad5CC[0x440];
    f32 unkA0C;
};

f32 func_002E5E70(struct func_002E5E70_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 + arg0->unk574;
    return (arg0->unkA0C * temp_f12) + (arg0->unk5C8 * (0x1.0000000000000p+0f - temp_f12));
}
