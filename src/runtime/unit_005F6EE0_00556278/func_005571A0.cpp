#include "types.h"

struct Obj {
    char pad[0x1C];
    f32 unk1C;
};

extern "C" void func_005571A0(Obj *arg0, f32 arg1) {
    arg0->unk1C = arg1 * -90.0f;
}
