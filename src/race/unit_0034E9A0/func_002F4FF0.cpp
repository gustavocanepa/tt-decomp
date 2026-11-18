#include "types.h"

struct Obj {
    char pad[0x1C];
    f32 unk1C;
};

extern "C" void func_002F4E60(Obj *arg0);

extern "C" f32 func_002F4FF0(Obj *arg0) {
    func_002F4E60(arg0);
    return arg0->unk1C;
}
