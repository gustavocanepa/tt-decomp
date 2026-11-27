#include "types.h"

struct G { f32 m0, m4, m8; };
extern G D_00794E70;

extern "C" void RaceCarSound__fadeMasterVolume(f32 x, f32 y) {
    G *g = &D_00794E70;
    f32 base = g->m0;
    g->m8 = x;
    g->m4 = (x - base) / 0x1.e00000p+5f / y;
}
