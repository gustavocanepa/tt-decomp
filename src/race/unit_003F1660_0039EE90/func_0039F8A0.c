#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0039F8A0_p {
    char pad0[0x10];
    s8 *unk10;
};

f32 func_0039F8A0(struct func_0039F8A0_p *p, f32 x) {
    s8 *s = p->unk10;
    f32 lo = *(f32 *)(s + 0x10C4);
    f32 hi = *(f32 *)(s + 0x10C8);
    if (x <= lo) return 0.0f;
    if (hi <= x) return 1.0f;
    return (x - lo) / (hi - lo);
}
