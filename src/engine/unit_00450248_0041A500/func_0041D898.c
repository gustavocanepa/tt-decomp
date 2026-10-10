#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0041D898_p {
    char pad0[0x4];
    s8 *unk4;
};

s32 func_0041D898(struct func_0041D898_p *p, f32 x) {
    s8 *s = p->unk4;
    s32 v = *(s32 *)(s + 0xA4);
    if (v >= 0) return v;
    if (*(f32 *)(s + 0xA8) < x) return 0;
    if (*(f32 *)(s + 0xA8) * 0x1.51EB84p-2f < x) return 1;
    return 2;
}
