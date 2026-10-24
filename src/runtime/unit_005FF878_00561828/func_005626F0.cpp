#include "types.h"

struct Obj {
    char pad[0x8C];
    s32 unk8C;
};

extern "C" f32 func_005626F0(struct Obj *arg0) {
    return (f32)arg0->unk8C * 0.0078125f;
}
