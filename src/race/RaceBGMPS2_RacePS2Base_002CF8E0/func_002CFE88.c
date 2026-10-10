#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002CFE40();                                /* extern */

struct func_002CFE88_arg0 {
    char pad0[0x1BC];
    f32 unk1BC;
    f32 unk1C0;
};

f32 func_002CFE88(struct func_002CFE88_arg0 *arg0) {
    if (func_002CFE40() != 0) {
        return arg0->unk1BC * arg0->unk1C0;
    }
    return 0.0f;
}
