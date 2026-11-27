#include "types.h"

struct Obj {
    char pad[0x68];
    s32 unk68;
};

extern "C" f32 func_00562570(struct Obj *arg0) {
    return (f32)arg0->unk68 * 0.0078125f;
}
