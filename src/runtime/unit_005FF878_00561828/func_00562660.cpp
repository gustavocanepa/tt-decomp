#include "types.h"

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" f32 func_00562660(struct Obj *arg0) {
    return (f32)arg0->unk80 * 0.0078125f;
}
