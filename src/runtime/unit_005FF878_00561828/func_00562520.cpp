#include "types.h"

struct Obj {
    char pad[0x60];
    s32 unk60;
};

extern "C" f32 func_00562520(struct Obj *arg0) {
    return (f32)arg0->unk60 * 0.0078125f;
}
