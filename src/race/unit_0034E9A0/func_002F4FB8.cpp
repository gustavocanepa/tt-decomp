#include "types.h"

struct Obj {
    char pad0[0x14];
    f32 unk14;
};

extern "C" void func_002F4E60(struct Obj *arg0);

extern "C" f32 func_002F4FB8(struct Obj *arg0) {
    struct Obj *s0 = arg0;
    func_002F4E60(s0);
    return s0->unk14 * 3.0f;
}
