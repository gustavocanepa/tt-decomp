#include "types.h"

struct Obj {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
};

extern "C" void func_002F8670(Obj *arg0) {
    arg0->unk1 = 0;
    arg0->unk0 = 0;
    arg0->unk2 = -0x80;
    arg0->unk3 = 0;
}
