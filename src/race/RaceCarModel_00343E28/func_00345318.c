#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00345318_arg0 {
    char pad0[0x3568];
    f32 unk3568;
    f32 unk356C;
    f32 unk3570;
};

f32 func_00345318(struct func_00345318_arg0 *arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 0:
        return arg0->unk3568;
    case 1:
        return arg0->unk356C;
    case 2:
        return arg0->unk3570;
    default:
        return 0x0.0p+0f;
    }
}
