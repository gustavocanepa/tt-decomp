#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct MTRGeometry__virtual_07_p {
    char pad0[0x4];
    s32 unk4;
};

f32 MTRGeometry__virtual_07(struct MTRGeometry__virtual_07_p *p, s32 s) {
    f32 r;
    if (p->unk4 == 0) {
        r = -0x1.22D0E4p-4f;
        if (s) r = 0x1.22D0E4p-4f;
    } else {
        r = -0x1.395810p-3f;
        if (s) r = 0x1.395810p-3f;
    }
    return r;

}
