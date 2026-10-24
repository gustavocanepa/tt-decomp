#include "types.h"

struct Obj {
    char pad[0x38];
    f32 unk38;
    f32 unk3C;
};

extern "C" void func_00391E68(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk38 = fparg0;
    arg0->unk3C = fparg1;
}
