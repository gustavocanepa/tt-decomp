#include "types.h"

struct Obj {
    char pad[0x18];
    f32 unk18;
    char pad2[0x84 - 0x18 - 4];
    f32 unk84;
};

extern "C" f32 func_00322068(Obj *arg0, f32 fparg0) {
    f32 a = arg0->unk18;
    return a + (arg0->unk84 - a) * fparg0;
}
