#include "types.h"

struct Obj {
    char pad[0x34];
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

extern "C" void func_001AB980(Obj *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    arg0->unk34 = fparg0;
    arg0->unk38 = fparg1;
    arg0->unk3C = fparg2;
}
