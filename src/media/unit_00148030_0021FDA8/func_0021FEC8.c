#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00205DF0(s32, f32, f32);               /* extern */

struct func_0021FEC8_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    f32 unk50;
    f32 unk54;
};

s32 func_0021FEC8(struct func_0021FEC8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4C;
    if (temp_v0 != 0) {
        func_00205DF0(temp_v0, arg0->unk50, arg0->unk54);
    }
}
