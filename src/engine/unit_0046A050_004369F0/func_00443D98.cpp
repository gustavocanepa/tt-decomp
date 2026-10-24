#include "types.h"

struct Obj0047D080 {
    s32 unk0;
    s32 unk4;
    char pad8[0x14];
    u8 unk1C;
    char pad1D[0xFF];
    s32 unk11C;
};

extern "C" void func_00443D98(struct Obj0047D080 *arg0, u32 arg1) {
    if (arg1 < 0x80U) {
        s32 t = (s32)arg1 + (s32)arg0;
        u8 *p = (u8 *)(t + 0x1C);
        *p = (u8)(*p | 5);
        arg0->unk11C = 1;
        arg0->unk0 = (s32)arg1;
        arg0->unk4 = 0;
    }
}
