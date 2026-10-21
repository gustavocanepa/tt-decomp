#include "types.h"

struct Obj {
    char pad[0x40];
    s8 unk40;
    s8 unk41;
};

extern "C" void func_004367E8(Obj *arg0) {
    arg0->unk41 = 0;
    arg0->unk40 = -1;
}
