#include "types.h"

struct Obj {
    char pad[0x3C];
    s32 unk3C;
    s32 unk40;
};

extern "C" char D_005D6E60[];

extern "C" void func_003ABB98(Obj *arg0) {
    arg0->unk40 = (s32)D_005D6E60;
    arg0->unk3C = arg0->unk3C & 0xFFFF00FF;
}
