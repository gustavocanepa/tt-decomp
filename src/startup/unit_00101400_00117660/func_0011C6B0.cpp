#include "types.h"

struct Obj {
    char pad[2];
    u8 unk2;
};

extern "C" f32 func_0011C6B0(struct Obj *arg0) {
    return (f32)arg0->unk2 / 255.0f;
}
