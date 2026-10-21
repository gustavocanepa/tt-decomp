#include "types.h"

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" f32 func_005625C0(struct Obj *arg0) {
    return (f32)arg0->unk70 * 0.0078125f;
}
