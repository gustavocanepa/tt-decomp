#include "types.h"
struct Blk { long w[8]; } __attribute__((aligned(8)));
struct G { float f0; char p4[0x10]; float f14; char p18[0x28]; };
extern G D_00583B68;

extern "C" void func_0031A9C0(char *arg0, float fa, float fb) {
    Blk *dst = (Blk *)(arg0 + 0xA80);
    if (fa < 1.0f) {
        D_00583B68.f0 = 1.0f;
        D_00583B68.f14 = fa;
    } else {
        D_00583B68.f14 = 1.0f;
        D_00583B68.f0 = 1.0f / fa;
    }
    *dst = *(Blk *)&D_00583B68;
    *(float *)((char *)dst + 0x40) = fb;
}
