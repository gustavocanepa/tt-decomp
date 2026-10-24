#include "types.h"

struct Obj {
    char pad[0x28];
    s32 unk68;
};

extern "C" void RaceMiniMap__virtual_07(Obj *arg0);

extern "C" void func_0035A058(Obj *arg0) {
    arg0->unk68 = 0;
    RaceMiniMap__virtual_07(arg0);
}
