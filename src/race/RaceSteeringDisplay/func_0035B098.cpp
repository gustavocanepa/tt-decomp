#include "types.h"

struct Obj {
    char pad[0x20];
    f32 unk20;
};

extern f32 D_005F5664;

extern "C" void func_0035B098(Obj *arg0) {
    arg0->unk20 = D_005F5664;
}
