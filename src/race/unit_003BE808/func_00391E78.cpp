#include "types.h"

struct Obj {
    char pad[0x40];
    f32 unk40;
    f32 unk44;
};

extern "C" void func_00391E78(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk44 = fparg0;
    arg0->unk40 = fparg0 * fparg1;
}
