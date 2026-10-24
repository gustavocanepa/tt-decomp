#include "types.h"

struct Obj {
    char pad[0x54];
    f32 unk4C;
    f32 unk50;
};

extern "C" void func_0013C938(Obj *arg0, f32 fparg0) {
    arg0->unk4C = fparg0;
    arg0->unk50 = fparg0;
}
