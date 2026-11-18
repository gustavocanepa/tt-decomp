#include "types.h"

struct Obj {
    char pad[0x1C];
    f32 unk1C;
};

extern "C" f32 func_00318728(Obj *arg0);

extern "C" void func_00318780(Obj *arg0) {
    arg0->unk1C = func_00318728(arg0);
}
